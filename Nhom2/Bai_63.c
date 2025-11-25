#include <stdio.h>
#include <math.h>

#define MAX 100

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

// ham kiem tra so chinh phuong
int la_so_chinh_phuong(int n) {
    int can_bac_2;

    if (n < 0)
        return 0;

    can_bac_2 = (int)sqrt(n);

    if (can_bac_2 * can_bac_2 == n)
        return 1;
    else
        return 0;
}

// ham xuat so chinh phuong va tinh tong
int tong_so_chinh_phuong(int a[], int n) {
    int i;
    int tong = 0;
    int dem = 0;

    printf("Cac so chinh phuong trong mang: ");

    for (i = 0; i < n; i++) {
        if (la_so_chinh_phuong(a[i])) {
            printf("%d ", a[i]);
            tong += a[i];
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so chinh phuong nao");
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

    tong = tong_so_chinh_phuong(a, n);

    printf("Tong cac so chinh phuong = %d\n", tong);

    return 0;
}

/*
YEU CAU BAI 63

a. Nhap mang 1 chieu A co N phan tu
   - Xuat mang ra man hinh

b. Xuat ra cac so chinh phuong trong mang
   - Tinh tong cac so do

IDEA

- So chinh phuong: la so co can bac 2 la so nguyen
- Dung sqrt() de kiem tra
- Duyet mang, neu la so chinh phuong thi in va cong vao tong
*/
