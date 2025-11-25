#include <stdio.h>

#define MAX 100

// ham nhap mang so tu nhien
void nhap_mang(int a[], int *n) {
    int i;

    do {
        printf("Nhap so luong phan tu n (n > 0): ");
        scanf("%d", n);

        if (*n <= 0) {
            printf("n phai lon hon 0 !\n");
        }
    } while (*n <= 0);

    for (i = 0; i < *n; i++) {
        do {
            printf("a[%d] = ", i);
            scanf("%d", &a[i]);

            if (a[i] < 0) {
                printf("Chi duoc nhap so tu nhien (>= 0) !\n");
            }
        } while (a[i] < 0);
    }
}

// ham dem so luong so 0 tan cung cua tich
int dem_so_0_tan_cung(int a[], int n) {
    int i;
    int dem_2 = 0;
    int dem_5 = 0;
    int temp;

    // dem so lan xuat hien cua 2 va 5 trong cac thua so
    for (i = 0; i < n; i++) {
        temp = a[i];

        while (temp % 2 == 0 && temp != 0) {
            dem_2++;
            temp /= 2;
        }

        while (temp % 5 == 0 && temp != 0) {
            dem_5++;
            temp /= 5;
        }
    }

    // so luong so 0 tan cung la min(dem_2, dem_5)
    if (dem_2 < dem_5)
        return dem_2;
    else
        return dem_5;
}

int main() {
    int a[MAX];
    int n;
    int so_0;

    nhap_mang(a, &n);

    so_0 = dem_so_0_tan_cung(a, n);

    printf("So luong so 0 tan cung cua tich = %d\n", so_0);

    return 0;
}

/*
YEU CAU BAI 62

a. Nhap cac so tu nhien tu ban phim
b. Dem xem tich cac so do co bao nhieu so 0 o tan cung

IDEA

- So 0 tan cung xuat hien do cap (2 * 5)
- Dem so lan xuat hien cua 2 va 5 trong cac thua so
- So 0 tan cung = min(so lan co 2, so lan co 5)
- Khong can tinh truc tiep tich vi so rat lon
*/
