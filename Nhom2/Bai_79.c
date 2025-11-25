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

/* ham xuat ma tran */
void xuat_ma_tran(int a[][20], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }
}

/* ham tim lon nhat tren 1 hang */
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

/* ham tao ma tran duong cheo chinh voi max moi hang */
int xu_ly_duong_cheo(int a[][20], int n, int dc[][20]) {
    int i, j;
    int max;
    int tong;

    tong = 0;

    for (i = 0; i < n; i++) {
        max = tim_lon_nhat_hang(a, i, n);
        tong += max;

        for (j = 0; j < n; j++) {
            if (j == i) {
                dc[i][j] = max;   /* dua max len duong cheo chinh */
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

    tong = xu_ly_duong_cheo(a, n, dc);

    printf("\nMa tran duong cheo chinh voi gia tri lon nhat moi hang:\n");
    xuat_ma_tran(dc, n);

    printf("\nTong cac phan tu lon nhat moi hang = %d\n", tong);

    return 0;
}
/*
Tim phan tu lon nhat cua tung hang
Dua no len duong cheo chinh
Gan cac phan tu khac = 0
Tinh tong cac gia tri lon nhat do
*/
