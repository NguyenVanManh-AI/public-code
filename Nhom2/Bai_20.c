#include <stdio.h>

/* ham tinh tong lap phuong cac chu so cua n */
int tong_lap_phuong(int n) {
    int chuc, dv;
    int tong;

    /* tach chu so */
    chuc = n / 10;
    dv = n % 10;

    /* tinh tong lap phuong */
    tong = chuc * chuc * chuc + dv * dv * dv;

    return tong;
}

/* ham kiem tra n^2 co bang tong lap phuong cac chu so */
int kiem_tra(int n) {
    int binh_phuong;
    int tong;

    binh_phuong = n * n;
    tong = tong_lap_phuong(n);

    if (binh_phuong == tong) {
        return 1;
    }
    return 0;
}

int main() {
    int n;

    printf("Nhap n (n <= 99): ");
    scanf("%d", &n);

    if (kiem_tra(n)) {
        printf("n^2 bang tong lap phuong cac chu so cua n\n");
    } else {
        printf("n^2 khong bang tong lap phuong cac chu so cua n\n");
    }

    return 0;
}
