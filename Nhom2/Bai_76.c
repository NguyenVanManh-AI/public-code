#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 50   // dong bo lai voi kich thuoc ma tran

/* 
 * Ham kiem tra chuoi co phai so nguyen hay khong (duong hoac am)
 * Tra ve 1 neu dung, 0 neu khong
 */
int la_so_nguyen(const char *s) {
    int i = 0;
    if(s[0] == '-' || s[0] == '+') 
        i = 1; // bo qua dau + hoac -

    for(; s[i] != '\0'; i++) {
        if(!isdigit(s[i])) 
            return 0; // neu gap ky tu khac so -> sai
    }
    return 1; // hop le
}

/* 
 * Ham nhap so nguyen duong n dung dinh dang (1 <= n <= MAX)
 * nhac: thong bao khi nhap
 */
int nhap_so_nguyen(const char *nhac) {
    char s[100];
    int n;

    while(1) {
        printf("%s", nhac);
        scanf("%s", s); // nhap bang chuoi

        if(la_so_nguyen(s)) {
            n = atoi(s); // chuyen sang so nguyen
            if(n > 0 && n <= MAX) 
                return n; // hop le
        }

        printf("Gia tri khong hop le. Vui long nhap lai!\n");
    }
}

/* --- NHAP MA TRAN VUONG --- */
void nhapMaTran(double a[][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i+1, j+1); // thong bao vi tri nhap
            scanf("%lf", &a[i][j]);          // nhap phan tu
        }
    }
}

/* --- XUAT MA TRAN --- */
void xuatMaTran(double a[][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%15.3f ", a[i][j]); // in canh le 15 ky tu, 3 chu so thap phan
        }
        printf("\n");
    }
}

/* 
 * Tim phan tu nho nhat tren mot hang
 * Tra ve gia tri nho nhat
 */
double minHang(double a[][MAX], int n, int dong){
    double min = a[dong][0]; // khoi tao min
    int j;
    for(j = 1; j < n; j++){
        if(a[dong][j] < min) 
            min = a[dong][j]; // cap nhat neu nho hon
    }
    return min;
}

int main(){
    int n;
    double A[MAX][MAX];

    /* Nhap n dung tieu chuan */
    n = nhap_so_nguyen("Nhap n : ");

    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    printf("Ma tran A vua nhap:\n");
    xuatMaTran(A, n);

    double sum = 0;
    int i;

    /* Dua phan tu nho nhat tung hang len duong cheo phu */
    for(i = 0; i < n; i++){
        double minn = minHang(A, n, i);  // tim min tren hang i
        A[i][n - 1 - i] = minn;          // gan len duong cheo phu
        sum += minn;                     // cong vao tong
    }

    printf("Ma tran sau khi dua min tung hang len duong cheo phu:\n");
    xuatMaTran(A, n);

    printf("Tong cac gia tri nho nhat = %.3f\n", sum);

    return 0;
}

/**
 * THUAT TOAN CHUONG TRINH
 * 1. Nhap kich thuoc n (1 <= n <= MAX) bang ham nhap_so_nguyen
 * 2. Nhap ma tran vuong A (n x n)
 * 3. In ma tran vua nhap
 * 4. Duyet tung hang i:
 *      - Tim phan tu nho nhat tren hang i
 *      - Gan phan tu nho nhat len duong cheo phu A[i][n-1-i]
 *      - Cong vao tong sum
 * 5. In ma tran sau khi dua min len duong cheo phu
 * 6. In tong cac gia tri nho nhat
 *
 * LUU Y
 * - Chuong trinh khong doi cac phan tu khac tren hang, chi gan len duong cheo phu
 * - Su dung kieu double de luu gia tri thap phan
 * - Su dung MAX = 50 gioi han kich thuoc ma tran
 */
