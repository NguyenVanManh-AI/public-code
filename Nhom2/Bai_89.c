#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2000

/* Ham xoa cac so 0 o dau chuoi (de tranh truong hop 0012) */
void xoaSo0Dau(char *s) {
    int i = 0;
    while (s[i] == '0' && s[i+1] != '\0') i++;  // dem so luong 0 o dau
    if (i > 0) memmove(s, s+i, strlen(s)-i+1);  // dich chuoi de xoa 0 o dau
}

/* Ham xoa cac so 0 o cuoi phan thap phan (de 1.2300 thanh 1.23) */
void xoaSo0Cuoi(char *s) {
    int len = strlen(s);  // lay do dai chuoi
    while (len > 1 && s[len-1] == '0') {  // lap den khi khong con 0 o cuoi
        s[len-1] = '\0';  // cat ky tu 0 cuoi
        len--;
    }
}

/* Ham tach so thanh phan nguyen, phan thap phan, va dau am/duong */
void tachSo(char *num, char *nguyen, char *thapPhan, int *am) {
    char *p, *dot;
    *am = (num[0] == '-');  // kiem tra dau am

    p = num + (*am ? 1 : 0);  // bo dau tru neu co
    dot = strchr(p, '.');     // tim dau cham

    if (dot) {
        strncpy(nguyen, p, dot - p);  // copy phan nguyen
        nguyen[dot - p] = '\0';
        strcpy(thapPhan, dot + 1);   // copy phan thap phan
    } else {
        strcpy(nguyen, p);           // khong co cham -> toan nguyen
        strcpy(thapPhan, "0");       // phan thap phan mac dinh 0
    }

    xoaSo0Dau(nguyen);   // xoa 0 o dau phan nguyen
    xoaSo0Cuoi(thapPhan); // xoa 0 o cuoi phan thap phan
}

/* Ham so sanh tri tuyet doi cua 2 so duoi dang chuoi (phan nguyen + thap phan) */
int soSanhAbs(char *aInt, char *aFrac, char *bInt, char *bFrac) {
    int i, la, lb, L;
    char ca, cb;

    if (strlen(aInt) != strlen(bInt))
        return strlen(aInt) > strlen(bInt) ? 1 : -1; // so sanh do dai phan nguyen

    int cmp = strcmp(aInt, bInt);
    if (cmp != 0)
        return cmp > 0 ? 1 : -1;  // so sanh phan nguyen theo chuoi

    la = strlen(aFrac);
    lb = strlen(bFrac);
    L = (la > lb ? la : lb); // lay do dai phan thap phan lon nhat

    for (i = 0; i < L; i++) {
        ca = (i < la ? aFrac[i] : '0');  // lay ky tu phan thap phan, padding = 0
        cb = (i < lb ? bFrac[i] : '0');
        if (ca != cb) return (ca > cb) ? 1 : -1;  // tra ket qua ngay khi khac nhau
    }
    return 0; // bang nhau
}

