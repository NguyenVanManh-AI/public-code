#include <stdio.h>

/* ham tinh tong cac so nguyen nhap vao cho den khi gap 0 */
int tinh_tong() {
    int tong;
    int x;

    tong = 0;

    while (1) {
        printf("Nhap so (0 de dung): ");
        scanf("%d", &x);

        if (x == 0) {
            break;
        }

        tong = tong + x;
    }

    return tong;
}

int main() {
    int kq;

    kq = tinh_tong();

    printf("Tong cac so da nhap = %d\n", kq);

    return 0;
}
