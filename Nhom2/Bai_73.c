#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

/* Ham kiem tra chuoi co phai so nguyen >= 1 */
int la_so_nguyen_duong(const char *s) {
    int i = 0;

    /* Neu co dau '+' thi bo qua */
    if(s[0] == '+') i = 1;

    /* Khong cho phep dau '-' vi n phai la so duong */
    if(s[0] == '-') return 0;

    for(; s[i] != '\0'; i++)
        if(!isdigit(s[i])) return 0;

    return 1;
}

/* Ham nhap n theo cach an toan */
int nhap_n() {
    char s[100];
    int x;

    while(1) {
        printf("Nhap cap ma tran vuong n : ");
        scanf("%s", s);

        if(la_so_nguyen_duong(s)) {
            x = atoi(s);
            if(x > 0 && x <= MAX) return x;
        }

        printf("Kich thuoc khong hop le! Hay nhap lai.\n");
    }
}

/* --- NHAP MA TRAN --- */
void nhapMat(double a[][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
}

/* --- XUAT MA TRAN --- */
void xuatMat(double a[][MAX], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%15.6lf", a[i][j]);
        printf("\n");
    }
}

/* --- TINH DINH THUC BANG GAUSS --- */
double detGauss(double A[][MAX], int n){
    double a[MAX][MAX];
    int i, j, k;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            a[i][j] = A[i][j];

    double det = 1.0;

    for(i = 0; i < n; i++){

        /* Neu pivot gan = 0 thi doi hang */
        if(fabs(a[i][i]) < 1e-12){
            int sw = 0;

            for(k = i+1; k < n; k++){
                if(fabs(a[k][i]) > 1e-12){
                    for(j = 0; j < n; j++){
                        double tmp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = tmp;
                    }
                    det = -det; /* doi hang -> doi dau dinh thuc */
                    sw = 1;
                    break;
                }
            }
            if(!sw) return 0;
        }

        det *= a[i][i];

        for(k = i+1; k < n; k++){
            double ratio = a[k][i] / a[i][i];
            for(j = i; j < n; j++)
                a[k][j] -= ratio * a[i][j];
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
            adj[j][i] = sign * detGauss(temp, n - 1);
        }
    }
}

/* --- TINH MA TRAN NGHICH DAO --- */
int inverse(double a[][MAX], double inv[][MAX], int n){
    double det = detGauss(a, n);

    printf("Determinant (det) = %f\n", det);

    if(fabs(det) < 1e-12){
        printf("Ma tran suy bien, khong co nghich dao!\n");
        return 0;
    }

    double adj[MAX][MAX];
    int i, j;

    adjoint(a, adj, n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det;

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
