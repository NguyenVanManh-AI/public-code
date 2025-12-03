#include <stdio.h>
#include <math.h>

#define MAX 50

// --- NHAP MA TRAN ---
void nhapMat(double a[][MAX], int m, int n) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
}

// --- XUAT MA TRAN ---
void xuatMat(double a[][MAX], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%20.3Lf      ", a[i][j]);
        printf("\n");
    }
}

// --- TIM MAX TREN 1 HANG ---
double timMaxDong(double a[][MAX], int n, int dong) {
    double max = a[dong][0];
    for(int j = 1; j < n; j++)
        if(a[dong][j] > max) max = a[dong][j];
    return max;
}

int main() {
    int m, n;
    double A[MAX][MAX];

    // --- NHAP m ---
    do {
        printf("Nhap m = ");
        scanf("%d", &m);
        if(m <= 0 || m > MAX)
            printf("m khong hop le! Nhap lai.\n");
    } while(m <= 0 || m > MAX);

    // --- NHAP n ---
    do {
        printf("Nhap n = ");
        scanf("%d", &n);
        if(n <= 0 || n > MAX)
            printf("n khong hop le! Nhap lai.\n");
    } while(n <= 0 || n > MAX);

    printf("Nhap ma tran A:\n");
    nhapMat(A, m, n);

    printf("\nMa tran A vua nhap:\n");
    xuatMat(A, m, n);

    // --- KIEM TRA MA TRAN VUONG ---
    if(m != n) {
        printf("\nKhong phai la ma tran vuong, nen khong co duong cheo chinh!\n");
        return 0;
    }

    // --- DUA MAX TUNG HANG LEN DUONG CHEO CHINH ---
    double sum = 0;
    for(int i = 0; i < n; i++) {
        double maxx = timMaxDong(A, n, i);
        A[i][i] = maxx; 	// chi GHI DE, khong doi cho
        sum += maxx;
    }

    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMat(A, m, n);

    printf("\nTong cac phan tu duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}