#include <stdio.h>

// ham nhap mang
void nhap_mang(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
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

// ham xoa cac phan tu am
// tra ve so luong phan tu moi sau khi xoa
int xoa_phan_tu_am(int a[], int n) {
    int i, j;

    j = 0; // j la chi so cho mang moi

    for (i = 0; i < n; i++) {
        if (a[i] >= 0) {
            a[j] = a[i]; // giu lai cac phan tu khong am
            j++;
        }
    }

    return j; // so phan tu moi
}

int main() {
    int a[100];
    int n;
    int n_moi;

    printf("Nhap so phan tu n: ");
    scanf("%d", &n);

    nhap_mang(a, n);

    printf("Mang vua nhap: ");
    xuat_mang(a, n);

    n_moi = xoa_phan_tu_am(a, n);

    printf("Mang sau khi xoa cac phan tu am: ");
    xuat_mang(a, n_moi);

    return 0;
}
