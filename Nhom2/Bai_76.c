#include <stdio.h>

/* ham nhap ma tran nxn */
void nhap_ma_tran(int a[][20], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

/* ham xuat ma tran nxn */
void xuat_ma_tran(int a[][20], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}

/* ham tim phan tu nho nhat tren 1 hang */
int tim_nho_nhat_hang(int a[][20], int hang, int n) {
    int j;
    int min;

    min = a[hang][0];

    for (j = 1; j < n; j++) {
        if (a[hang][j] < min) {
            min = a[hang][j];
        }
    }

    return min;
}

/* ham dua gia tri nho nhat moi hang len duong cheo phu */
int xu_ly_duong_cheo_phu(int a[][20], int n, int dc[][20]) {
    int i, j;
    int min;
    int tong;

    tong = 0;

    /* tao ma tran co duong cheo phu la gia tri min moi hang */
    for (i = 0; i < n; i++) {
        min = tim_nho_nhat_hang(a, i, n);
        tong += min;

        for (j = 0; j < n; j++) {
            if (j == n - 1 - i) {
                dc[i][j] = min;
            } else {
                dc[i][j] = 0;
            }
        }
    }

    return tong;
}

int main() {
    int a[20][20];
    int dc[20][20];
    int n;
    int tong;

    printf("Nhap cap ma tran n: ");
    scanf("%d", &n);

    nhap_ma_tran(a, n);

    printf("\nMa tran A:\n");
    xuat_ma_tran(a, n);

    tong = xu_ly_duong_cheo_phu(a, n, dc);

    printf("\nMa tran duong cheo phu voi gia tri nho nhat moi hang:\n");
    xuat_ma_tran(dc, n);

    printf("\nTong cac phan tu nho nhat moi hang = %d\n", tong);

    return 0;
}
/*
Tim phan tu nho nhat tung hang
Dat gia tri do len duong cheo phu (cac vi tri A[i][n-1-i])
Cac vi tri khac gan 0
Tinh tong cua cac gia tri nho nhat moi hang
*/
