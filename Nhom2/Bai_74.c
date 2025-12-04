#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

/* Ham kiem tra chuoi co phai so nguyen du duong khong */
int la_so_nguyen(const char *s) {
    int i = 0;

    if(s[0] == '+' || s[0] == '-') i = 1; /* bo qua dau */

    for(; s[i] != '\0'; i++)
        if(!isdigit(s[i])) return 0; /* phat hien ky tu khong phai so -> sai */

    return 1;
}

/* Ham nhap so nguyen >= 1 va <= MAX */
int nhap_so_nguyen(const char *nhac) {
    char s[100];
    int x;

    while(1) {
        printf("%s", nhac);
        scanf("%s", s);

        if(la_so_nguyen(s)) {
            x = atoi(s);
            if(x > 0 && x <= MAX) return x;
        }

        printf("Gia tri khong hop le! Nhap lai.\n");
    }
}

/* --- NHAP MA TRAN --- */
void nhapMat(double a[][MAX], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
}

/* --- XUAT MA TRAN --- */
void xuatMat(double a[][MAX], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            printf("%20.3lf", a[i][j]);
        printf("\n");
    }
}

/* --- TIM MAX TREN 1 HANG --- */
double timMaxDong(double a[][MAX], int n, int dong) {
    int j;
    double max = a[dong][0];
    for(j = 1; j < n; j++)
        if(a[dong][j] > max)
            max = a[dong][j];
    return max;
}

int main() {
    int m, n;
    double A[MAX][MAX];
    double sum;
    int i;

    /* --- NHAP m dung cach moi --- */
    m = nhap_so_nguyen("Nhap m = ");

    /* --- NHAP n dung cach moi --- */
    n = nhap_so_nguyen("Nhap n = ");

    printf("Nhap ma tran A:\n");
    nhapMat(A, m, n);

    printf("\nMa tran A vua nhap:\n");
    xuatMat(A, m, n);

    /* --- KIEM TRA MA TRAN VUONG --- */
    if(m != n) {
        printf("\nKhong phai la ma tran vuong, nen khong co duong cheo chinh!\n");
        return 0;
    }

    /* --- DUA MAX TUNG HANG LEN DUONG CHEO CHINH --- */
    sum = 0;
    for(i = 0; i < n; i++) {
        double maxx = timMaxDong(A, n, i);
        A[i][i] = maxx;   /* ghi de, khong doi cho */
        sum += maxx;
    }

    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMat(A, m, n);

    printf("\nTong cac phan tu duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}
