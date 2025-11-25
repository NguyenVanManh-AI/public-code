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
        printf("Nhap so luong phan tu N (N > 0): ");
        scanf("%d", n);

        if (*n <= 0) {
            printf("N phai lon hon 0!\n");
        }
    } while (*n <= 0);

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

// ham tim so nguyen to cuoi cung trong mang
int tim_so_nguyen_to_cuoi(int a[], int n, int *tim_thay) {
    int i;

    *tim_thay = 0;

    for (i = n - 1; i >= 0; i--) {
        if (la_so_nguyen_to(a[i])) {
            *tim_thay = 1;
            return a[i];
        }
    }

    return 0;
}

int main() {
    int a[MAX];
    int n;
    int kq;
    int tim_thay;

    nhap_mang(a, &n);

    xuat_mang(a, n);

    kq = tim_so_nguyen_to_cuoi(a, n, &tim_thay);

    if (tim_thay) {
        printf("So nguyen to cuoi cung trong mang = %d\n", kq);
    } else {
        printf("Khong co so nguyen to trong mang\n");
    }

    return 0;
}

/*
YEU CAU BAI 64

a. Nhap mang 1 chieu A co N phan tu
   - Xuat mang ra man hinh

b. Tim va xuat ra so nguyen to cuoi cung trong mang
   - Neu khong co, in: "Khong co so nguyen to trong mang"

IDEA

- Duyet mang tu cuoi ve dau
- Neu gap so nguyen to dau tien thi dung lai
- Neu khong tim thay thi bao khong co
*/
