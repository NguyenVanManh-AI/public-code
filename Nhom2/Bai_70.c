#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Doc chuoi */
void nhap_chuoi(const char *ten, char *out) {
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra so nguyen hop le */
int la_so_nguyen(const char *s) {
    int i = 0;

    if (s[0] == '-' && s[1] != '\0') i = 1;

    for (; s[i]; i++)
        if (!isdigit(s[i])) return 0;

    return 1;
}

/* Chuyen chuoi sang long long */
long long to_ll(const char *s) {
    long long x = 0;
    int sign = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return sign * x;
}

/* Sap xep tang dan (bubble sort) */
void sort(long long arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                long long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

int main() {
    int nA, nB;

    /* Nhap nA */
    while (1) {
        char buf[100];
        nhap_chuoi("so luong phan tu cua A", buf);

        if (la_so_nguyen(buf)) {
            nA = (int)to_ll(buf);
            if (nA > 0) break;
        }
        printf("n phai > 0. Nhap lai.\n");
    }

    /* Nhap nB */
    while (1) {
        char buf[100];
        nhap_chuoi("so luong phan tu cua B", buf);

        if (la_so_nguyen(buf)) {
            nB = (int)to_ll(buf);
            if (nB > 0) break;
        }
        printf("n phai > 0. Nhap lai.\n");
    }

    char buf[100];
    long long A[200], B[200], C[400];

    printf("=== Nhap cac phan tu mang A ===\n");
    for (int i = 0; i < nA; i++) {
        char ten[50];
        sprintf(ten, "A[%d]", i);
        nhap_chuoi(ten, buf);
        A[i] = to_ll(buf);
    }

    printf("=== Nhap cac phan tu mang B ===\n");
    for (int i = 0; i < nB; i++) {
        char ten[50];
        sprintf(ten, "B[%d]", i);
        nhap_chuoi(ten, buf);
        B[i] = to_ll(buf);
    }

    printf("=== Mang A vua nhap ===\n");
    for (int i = 0; i < nA; i++) printf("%lld ", A[i]);

    printf("\n=== Mang B vua nhap ===\n");
    for (int i = 0; i < nB; i++) printf("%lld ", B[i]);

    /* Noi mang */
    int nC = nA + nB;
    for (int i = 0; i < nA; i++) C[i] = A[i];
    for (int i = 0; i < nB; i++) C[nA + i] = B[i];

    /* Sap xep */
    sort(C, nC);

    printf("\n=== Mang sau khi noi va da tang dan ===\n");
    for (int i = 0; i < nC; i++) printf("%lld ", C[i]);

    printf("\n");

    return 0;
}