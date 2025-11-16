#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, int arr[MAX][MAX]) { 
    printf("\n");
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("A[%d][%d]=%d ", i,j, arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nhap(int n, int arr[MAX][MAX]) {
    printf("\n");
    int i,j;
    for(i = 0;i<n;i++) {
        for(j = 0;j<n;j++) {
            printf("A[%d][%d]= ",i,j); 
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
}

// Ham tinh dinh thuc theo trien khai Laplace
double det(int n, int a[MAX][MAX]) {
    if (n == 1)
        return a[0][0];
    if (n == 2)
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    double D = 0;
    int x,i,j, sub[MAX][MAX]; // ma tran con 

    for (x = 0; x < n; x++) {
        int subi = 0;
        for (i = 1; i < n; i++) {
            int subj = 0;
            for (j = 0; j < n; j++) {
                if (j == x)
                    continue;
                sub[subi][subj] = a[i][j];
                subj++;
            }
            subi++;
        }
        // (-1)^(x) * a[0][x] * det(phan con lai)
        D += (pow(-1, x) * a[0][x] * det(n - 1, sub));
    }

    return D;
}

void program() {
    int n;
    printf("n : "); scanf("%d", &n);
    int a[MAX][MAX];

    nhap(n,a);
    xuat(n,a);
    printf("det(A) = %lf\n", det(n,a));
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

