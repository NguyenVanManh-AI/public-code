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

// ham kiem tra so hoan hao
int la_so_hoan_hao(int n) {
    int i;
    int tong = 0;

    if (n <= 0)
        return 0;

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }

    if (tong == n)
        return 1;
    else
        return 0;
}

// ham xuat cac so hoan hao trong mang
void xuat_so_hoan_hao(int a[], int n) {
    int i;
    int dem = 0;

    printf("Cac so hoan hao trong mang: ");

    for (i = 0; i < n; i++) {
        if (la_so_hoan_hao(a[i]) == 1) {
            printf("%d ", a[i]);
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so hoan hao nao");
    }

    printf("\n");
}

int main() {
    int a[MAX];
    int n;

    nhap_mang(a, &n);

    printf("Mang vua nhap:\n");
    xuat_mang(a, n);

    xuat_so_hoan_hao(a, n);

    return 0;
}

/*
b. So hoan hao:
   - La so nguyen duong
   - Bang tong cac uoc thuc su cua no (khong ke chinh no)
   - Vi du: 6 = 1 + 2 + 3
*/