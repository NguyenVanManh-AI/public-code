#include <stdio.h>

void nhapMaTran(double a[][50], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
}

void xuatMaTran(double a[][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%15.3lf ", a[i][j]); 	// in dep, du khoang cach
        printf("\n");
    }
}

double timMaxDong(double a[][50], int n, int dong) {
    double max = a[dong][0];
    for (int j = 1; j < n; j++)
        if (a[dong][j] > max)
            max = a[dong][j];
    return max;
}

int main() {
    int n;

    // Nhap n > 0
    do {
        printf("Nhap n (n > 0): ");
        scanf("%d", &n);
        if (n <= 0) printf("n phai > 0, vui long nhap lai!\n");
    } while (n <= 0);

    double A[50][50];

    // Nhap ma tran
    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    // Xuat ma tran ban dau
    printf("\nMa tran A vua nhap:\n");
    xuatMaTran(A, n);

    double sum = 0;

    // Dua max moi hang len duong cheo chinh
    for (int i = 0; i < n; i++) {
        double maxVal = timMaxDong(A, n, i);
        A[i][i] = maxVal;
        sum += maxVal;
    }

    // Xuat ma tran sau khi xu ly
    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMaTran(A, n);

    // Tong
    printf("\nTong cac phan tu lon nhat duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}
