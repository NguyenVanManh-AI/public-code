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

// ham chen mot phan tu x vao mang b tai vi tri pos
void chen_vao_vi_tri(int b[], int *n_b, int x, int pos) {
    int i;

    // don mang sang phai
    for (i = *n_b; i > pos; i--) {
        b[i] = b[i - 1];
    }

    b[pos] = x;
    *n_b = *n_b + 1;
}

// ham noi A vao B de mang B luon tang dan
void noi_mang_tang_dan(int a[], int n_a, int b[], int *n_b) {
    int i, pos;

    for (i = 0; i < n_a; i++) {
        pos = 0;

        // tim vi tri chen thich hop trong B
        while (pos < *n_b && b[pos] < a[i]) {
            pos++;
        }

        // chen phan tu A[i] vao dung vi tri
        chen_vao_vi_tri(b, n_b, a[i], pos);
    }
}

int main() {
    int a[100], b[200];
    int n_a, n_b;

    printf("Nhap so phan tu mang A: ");
    scanf("%d", &n_a);

    nhap_mang(a, n_a);

    printf("Nhap so phan tu mang B: ");
    scanf("%d", &n_b);

    nhap_mang(b, n_b);

    printf("Mang A: ");
    xuat_mang(a, n_a);

    printf("Mang B: ");
    xuat_mang(b, n_b);

    noi_mang_tang_dan(a, n_a, b, &n_b);

    printf("Mang B sau khi noi A vao va van tang dan: ");
    xuat_mang(b, n_b);

    return 0;
}
/*
Khong dung mang phu lon (chi thao tac trong 1 mang), khong duoc sap xep truoc va sau, ma chi ghep A → B sao cho mang B sau cung van tang dan
Noi A vao B
Ket qua van tang dan
Khong dung mang phu
Khong sap xep lai sau khi noi
*/
