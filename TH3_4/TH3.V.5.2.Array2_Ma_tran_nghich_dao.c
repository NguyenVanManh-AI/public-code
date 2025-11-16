#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, double arr[MAX][MAX]) {
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.3lf ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nhap(int n, int arr[MAX][MAX]) {
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]= ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
}

// Ham tinh dinh thuc bang khai trien Laplace
double det(int n, int a[MAX][MAX]) {
    int x, i, j, subi, subj;
    double D = 0;
    int sub[MAX][MAX];

    if (n == 1)
        return a[0][0];
    if (n == 2)
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    for (x = 0; x < n; x++) {
        subi = 0;
        for (i = 1; i < n; i++) {
            subj = 0;
            for (j = 0; j < n; j++) {
                if (j == x)
                    continue;
                sub[subi][subj] = a[i][j];
                subj++;
            }
            subi++;
        }
        D += (pow(-1, x) * a[0][x] * det(n - 1, sub));
    }
    return D;
}

// Lay ma tran con tai vi tri (p,q)
void getCofactor(int A[MAX][MAX], int temp[MAX][MAX], int p, int q, int n) {
    int row, col, i = 0, j = 0;
    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Tim ma tran nghich dao bang cong thuc cofactor
void inverseMatrix(int n, int A[MAX][MAX], double inverse[MAX][MAX]) {
    double detA;
    int i, j;
    int cofactor[MAX][MAX];
    double adj[MAX][MAX];
    int temp[MAX][MAX];
    double sign;

    detA = det(n, A);
    if (fabs(detA) < 1e-9) {
        printf("\nMa tran khong co nghich dao (det(A)=0)\n");
        return;
    }

    // Tinh ma tran phu dai so (Cofactor)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            getCofactor(A, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            cofactor[i][j] = sign * det(n - 1, temp);
        }
    }

    // Tinh ma tran chuyen vi cua Cofactor -> Adj(A)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adj[i][j] = cofactor[j][i];
        }
    }

    // Chia tung phan tu cho det(A)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            inverse[i][j] = adj[i][j] / detA;
        }
    }
}

void program() {
    int n;
    int A[MAX][MAX];
    double detA;
    double inv[MAX][MAX];

    printf("n : ");
    scanf("%d", &n);
    nhap(n, A);

    detA = det(n, A);
    printf("det(A) = %.3lf\n", detA);

    if (fabs(detA) < 1e-9) {
        printf("=> Ma tran KHONG co nghich dao.\n");
        return;
    }

    inverseMatrix(n, A, inv);
    printf("\nMa tran nghich dao A^-1:\n");
    xuat(n, inv);
}

int main() {
    while (1) {
        program();
        printf("\n---------------------\n");
    }
    return 0;
}

