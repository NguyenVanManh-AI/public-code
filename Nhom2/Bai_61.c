#include <stdio.h>

#define MAX 100

// ham kiem tra so nguyen to
int la_so_nguyen_to(int n) {
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

// ham nhap mang
void nhap_mang(int a[], int *n) {
    int i;

    do {
        printf("Nhap so luong phan tu n (n >= 15): ");
        scanf("%d", n);

        if (*n < 15) {
            printf("n phai lon hon hoac bang 15 !\n");
        }
    } while (*n < 15);

    for (i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// ham xuat mang
void xuat_mang(int a[], int n) {
    int i;

    printf("Mang vua nhap: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// ham tinh tong so nguyen to trong mang
int tong_so_nguyen_to(int a[], int n) {
    int i;
    int tong = 0;

    printf("Cac so nguyen to: ");
    for (i = 0; i < n; i++) {
        if (la_so_nguyen_to(a[i])) {
            printf("%d ", a[i]);
            tong += a[i];
        }
    }
    printf("\n");

    return tong;
}

int main() {
    int a[MAX];
    int n;
    int tong;

    nhap_mang(a, &n);

    xuat_mang(a, n);

    tong = tong_so_nguyen_to(a, n);

    printf("Tong cac so nguyen to trong mang = %d\n", tong);

    return 0;
}

