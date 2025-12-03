#include <stdio.h>
#include <math.h>

#define MAX 50

// *** NHAP MA TRAN ***
void nhapMat(double a[][MAX], int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
}

// *** XUAT MA TRAN ***
void xuatMat(double a[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%15.6lf", a[i][j]);
        printf("\n");
    }
}

// *** TINH DINH THUC BANG GAUSS ***
double detGauss(double A[][MAX], int n){
    double a[MAX][MAX];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = A[i][j];

    double det = 1.0;
    for(int i=0; i<n; i++){
        if(fabs(a[i][i]) < 1e-12){
            int sw = 0;
            for(int k=i+1; k<n; k++){
                if(fabs(a[k][i]) > 1e-12){
                    for(int j=0; j<n; j++){
                        double tmp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = tmp;
                    }
                    det = -det;
                    sw = 1;
                    break;
                }
            }
            if(!sw) return 0;
        }
        det *= a[i][i];
        for(int k=i+1; k<n; k++){
            double ratio = a[k][i] / a[i][i];
            for(int j=i; j<n; j++)
                a[k][j] -= ratio * a[i][j];
        }
    }
    return det;
}

// *** TINH MA TRAN PHU HOP (ADJOINT) ***
void adjoint(double a[][MAX], double adj[][MAX], int n){
    if(n == 1){
        adj[0][0] = 1;
        return;
    }

    double temp[MAX][MAX];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int p = 0, q = 0;
            for(int row=0; row<n; row++){
                if(row == i) continue;
                for(int col=0; col<n; col++){
                    if(col == j) continue;
                    temp[p][q++] = a[row][col];
                    if(q == n-1){
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

// *** TINH MA TRAN NGHICH DAO ***
int inverse(double a[][MAX], double inv[][MAX], int n){
    double det = detGauss(a, n);
    printf("Determinant (det) = %f\n", det);
    if(fabs(det) < 1e-12){ // tang nguong suy bien de thong bao suy bien
        printf("Ma tran suy bien, khong co nghich dao!\n");
        return 0;
    }

    double adj[MAX][MAX];
    adjoint(a, adj, n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            inv[i][j] = adj[i][j] / det;

    return 1;
}

// *** MAIN ***
int main(){
    int n;
    double A[MAX][MAX], INV[MAX][MAX];

    do{
        printf("Nhap cap ma tran vuong n : ", MAX);
        scanf("%d", &n);
        if(n <= 0 || n > MAX)
            printf("Kich thuoc khong hop le ! Hay nhap lai.\n");
    } while(n <= 0 || n > MAX);

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
