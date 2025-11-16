#include <stdio.h>
#include <math.h>

int soNguyenTo(long long int n) {
    if (n < 2) return 0;            // 0 và 1 khong phai la so nguyen to
    if (n == 2) return 1;           // 2 la so nguyen to chan duy nhat
    if (n % 2 == 0) return 0;       // loai bo cac so chan khac 2

	long long int i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void program() {
    long long int i, n = 1000000;
    printf("Cac so nguyen to tu 2 den %lld la:\n", n);
    for (i = 2; i <= n; i++) {
        if (soNguyenTo(i))
            printf("%lld\n", i);
    }
}

int main() {
    program();
    printf("\n---------\n");
    return 0;
}

