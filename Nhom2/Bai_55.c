#include <stdio.h>

#define MAX 100

// ham nhap mang
void nhap_mang(int a[], int *n) {
    int i;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// ham xuat mang
void xuat_mang(int a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// ham xoa phan tu co chi so k
int xoa_phan_tu(int a[], int *n, int k) {
    int i;

    // kiem tra chi so k hop le
    if (k < 0 || k >= *n) {
        return 0; // xoa khong thanh cong
    }

    // dich cac phan tu sang trai
    for (i = k; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }

    (*n)--; // giam so luong phan tu
    return 1; // xoa thanh cong
}

int main() {
    int a[MAX];
    int n, k;
    int check;

    nhap_mang(a, &n);

    printf("Nhap chi so k can xoa: ");
    scanf("%d", &k);

    check = xoa_phan_tu(a, &n, k);

    if (check == 1) {
        printf("Mang sau khi xoa:\n");
        xuat_mang(a, n);
    } else {
        printf("Chi so k khong hop le, khong the xoa!\n");
    }

    return 0;
}

/*
- Kiem tra k co hop le: 0 <= k < n
- Neu hop le thi dich cac phan tu tu vi tri k sang trai 1 don vi
- Giam so luong phan tu n di 1
*/
