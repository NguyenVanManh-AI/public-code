#include <stdio.h>
#include <math.h>

#define MAX 50

// Nguyen Van Manh - Lop SH 20T1 - MSSV: 102200024 - Nhom 10A

// 1. Nhap ma tran vuong cap n
void nhapMat(float a[][MAX], int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
}

// 2. Xuat ma tran ra man hinh, dinh dang 3 chu so thap phan
void xuatMat(float a[][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%10.3f", a[i][j]);
        printf("\n");
    }
}

// 3.1. Dinh thuc theo phuong phap Laplace (de quy)
float detLaplace(float a[][MAX], int n){
    if(n==1) return a[0][0];
    if(n==2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    float det = 0;
    float temp[MAX][MAX];
    for(int k=0; k<n; k++){
        int r=0, c=0;
        for(int i=1; i<n; i++){           // bo hang 0
            for(int j=0; j<n; j++){
                if(j==k) continue;        // bo cot k
                temp[r][c++] = a[i][j];
                if(c==n-1){ c=0; r++; }
            }
        }
        det += (k%2==0 ? 1 : -1) * a[0][k] * detLaplace(temp, n-1);
    }
    return det;
}

// 3.2. Dinh thuc bang bien doi Gauss (khu Gauss)
float detGauss(float A[][MAX], int n){
    float a[MAX][MAX];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = A[i][j];

    float det = 1.0;
    for(int i=0; i<n; i++){
        if(fabs(a[i][i]) < 1e-10){
            int sw = 0;
            for(int k=i+1; k<n; k++){
                if(fabs(a[k][i]) > 1e-10){
                    for(int j=0; j<n; j++){
                        float tmp = a[i][j];
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
            float ratio = a[k][i] / a[i][i];
            for(int j=i; j<n; j++)
                a[k][j] -= ratio * a[i][j];
        }
    }
    return det;
}

// 3.3. Dinh thuc bien doi ve dang tam giac tren
float detTriangle(float A[][MAX], int n){
    float a[MAX][MAX];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = A[i][j];

    float det = 1.0;
    for(int i=0; i<n; i++){
        if(fabs(a[i][i]) < 1e-10){
            int sw = 0;
            for(int k=i+1; k<n; k++){
                if(fabs(a[k][i]) > 1e-10){
                    for(int j=0; j<n; j++){
                        float tmp = a[i][j];
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
        for(int k=i+1; k<n; k++){
            float ratio = a[k][i] / a[i][i];
            for(int j=i; j<n; j++)
                a[k][j] -= ratio * a[i][j];
        }
    }
    for(int i=0; i<n; i++) det *= a[i][i];   // tich duong cheo
    return det;
}

// 3.4. Dinh thuc bang phan tich LU 
float detLU(float a[][MAX], int n){
    float U[MAX][MAX] = {0};
    float L[MAX][MAX] = {0};

    for(int i=0; i<n; i++){
        for(int k=i; k<n; k++){
            float sum = 0;
            for(int j=0; j<i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = a[i][k] - sum;
        }
        for(int k=i; k<n; k++){
            if(i == k) L[i][i] = 1;
            else{
                float sum = 0;
                for(int j=0; j<i; j++)
                    sum += L[k][j] * U[j][i];
                if(fabs(U[i][i]) < 1e-10) return 0;
                L[k][i] = (a[k][i] - sum) / U[i][i];
            }
        }
    }
    float det = 1.0;
    for(int i=0; i<n; i++) det *= U[i][i];
    return det;
}

// 3.5. Dinh thuc Sarrus chi danh cho ma tran 3x3
float detSarrus(float a[][MAX]){
    return a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1]
         - a[0][2]*a[1][1]*a[2][0] - a[0][0]*a[1][2]*a[2][1] - a[0][1]*a[1][0]*a[2][2];
}

void adjoint(float a[][MAX], float adj[][MAX], int n){
    if(n == 1){
        adj[0][0] = 1;
        return;
    }
    float temp[MAX][MAX];

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
            float sign = ((i + j) % 2 == 0) ? 1.0f : -1.0f;
            adj[j][i] = sign * detGauss(temp, n-1);
        }
    }
}

// 4. Tinh ma tran nghich dao = (1/det) * adj(A)
int inverse(float a[][MAX], float inv[][MAX], int n){
    float det = detGauss(a, n);
    if(fabs(det) < 1e-10){
        printf("Ma tran suy bien, khong co nghich dao!\n");
        return 0;
    }
    float adj[MAX][MAX];
    adjoint(a, adj, n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            inv[i][j] = adj[i][j] / det;
    return 1;
}

int main(){
    int n;
    float A[MAX][MAX], INV[MAX][MAX];

    printf("Nhap cap ma tran vuong n : ", MAX);
    scanf("%d", &n);

    if(n <= 0 || n > MAX){
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    printf("Nhap ma tran A:\n");
    nhapMat(A, n);

    printf("\nMa tran A:\n");
    xuatMat(A, n);

    printf("\n1. Dinh thuc (Laplace)      = %.3f\n", detLaplace(A, n));
    printf("2. Dinh thuc (Gauss)        = %.3f\n", detGauss(A, n));
    printf("3. Dinh thuc (Tam giac)     = %.3f\n", detTriangle(A, n));
    printf("4. Dinh thuc (LU)           = %.3f\n", detLU(A, n));
    if(n == 3)
        printf("5. Dinh thuc (Sarrus 3x3)   = %.3f\n", detSarrus(A));
    else
        printf("5. Dinh thuc (Sarrus 3x3)   = Khong ap dung voi ma tran khac 3x3\n");

    printf("\nMa tran nghich dao A^-1:\n");
    if(inverse(A, INV, n)){
        xuatMat(INV, n);
    }

    return 0;
}
