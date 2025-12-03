#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2000

// Xoa cac so 0 o dau
void xoaSo0Dau(char *s) {
    int i = 0;
    while (s[i] == '0' && s[i+1] != '\0') i++;
    if (i > 0) memmove(s, s+i, strlen(s)-i+1);
}

// Xoa cac so 0 o cuoi
void xoaSo0Cuoi(char *s) {
    int len = strlen(s);
    while (len > 1 && s[len-1] == '0') {
        s[len-1] = '\0';
        len--;
    }
}

// Tach so thanh phan nguyen va phan thap phan
void tachSo(char *num, char *nguyen, char *thapPhan, int *am) {
    *am = (num[0] == '-');

    char *p = num + (*am ? 1 : 0);
    char *dot = strchr(p, '.');

    if (dot) {
        strcpy(nguyen, "");
        strncat(nguyen, p, dot - p);
        strcpy(thapPhan, dot + 1);
    } else {
        strcpy(nguyen, p);
        strcpy(thapPhan, "0");
    }

    xoaSo0Dau(nguyen);
    xoaSo0Cuoi(thapPhan);
}

// So sanh tri tuyet doi 2 so lon
int soSanhAbs(char *aInt, char *aFrac, char *bInt, char *bFrac) {
    if (strlen(aInt) != strlen(bInt))
        return strlen(aInt) > strlen(bInt) ? 1 : -1;

    int cmp = strcmp(aInt, bInt);
    if (cmp != 0) return cmp > 0 ? 1 : -1;

    int la = strlen(aFrac), lb = strlen(bFrac);
    int L = la > lb ? la : lb;

    for (int i = 0; i < L; i++) {
        char ca = (i < la ? aFrac[i] : '0');
        char cb = (i < lb ? bFrac[i] : '0');
        if (ca != cb) return ca > cb ? 1 : -1;
    }
    return 0;
}

// Cong tri tuyet doi 2 so lon
void congAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
             char *resInt, char *resFrac)
{
    int la = strlen(aFrac);
    int lb = strlen(bFrac);
    int L = la > lb ? la : lb;

    char A[MAX], B[MAX];
    strcpy(A, aFrac);
    strcpy(B, bFrac);

    while (strlen(A) < L) strcat(A, "0");
    while (strlen(B) < L) strcat(B, "0");

    resFrac[L] = '\0';
    int carry = 0;

    for (int i = L-1; i >= 0; i--) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        resFrac[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    char IA[MAX], IB[MAX];
    strcpy(IA, aInt);
    strcpy(IB, bInt);

    int ia = strlen(IA);
    int ib = strlen(IB);
    int imax = ia > ib ? ia : ib;

    resInt[imax] = '\0';
    int k = imax - 1;
    ia--; ib--;

    while (imax--) {
        int da = ia >= 0 ? IA[ia--] - '0' : 0;
        int db = ib >= 0 ? IB[ib--] - '0' : 0;
        int sum = da + db + carry;
        resInt[k--] = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry) {
        memmove(resInt + 1, resInt, strlen(resInt) + 1);
        resInt[0] = '1';
    }

    xoaSo0Cuoi(resFrac);
    xoaSo0Dau(resInt);
}

// Tru tri tuyet doi (so lon tru so be)
void truAbs(char *aInt, char *aFrac, char *bInt, char *bFrac,
            char *resInt, char *resFrac)
{
    int la = strlen(aFrac), lb = strlen(bFrac);
    int L = la > lb ? la : lb;

    char A[MAX], B[MAX];
    strcpy(A, aFrac);
    strcpy(B, bFrac);
    while (strlen(A) < L) strcat(A, "0");
    while (strlen(B) < L) strcat(B, "0");

    resFrac[L] = '\0';
    int borrow = 0;

    for (int i = L-1; i >= 0; i--) {
        int da = A[i] - '0' - borrow;
        int db = B[i] - '0';
        if (da < db) {
            da += 10;
            borrow = 1;
        } else borrow = 0;
        resFrac[i] = (da - db) + '0';
    }

    char IA[MAX], IB[MAX];
    strcpy(IA, aInt);
    strcpy(IB, bInt);

    int ia = strlen(IA);
    int ib = strlen(IB);
    int imax = ia;

    resInt[imax] = '\0';
    int k = imax - 1;
    ia--; ib--;

    while (imax--) {
        int da = IA[ia--] - '0';
        int db = ib >= 0 ? IB[ib--] - '0' : 0;
        da -= borrow;

        if (da < db) {
            da += 10;
            borrow = 1;
        } else borrow = 0;

        resInt[k--] = (da - db) + '0';
    }

    xoaSo0Cuoi(resFrac);
    xoaSo0Dau(resInt);
}

int main() {
    char A[MAX], B[MAX];
    char aInt[MAX], aFrac[MAX], bInt[MAX], bFrac[MAX];
    char resInt[MAX], resFrac[MAX];
    int signA, signB;

    printf("Nhap so thu nhat: ");
    scanf("%s", A);
    printf("Nhap so thu hai: ");
    scanf("%s", B);

    tachSo(A, aInt, aFrac, &signA);
    tachSo(B, bInt, bFrac, &signB);

    int cmp = soSanhAbs(aInt, aFrac, bInt, bFrac);
    int signKQ = 0;

    if (signA == signB) {
        congAbs(aInt, aFrac, bInt, bFrac, resInt, resFrac);
        signKQ = signA;
    } else {
        if (cmp == 0) {
            printf("Ket qua: 0\n");
            return 0;
        } else if (cmp > 0) {
            truAbs(aInt, aFrac, bInt, bFrac, resInt, resFrac);
            signKQ = signA;
        } else {
            truAbs(bInt, bFrac, aInt, aFrac, resInt, resFrac);
            signKQ = signB;
        }
    }

    if (signKQ) printf("-");

    printf("%s", resInt);
    if (strlen(resFrac) > 0)
        printf(".%s", resFrac);

    printf("\n");
    return 0;
}
