#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 50   // dong bo lai voi kich thuoc ma tran

/* Ham kiem tra chuoi co phai so nguyen du hay khong (am, duong) */
int la_so_nguyen(const char *s) {
    int i = 0;
    if(s[0] == '-' || s[0] == '+') 
        i = 1; // bo qua dau

    for(; s[i] != '\0'; i++) {
        if(!isdigit(s[i])) 
            return 0; // neu gap ky tu khac so -> sai
    }
    return 1;
}

/* Ham nhap so nguyen duong n dung dinh dang */
int nhap_so_nguyen(const char *nhac) {
    char s[100];
    int n;

    while(1) {
        printf("%s", nhac);
        scanf("%s", s);

        if(la_so_nguyen(s)) {
            n = atoi(s);
            if(n > 0 && n <= MAX) 
                return n;
        }

        printf("Gia tri khong hop le. Vui long nhap lai!\n");
    }
}

/* Ham nhap ma tran vuong */
void nhapMaTran(double a[][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
    }
}

/* Ham xuat ma tran */
void xuatMaTran(double a[][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%15.3f ", a[i][j]);
        }
        printf("\n");
    }
}

/* Tim phan tu nho nhat tren mot hang */
double minHang(double a[][MAX], int n, int dong){
    double min = a[dong][0];
    int j;
    for(j = 1; j < n; j++){
        if(a[dong][j] < min) 
            min = a[dong][j];
    }
    return min;
}

int main(){
    int n;
    double A[MAX][MAX];

    /* Nhap n dung tieu chuan */
    n = nhap_so_nguyen("Nhap n (1 <= n <= 50): ");

    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    printf("Ma tran A vua nhap:\n");
    xuatMaTran(A, n);

    double sum = 0;
    int i;

    /* Dua phan tu nho nhat tung hang len duong cheo phu */
    for(i = 0; i < n; i++){
        double minn = minHang(A, n, i);  // tim min hang i
        A[i][n - 1 - i] = minn;          // gan len duong cheo phu
        sum += minn;                     // cong vao tong
    }

    printf("Ma tran sau khi dua min tung hang len duong cheo phu:\n");
    xuatMaTran(A, n);

    printf("Tong cac gia tri nho nhat = %.3f\n", sum);

    return 0;
}
