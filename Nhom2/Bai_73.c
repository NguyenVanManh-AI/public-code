#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50 // kich thuoc toi da cua ma tran

/** 
 * Ham kiem tra chuoi co phai la so nguyen >= 1
 * Tra ve 1 neu hop le, 0 neu khong hop le
 */
int la_so_nguyen_duong(const char *s) {
    int i = 0;

    /* Neu co dau '+' thi bo qua */
    if(s[0] == '+') i = 1;

    /* Khong cho phep dau '-' vi n phai la so duong */
    if(s[0] == '-') return 0;

    for(; s[i] != '\0'; i++)
        if(!isdigit(s[i])) return 0; // neu co ky tu khong phai so

    return 1; // hop le
}

/** 
 * Ham nhap n theo cach an toan
 * Tra ve n la so nguyen duong <= MAX
 */
int nhap_n() {
    char s[100];
    int x;

    while(1) {
        printf("Nhap cap ma tran vuong n : ");
        scanf("%s", s); // nhap tam thoi bang chuoi

        if(la_so_nguyen_duong(s)) {
            x = atoi(s); // chuyen sang so nguyen
            if(x > 0 && x <= MAX) return x; // hop le
        }

        printf("Kich thuoc khong hop le! Hay nhap lai.\n");
    }
}

/* --- NHAP MA TRAN --- */
void nhapMat(double a[][MAX], int n){
    int i, j; // bien lap
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]); // nhap phan tu
        }
}

/* --- XUAT MA TRAN --- */
void xuatMat(double a[][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%15.6lf", a[i][j]); // in canh le 15 ky tu, 6 chu so thap phan
        printf("\n");
    }
}

/* --- TINH DINH THUC BANG GAUSS --- */
double detGauss(double A[][MAX], int n){
    double a[MAX][MAX];
    int i, j, k;

    /* sao chep A vao a de tinh, khong thay doi goc */
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = A[i][j];

    double det = 1.0; // khoi tao det

    for(i = 0; i < n; i++){

        /* Neu pivot gan = 0 thi doi hang */
        if(fabs(a[i][i]) < 1e-12){
            int sw = 0;

            for(k = i+1; k < n; k++){
                if(fabs(a[k][i]) > 1e-12){
                    /* doi hang i va k */
                    for(j = 0; j < n; j++){
                        double tmp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = tmp;
                    }
                    det = -det; /* doi dau dinh thuc */
                    sw = 1;
                    break;
                }
            }
            if(!sw) return 0; // tat ca cac gia tri pivot bang 0 -> det = 0
        }

        det *= a[i][i]; // nhan pivot vao det

        /* Loai cac phan tu ben duoi */
        for(k = i+1; k < n; k++){
            double ratio = a[k][i] / a[i][i];
            for(j = i; j < n; j++)
                a[k][j] -= ratio * a[i][j]; // loai bo cac phan tu ben duoi pivot
        }
    }
    return det;
}

/* --- TINH MA TRAN PHU HOP (ADJOINT) --- */
void adjoint(double a[][MAX], double adj[][MAX], int n){
    int i, j;

    if(n == 1){
        adj[0][0] = 1;
        return;
    }

    double temp[MAX][MAX];
    int row, col, p, q;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){

            p = q = 0;

            /* tao ma tran con bo hang i va cot j */
            for(row = 0; row < n; row++){
                if(row == i) continue;
                for(col = 0; col < n; col++){
                    if(col == j) continue;
                    temp[p][q++] = a[row][col];
                    if(q == n - 1){
                        q = 0;
                        p++;
                    }
                }
            }

            double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            adj[j][i] = sign * detGauss(temp, n - 1); // luu vao ma tran adjoint (tra ma tran chuyen vi)
        }
    }
}

/* --- TINH MA TRAN NGHICH DAO --- */
int inverse(double a[][MAX], double inv[][MAX], int n){
    double det = detGauss(a, n);

    printf("Determinant (det) = %f\n", det);

    if(fabs(det) < 1e-12){
        printf("Ma tran suy bien, khong co nghich dao!\n");
        return 0; // ma tran khong co nghich dao
    }

    double adj[MAX][MAX];
    int i, j;

    adjoint(a, adj, n); // tinh ma tran phu hop

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det; // chia cho dinh thuc -> nghich dao

    return 1;
}

/* --- MAIN --- */
int main(){
    int n;
    double A[MAX][MAX], INV[MAX][MAX];

    /* Nhap n bang chuoi */
    n = nhap_n();

    printf("Nhap ma tran A:\n");
    nhapMat(A, n);

    printf("\nMa tran A:\n");
    xuatMat(A, n);

    printf("\nMa tran nghich dao A^-1:\n");
    if(inverse(A, INV, n)){
        xuatMat(INV, n);
    }

    return 0;
}

/**
 * THUAT TOAN CHUONG TRINH
 * 1. Nhap kich thuoc n cua ma tran vuong A, bang chuoi de kiem tra hop le (so nguyen duong <= MAX)
 * 2. Nhap cac phan tu ma tran A
 * 3. In ma tran A
 * 4. Tinh dinh thuc A bang phuong phap Gauss:
 *      - Neu pivot bang 0 thi doi hang voi mot hang duoi khac
 *      - Nhan pivot vao det, loai cac phan tu ben duoi
 * 5. Tinh ma tran phu hop (adjoint) cua A
 *      - Luu y: ma tran phu hop la ma tran chuyen vi cua ma tran cofactors
 * 6. Tinh ma tran nghich dao:
 *      - inv = adj / det
 *      - Neu det = 0 -> ma tran suy bien, khong co nghich dao
 * 7. In ma tran nghich dao neu ton tai
 *
 * LUU Y
 * - Su dung kieu double de chua gia tri
 * - So sanh voi 1e-12 de tranh loi lam tron khi so sanh voi 0
 * - MAX = 50 gioi han kich thuoc ma tran
 */
