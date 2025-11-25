#include <stdio.h>

/* ham nhap ma tran mxn */
void nhap_ma_tran(int a[][20], int m, int n) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

/* ham xuat ma tran */
void xuat_ma_tran(int a[][20], int m, int n) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}

/* ham tim phan tu lon nhat tren 1 hang */
int tim_lon_nhat_hang(int a[][20], int hang, int n) {
    int j;
    int max;

    max = a[hang][0];

    for (j = 1; j < n; j++) {
        if (a[hang][j] > max) {
            max = a[hang][j];
        }
    }

    return max;
}

/* ham tinh tong cac gia tri lon nhat tung hang va dua len duong cheo */
int xu_ly_duong_cheo(int a[][20], int m, int n, int dc[][20]) {
    int i, j;
    int tong;
    int max;

    tong = 0;

    /* tao ma tran m x m voi duong cheo la gia tri lon nhat moi hang */
    for (i = 0; i < m; i++) {

        max = tim_lon_nhat_hang(a, i, n);
        tong += max;

        for (j = 0; j < m; j++) {
            if (j == i) {
                dc[i][j] = max;
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
    int m, n;
    int tong;

    printf("Nhap so dong m: ");
    scanf("%d", &m);

    printf("Nhap so cot n: ");
    scanf("%d", &n);

    nhap_ma_tran(a, m, n);

    printf("\nMa tran A:\n");
    xuat_ma_tran(a, m, n);

    tong = xu_ly_duong_cheo(a, m, n, dc);

    printf("\nMa tran duong cheo tu phan tu lon nhat moi hang:\n");
    xuat_ma_tran(dc, m, m);

    printf("\nTong cac phan tu lon nhat moi hang = %d\n", tong);

    return 0;
}
/*
Moi hang tim phan tu lon nhat
Dua phan tu lon nhat do len duong cheo chinh cua ma tran m x m
Cac vi tri khac tren ma tran duong cheo gan 0
Cong tat ca gia tri lon nhat lai
*/
