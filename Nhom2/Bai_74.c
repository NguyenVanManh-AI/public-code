#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50 // kich thuoc toi da cua ma tran

/* 
 * Ham kiem tra chuoi co phai so nguyen hay khong
 * Tra ve 1 neu dung, 0 neu khong
 */
int la_so_nguyen(const char *s) {
    int i = 0;

    if(s[0] == '+' || s[0] == '-') i = 1; /* bo qua dau + hoac - */

    for(; s[i] != '\0'; i++)
        if(!isdigit(s[i])) return 0; /* phat hien ky tu khong phai so -> sai */

    return 1; // hop le
}

/* 
 * Ham nhap so nguyen >= 1 va <= MAX
 * nhac: thong bao khi nhap
 */
int nhap_so_nguyen(const char *nhac) {
    char s[100];
    int x;

    while(1) {
        printf("%s", nhac);
        scanf("%s", s); // nhap bang chuoi de kiem tra

        if(la_so_nguyen(s)) {
            x = atoi(s); // chuyen sang so nguyen
            if(x > 0 && x <= MAX) return x; // hop le
        }

        printf("Gia tri khong hop le! Nhap lai.\n");
    }
}

/* --- NHAP MA TRAN --- */
void nhapMat(double a[][MAX], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i+1, j+1); // thong bao vi tri nhap
            scanf("%lf", &a[i][j]); // nhap phan tu
        }
}

/* --- XUAT MA TRAN --- */
void xuatMat(double a[][MAX], int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            printf("%20.3lf", a[i][j]); // in canh le 20 ky tu, 3 chu so thap phan
        printf("\n");
    }
}

/* --- TIM MAX TREN 1 HANG --- */
double timMaxDong(double a[][MAX], int n, int dong) {
    int j;
    double max = a[dong][0]; // khoi tao gia tri max
    for(j = 1; j < n; j++)
        if(a[dong][j] > max)
            max = a[dong][j]; // cap nhat max neu lon hon
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
        double maxx = timMaxDong(A, n, i); // tim max tren hang i
        A[i][i] = maxx;   /* ghi de len duong cheo chinh */
        sum += maxx; // tinh tong
    }

    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMat(A, m, n);

    printf("\nTong cac phan tu duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}

/**
 * THUAT TOAN CHUONG TRINH
 * 1. Nhap m va n bang ham nhap_so_nguyen (so nguyen duong <= MAX)
 * 2. Nhap ma tran A (m hang n cot)
 * 3. In ma tran vua nhap
 * 4. Kiem tra ma tran co vuong hay khong:
 *      - Neu khong vuong thi thong bao va dung chuong trinh
 * 5. Duyet tung hang:
 *      - Tim phan tu lon nhat tren hang i
 *      - Gan phan tu lon nhat len duong cheo chinh A[i][i]
 *      - Cong phan tu vao tong sum
 * 6. In ma tran sau khi dua max len duong cheo chinh
 * 7. In tong cac phan tu duoc dua len duong cheo
 *
 * LUU Y
 * - Chuong trinh khong doi cac phan tu khac tren hang, chi ghi de len duong cheo
 * - Su dung kieu double de luu gia tri thap phan
 * - Su dung MAX = 50 gioi han kich thuoc ma tran
 */
