#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2000

// XOA 0 O DAU
void xoaSo0Dau(char *s) {
    int i = 0;
    while (s[i] == '0' && s[i+1] != '\0') i++;
    if (i > 0) memmove(s, s+i, strlen(s)-i+1);
}

// XOA 0 O CUOI (PHAN THAP PHAN)
void xoaSo0Cuoi(char *s) {
    int len = strlen(s);
    while (len > 1 && s[len-1] == '0') {
        s[len-1] = '\0';
        len--;
    }
}

// Tach so thanh: nguyen, thap phan, dau
void tachSo(char *num, char *nguyen, char *thapPhan, int *am) {
    *am = (num[0] == '-');

    char *p = num + (*am ? 1 : 0);
    char *dot = strchr(p, '.');

    if (dot) {
        strncpy(nguyen, p, dot - p);
        nguyen[dot - p] = '\0';
        strcpy(thapPhan, dot + 1);
    } else {
        strcpy(nguyen, p);
        strcpy(thapPhan, "0");
    }

    xoaSo0Dau(nguyen);
    xoaSo0Cuoi(thapPhan);
}

// So sanh tri tuyet doi
int soSanhAbs(char *aInt, char *aFrac, char *bInt, char *bFrac) {
    if (strlen(aInt) != strlen(bInt))
        return strlen(aInt) > strlen(bInt) ? 1 : -1;

    int cmp = strcmp(aInt, bInt);
    if (cmp != 0)
        return cmp > 0 ? 1 : -1;

    int la = strlen(aFrac), lb = strlen(bFrac);
    int L = (la > lb ? la : lb);

    for (int i = 0; i < L; i++) {
        char ca = (i < la ? aFrac[i] : '0');
        char cb = (i < lb ? bFrac[i] : '0');
        if (ca != cb) return (ca > cb) ? 1 : -1;
    }
    return 0;
}

// cong tri tuyet doi
void congAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
             char *resInt, char *resFrac)
{
    int la = strlen(aFrac);
    int lb = strlen(bFrac);
    int L = (la > lb ? la : lb);

    char A[MAX], B[MAX];
    strcpy(A, aFrac);
    strcpy(B, bFrac);

    while (strlen(A) < L) strcat(A, "0");
    while (strlen(B) < L) strcat(B, "0");

    int carry = 0;
    resFrac[L] = '\0';

    for (int i = L-1; i >= 0; i--) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        resFrac[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // cong phan nguyen
    int ia = strlen(aInt), ib = strlen(bInt);
    int imax = (ia > ib ? ia : ib);

    resInt[imax] = '\0';
    int k = imax - 1;
    ia--; ib--;

    while (imax--) {
        int da = (ia >= 0 ? aInt[ia--] - '0' : 0);
        int db = (ib >= 0 ? bInt[ib--] - '0' : 0);
        int sum = da + db + carry;

        resInt[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        memmove(resInt + 1, resInt, strlen(resInt) + 1);
        resInt[0] = '1';
    }

    xoaSo0Cuoi(resFrac);
    xoaSo0Dau(resInt);
}

// tru tri tuyet doi (a ≥ b)
void truAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
            char *resInt, char *resFrac)
{
    int la = strlen(aFrac), lb = strlen(bFrac);
    int L = (la > lb ? la : lb);

    char A[MAX], B[MAX];
    strcpy(A, aFrac);
    strcpy(B, bFrac);

    while (strlen(A) < L) strcat(A, "0");
    while (strlen(B) < L) strcat(B, "0");

    int borrow = 0;
    resFrac[L] = '\0';

    for (int i = L-1; i >= 0; i--) {
        int da = (A[i] - '0') - borrow;
        int db = (B[i] - '0');

        if (da < db) {
            da += 10;
            borrow = 1;
        } else borrow = 0;

        resFrac[i] = (da - db) + '0';
    }

    // tru phan nguyen
    int ia = strlen(aInt);
    int ib = strlen(bInt);

    resInt[ia] = '\0';
    int k = ia - 1;
    ia--; ib--;

    while (k >= 0) {
        int da = aInt[ia] - '0';
        int db = (ib >= 0 ? bInt[ib] - '0' : 0);
        da -= borrow;

        if (da < db) {
            da += 10;
            borrow = 1;
        } else borrow = 0;

        resInt[k] = (da - db) + '0';

        ia--; ib--;
        k--;
    }

    xoaSo0Cuoi(resFrac);
    xoaSo0Dau(resInt);
}


// ====================== MAIN ========================
int main() {
    char A[MAX], B[MAX];
    char aInt[MAX], aFrac[MAX], bInt[MAX], bFrac[MAX];
    char rAddInt[MAX], rAddFrac[MAX];
    char rSubInt[MAX], rSubFrac[MAX];
    int signA, signB;

    printf("Nhap so thu nhat: ");
    scanf("%s", A);
    printf("Nhap so thu hai: ");
    scanf("%s", B);

    tachSo(A, aInt, aFrac, &signA);
    tachSo(B, bInt, bFrac, &signB);

    // ----------------- PHEP CONG -----------------
    printf("\n--- PHEP CONG ---\n");

    if (signA == signB) {
        // CUNG DAU -> CONG
        congAbs(aInt, aFrac, bInt, bFrac, rAddInt, rAddFrac);
        if (strcmp(rAddInt, "0") == 0 && strcmp(rAddFrac, "0") == 0)
            printf("0\n");
        else {
            if (signA) printf("-");
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        }
    } else {
        // KHAC DAU -> TRU
        int cmp = soSanhAbs(aInt, aFrac, bInt, bFrac);

        if (cmp == 0) {
            printf("0\n");
        } else if (cmp > 0) {
            // |A| > |B| ⇒ KET QUA CUNG VOI A
            if (signA) printf("-");
            truAbs(aInt, aFrac, bInt, bFrac, rAddInt, rAddFrac);
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        } else {
            // |B| > |A| ⇒ KET QUA CUNG VOI B
            if (signB) printf("-");
            truAbs(bInt, bFrac, aInt, aFrac, rAddInt, rAddFrac);
            printf("%s", rAddInt);
            if (strlen(rAddFrac) > 0) printf(".%s", rAddFrac);
            printf("\n");
        }
    }

    // ----------------- PHEP TRU -----------------
    printf("\n--- PHEP TRU A - B ---\n");

    // A - B = A + (-B)
    int newSignB = !signB;  // dao dau B

    if (signA == newSignB) {
        congAbs(aInt, aFrac, bInt, bFrac, rSubInt, rSubFrac);

        if (strcmp(rSubInt, "0") == 0 && strcmp(rSubFrac, "0") == 0)
            printf("0\n");
        else {
            if (signA) printf("-");
            printf("%s", rSubInt);
            if (strlen(rSubFrac) > 0) printf(".%s", rSubFrac);
            printf("\n");
        }
    } else {
        int cmp = soSanhAbs(aInt, aFrac, bInt, bFrac);

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
