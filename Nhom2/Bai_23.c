#include <stdio.h>

/* ham tinh a^n */
double tinh_luy_thua(double a, int n) {
    int i;
    double kq;

    kq = 1.0;

    for (i = 0; i < n; i++) {
        kq = kq * a;
    }

    return kq;
}

/* ham tinh tich a(a+1)...(a+n-1) */
double tinh_tich(double a, int n) {
    int i;
    double kq;

    kq = 1.0;

    for (i = 0; i < n; i++) {
        kq = kq * (a + i);
    }

    return kq;
}

/* ham tinh tong 1/a + 1/[a(a+1)] + ... */
double tinh_tong(double a, int n) {
    int i, j;
    double tong;
    double tich;

    tong = 0.0;

    for (i = 0; i <= n; i++) {
        /* tinh tich a(a+1)...(a+i) */
        tich = 1.0;
        for (j = 0; j <= i; j++) {
            tich = tich * (a + j);
        }

        tong = tong + 1.0 / tich;
    }

    return tong;
}

int main() {
    double a;
    int n;

    printf("Nhap a: ");
    scanf("%lf", &a);

    printf("Nhap n: ");
    scanf("%d", &n);

    printf("a^n = %.6lf\n", tinh_luy_thua(a, n));
    printf("Tich a(a+1)...(a+n-1) = %.6lf\n", tinh_tich(a, n));
    printf("Tong day = %.6lf\n", tinh_tong(a, n));

    return 0;
}