/* Ham cong tri tuyet doi 2 so (phan nguyen + thap phan) */
void congAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
             char *resInt, char *resFrac)
{
    int la, lb, L, i, ia, ib, imax, k, sum, carry;
    char A[MAX], B[MAX];

    la = strlen(aFrac);
    lb = strlen(bFrac);
    L = (la > lb ? la : lb);  // chuan hoa do dai phan thap phan

    strcpy(A, aFrac);
    strcpy(B, bFrac);

    while (strlen(A) < L) strcat(A, "0"); // padding 0 phan thap phan
    while (strlen(B) < L) strcat(B, "0");

    carry = 0;
    resFrac[L] = '\0'; // ket thuc chuoi ket qua phan thap phan

    for (i = L-1; i >= 0; i--) {  // cong phan thap phan tu cuoi len dau
        sum = (A[i] - '0') + (B[i] - '0') + carry;
        resFrac[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Cong phan nguyen
    ia = strlen(aInt);
    ib = strlen(bInt);
    imax = (ia > ib ? ia : ib);

    resInt[imax] = '\0';  // ket thuc chuoi ket qua phan nguyen
    k = imax - 1;
    ia--; ib--;

    while (imax--) {  // cong tung chu so phan nguyen
        int da = (ia >= 0 ? aInt[ia--] - '0' : 0);
        int db = (ib >= 0 ? bInt[ib--] - '0' : 0);
        sum = da + db + carry;

        resInt[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {  // neu con carry -> dich chuoi de them '1' vao dau
        memmove(resInt + 1, resInt, strlen(resInt) + 1);
        resInt[0] = '1';
    }

    xoaSo0Cuoi(resFrac); // loai bo 0 thua phan thap phan
    xoaSo0Dau(resInt);   // loai bo 0 thua phan nguyen
}

/* Ham tru tri tuyet doi 2 so (a >= b) */
void truAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
            char *resInt, char *resFrac)
{
    int la, lb, L, i, ia, ib, k, da, db, borrow;
    char A[MAX], B[MAX];

    la = strlen(aFrac);
    lb = strlen(bFrac);
    L = (la > lb ? la : lb); // chuan hoa do dai phan thap phan

    strcpy(A, aFrac);
    strcpy(B, bFrac);

    while (strlen(A) < L) strcat(A, "0");
    while (strlen(B) < L) strcat(B, "0");

    borrow = 0;
    resFrac[L] = '\0'; // ket thuc phan thap phan

    for (i = L-1; i >= 0; i--) { // tru phan thap phan tu cuoi len dau
        da = (A[i] - '0') - borrow;
        db = (B[i] - '0');

        if (da < db) {
            da += 10;
            borrow = 1;  // muon tu phan thap phan lon hon
        } else borrow = 0;

        resFrac[i] = (da - db) + '0';
    }

    // Tru phan nguyen
    ia = strlen(aInt);
    ib = strlen(bInt);

    resInt[ia] = '\0';
    k = ia - 1;
    ia--; ib--;

    while (k >= 0) {
        da = aInt[ia] - '0';
        db = (ib >= 0 ? bInt[ib] - '0' : 0);
        da -= borrow;

        if (da < db) {
            da += 10;
            borrow = 1;
        } else borrow = 0;

        resInt[k] = (da - db) + '0';

        ia--; ib--;
        k--;
    }

    xoaSo0Cuoi(resFrac); // loai bo 0 thua phan thap phan
    xoaSo0Dau(resInt);   // loai bo 0 thua phan nguyen
}

int main() {
    char A[MAX], B[MAX]; // luu so nhap vao
    char aInt[MAX], aFrac[MAX], bInt[MAX], bFrac[MAX]; // luu phan nguyen + thap phan
    char rAddInt[MAX], rAddFrac[MAX]; // ket qua cong
    char rSubInt[MAX], rSubFrac[MAX]; // ket qua tru
    int signA, signB; // dau am/duong
    int cmp, newSignB; // bien trung gian

    printf("Nhap so thu nhat: ");
    scanf("%s", A); // nhap so A
    printf("Nhap so thu hai: ");
    scanf("%s", B); // nhap so B

    tachSo(A, aInt, aFrac, &signA); // tach so A
    tachSo(B, bInt, bFrac, &signB); // tach so B

    // ----------------- PHEP CONG -----------------
    printf("\n--- PHEP CONG A + B ---\n");

    if (signA == signB) { // cung dau -> cong
        congAbs(aInt, aFrac, bInt, bFrac, rAddInt, rAddFrac);
        if (strcmp(rAddInt, "0") == 0 && strcmp(rAddFrac, "0") == 0)
            printf("0\n");
        else {
            if (signA) printf("-"); // in dau am neu can
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        }
    } else { // khac dau -> tru
        cmp = soSanhAbs(aInt, aFrac, bInt, bFrac);

        if (cmp == 0) {
            printf("0\n");
        } else if (cmp > 0) { // |A| > |B|
            if (signA) printf("-");
            truAbs(aInt, aFrac, bInt, bFrac, rAddInt, rAddFrac);
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        } else { // |B| > |A|
            if (signB) printf("-");
            truAbs(bInt, bFrac, aInt, aFrac, rAddInt, rAddFrac);
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        }
    }

    // ----------------- PHEP TRU -----------------
    printf("\n--- PHEP TRU A - B ---\n");

    newSignB = !signB;  // dao dau B de tinh A - B = A + (-B)

    if (signA == newSignB) { // cung dau -> cong
        congAbs(aInt, aFrac, bInt, bFrac, rSubInt, rSubFrac);

        if (strcmp(rSubInt, "0") == 0 && strcmp(rSubFrac, "0") == 0)
            printf("0\n");
        else {
            if (signA) printf("-");
            printf("%s", rSubInt);
            if (strlen(rSubFrac) > 0) printf(".%s", rSubFrac);
            printf("\n");
        }
    } else { // khac dau -> tru
        cmp = soSanhAbs(aInt, aFrac, bInt, bFrac);

        if (cmp == 0) {
            printf("0\n");
        } else if (cmp > 0) {
            if (signA) printf("-");
            truAbs(aInt, aFrac, bInt, bFrac, rSubInt, rSubFrac);
            printf("%s", rSubInt);
            if (strlen(rSubFrac) > 0) printf(".%s", rSubFrac);
            printf("\n");
        } else {
            if (newSignB) printf("-");
            truAbs(bInt, bFrac, aInt, aFrac, rSubInt, rSubFrac);
            printf("%s", rSubInt);
            if (strlen(rSubFrac) > 0) printf(".%s", rSubFrac);
            printf("\n");
        }
    }

    return 0;
}
/* 
    1. Nhap 2 so dang chuoi tu ban phim (co the am, duong, co phan thap phan).
    2. Tach tung so thanh:
        - phan nguyen (aInt, bInt)
        - phan thap phan (aFrac, bFrac)
        - dau am/duong (signA, signB)
    3. Xoa cac so 0 thua o dau phan nguyen va cuoi phan thap phan.
    4. PHEP CONG A + B:
        - Neu cung dau (cung am hoac cung duong) -> congAbs:
            + Cong phan thap phan tu cuoi len dau
            + Cong phan nguyen tu cuoi len dau, quan ly carry
            + Xoa so 0 thua o dau va cuoi
            + In ket qua, in dau am neu can
        - Neu khac dau -> truAbs theo tri tuyet doi:
            + So sanh tri tuyet doi cua A va B
            + Tru so lon hon tru so nho hon
            + In ket qua voi dau cua so lon hon
    5. PHEP TRU A - B:
        - Dao dau B (newSignB = !signB)
        - Su dung cung logic nhu phep cong:
            + Neu cung dau -> congAbs
            + Neu khac dau -> truAbs theo tri tuyet doi
            + In ket qua voi dau phu hop
    6. Ham phu tro chinh:
        - xoaSo0Dau: loai bo 0 dau chuoi
        - xoaSo0Cuoi: loai bo 0 cuoi phan thap phan
        - tachSo: tach so thanh phan nguyen, phan thap phan, dau am/duong
        - soSanhAbs: so sanh tri tuyet doi 2 so
        - congAbs: cong tri tuyet doi 2 so
        - truAbs: tru tri tuyet doi 2 so (a >= b)
    
    LUU Y:
    - Xu ly ca so am, duong, so 0, so co phan thap phan
    - Padding '0' phan thap phan khi cong/tru
    - Carry va borrow duoc quan ly cho ca phan thap phan va nguyen
    - Ket qua in ra tu phan nguyen + thap phan, in dau am neu can
*/
