#include <stdio.h>

/* ham nhap ma tran cap n */
void nhap_ma_tran(double a[][20], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}

/* ham xuat ma tran cap n */
void xuat_ma_tran(double a[][20], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.3lf ", a[i][j]);
        }
        printf("\n");
    }
}

/* ham tim ma tran nghich dao theo phuong phap gauss jordan */
int tim_ma_tran_nghich_dao(double a[][20], double inv[][20], int n) {
    int i, j, k;
    double temp;

    /* khoi tao ma tran don vi */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                inv[i][j] = 1.0;
            } else {
                inv[i][j] = 0.0;
            }
        }
    }

    /* thuc hien bien doi gauss jordan */
    for (i = 0; i < n; i++) {

        /* neu phan tu duong cheo = 0 thi khong the nghich dao */
        if (a[i][i] == 0) {
            return 0;
        }

        /* chia hang i cho a[i][i] */
        temp = a[i][i];
        for (j = 0; j < n; j++) {
            a[i][j] = a[i][j] / temp;
            inv[i][j] = inv[i][j] / temp;
        }

        /* khử cac hang khac */
        for (k = 0; k < n; k++) {
            if (k != i) {
                temp = a[k][i];

                for (j = 0; j < n; j++) {
                    a[k][j] = a[k][j] - temp * a[i][j];
                    inv[k][j] = inv[k][j] - temp * inv[i][j];
                }
            }
        }
    }

    return 1;
}

int main() {
    double a[20][20];
    double inv[20][20];
    int n;
    int ket_qua;

    printf("Nhap cap ma tran n: ");
    scanf("%d", &n);

    nhap_ma_tran(a, n);

    printf("\nMa tran A:\n");
    xuat_ma_tran(a, n);

    ket_qua = tim_ma_tran_nghich_dao(a, inv, n);

    if (ket_qua == 0) {
        printf("\nMa tran khong co nghich dao (det = 0)\n");
    } else {
        printf("\nMa tran nghich dao:\n");
        xuat_ma_tran(inv, n);
    }

    return 0;
}

/*
Su dung phuong phap gauss jordan de tim nghich dao
Lap ma tran don vi I
Thuc hien phep bien doi A → I
Dong thoi bien doi I → A^(-1)
Neu phan tu duong cheo bang 0 thi khong nghich dao
*/
