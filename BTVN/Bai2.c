#include <stdio.h>
#include <math.h>

#define MAX 50

// ======================================
// HAM NHAP MA TRAN VUONG
// ======================================
void nhapMat(float a[][MAX], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
}

// ======================================
// HAM XUAT MA TRAN
// ======================================
void xuatMat(float a[][MAX], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%10.3f", a[i][j]);
        printf("\n");
    }
}

// ======================================
// 1. DINH THUC LAPALCE (DE QUY)
// ======================================
float detLaplace(float a[][MAX], int n){
    if(n==1) return a[0][0];
    if(n==2) return a[0][0]*a[1][1]-a[0][1]*a[1][0];

    float det=0;
    float temp[MAX][MAX];

    for(int k=0;k<n;k++){
        int r=0, c=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==k) continue;
                temp[r][c++] = a[i][j];
                if(c==n-1){ c=0; r++; }
            }
        }
        det += ((k%2==0 ? 1:-1) * a[0][k] * detLaplace(temp, n-1));
    }
    return det;
}

// ======================================
// 2. DINH THUC KHUA GAUSS
// ======================================
float detGauss(float A[][MAX], int n){
    float a[MAX][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = A[i][j];

    float det=1;
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            int sw=0;
            for(int k=i+1;k<n;k++){
                if(a[k][i]!=0){
                    for(int j=0;j<n;j++){
                        float tmp=a[i][j]; a[i][j]=a[k][j]; a[k][j]=tmp;
                    }
                    det=-det;
                    sw=1;
                    break;
                }
            }
            if(!sw) return 0; // ma tran suy bien
        }
        det *= a[i][i];
        for(int k=i+1;k<n;k++){
            float ratio = a[k][i]/a[i][i];
            for(int j=i;j<n;j++)
                a[k][j]-=ratio*a[i][j];
        }
    }
    return det;
}

// ======================================
// 3. DINH THUC TAM GIAC TREN (DAU TUONG TU KHUA GAUSS)
// ======================================
float detTriangle(float A[][MAX], int n){
    float a[MAX][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=A[i][j];

    float det=1;
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            int sw=0;
            for(int k=i+1;k<n;k++){
                if(a[k][i]!=0){
                    for(int j=0;j<n;j++){
                        float tmp=a[i][j]; a[i][j]=a[k][j]; a[k][j]=tmp;
                    }
                    det=-det; sw=1; break;
                }
            }
            if(!sw) return 0;
        }
        for(int k=i+1;k<n;k++){
            float ratio = a[k][i]/a[i][i];
            for(int j=i;j<n;j++)
                a[k][j]-=ratio*a[i][j];
        }
    }
    for(int i=0;i<n;i++) det*=a[i][i];
    return det;
}

// ======================================
// 4. DINH THUC LU DECOMPOSITION
// ======================================
float detLU(float a[][MAX], int n){
    float L[MAX][MAX]={0}, U[MAX][MAX]={0};
    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            float sum=0;
            for(int j=0;j<i;j++)
                sum+=L[i][j]*U[j][k];
            U[i][k]=a[i][k]-sum;
        }
        for(int k=i;k<n;k++){
            if(i==k) L[i][i]=1;
            else{
                float sum=0;
                for(int j=0;j<i;j++)
                    sum+=L[k][j]*U[j][i];
                if(U[i][i]==0) return 0; // ma tran suy bien
                L[k][i]=(a[k][i]-sum)/U[i][i];
            }
        }
    }
    float det=1;
    for(int i=0;i<n;i++) det*=U[i][i];
    return det;
}

// ======================================
// 5. DINH THUC SARRUS (CHI CHO 3x3)
// ======================================
float detSarrus(float a[][MAX]){
    return a[0][0]*a[1][1]*a[2][2] +
           a[0][1]*a[1][2]*a[2][0] +
           a[0][2]*a[1][0]*a[2][1] -
           a[0][2]*a[1][1]*a[2][0] -
           a[0][0]*a[1][2]*a[2][1] -
           a[0][1]*a[1][0]*a[2][2];
}

// ======================================
// HAM TINH ADJOINT
// ======================================
void adjoint(float a[][MAX], float adj[][MAX], int n){
    float temp[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int r=0,c=0;
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    if(x!=i && y!=j){
                        temp[r][c++]=a[x][y];
                        if(c==n-1){ c=0; r++; }
                    }
                }
            }
            float sign = ((i+j)%2==0)?1:-1;
            adj[j][i]=sign*detGauss(temp,n-1);
        }
    }
}

// ======================================
// HAM NGHICH DAO
// ======================================
int inverse(float a[][MAX], float inv[][MAX], int n){
    float det=detGauss(a,n);
    if(det==0){
        printf("Ma tran khong kha nghich.\n");
        return 0;
    }
    float adj[MAX][MAX];
    adjoint(a,adj,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            inv[i][j]=adj[i][j]/det;
    return 1;
}

// ======================================
// MAIN
// ======================================
int main(){
    int n;
    float A[MAX][MAX], INV[MAX][MAX];

    printf("Nhap cap ma tran n: ");
    scanf("%d",&n);

    printf("Nhap ma tran A:\n");
    nhapMat(A,n);

    printf("\nMa tran A:\n");
    xuatMat(A,n);

    // 5 phuong phap tinh dinh thuc
    printf("\n1. Dinh thuc (Laplace)      = %.3f\n", detLaplace(A,n));
    printf("2. Dinh thuc (Gauss)        = %.3f\n", detGauss(A,n));
    printf("3. Dinh thuc (Tam giac)     = %.3f\n", detTriangle(A,n));
    printf("4. Dinh thuc (LU)           = %.3f\n", detLU(A,n));
	if(n==3)
        printf("5. Dinh thuc (Sarrus 3x3)   = %.3f\n", detSarrus(A));
    else 
		printf("5. Dinh thuc (Sarrus 3x3)   = Khong ap dung voi ma tran khac 3x3\n"); 
		
    // tinh nghich dao
    printf("\nMa tran nghich dao A^-1:\n");
    if(inverse(A,INV,n))
        xuatMat(INV,n);

    return 0;
}

