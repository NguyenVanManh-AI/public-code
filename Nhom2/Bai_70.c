#include <stdio.h>

#define MAX 100

/* Ham nhap mang so thuc (double) */
void nhapMang(double a[], int *n, const char ten) {
    printf("Nhap so phan tu mang %c: ", ten);
    scanf("%d", n);   // nhap so luong phan tu

    for (int i = 0; i < *n; i++) {
        printf("%c[%d] = ", ten, i);
        scanf("%lf", &a[i]);   // nhap gia tri kieu double: am, so thap phan, 1e18
    }
}

/* Ham xuat mang so thuc */
void xuatMang(double a[], int n, const char ten) {
    printf("%c: ", ten);
    for (int i = 0; i < n; i++)
        printf("%.6lf ", a[i]);    // in ra 6 chu so thap phan
    printf("\n");
}

/* Ham chen phan tu x vao mang b sao cho mang b tang dan */
void chenTangDan(double b[], int *nB, double x) {
    int i = *nB - 1;

    // day cac phan tu lon hon x sang ben phai
    while (i >= 0 && b[i] > x) {
        b[i + 1] = b[i];
        i--;
    }

    // chen x vao dung vi tri
    b[i + 1] = x;
    (*nB)++; // tang so luong phan tu cua B
}

/* Ham sap xep chen (insertion sort) tai cho */
void sapXepChenTaiCho(double b[], int nB) {
    for (int i = 1; i < nB; i++) {
        double x = b[i];    // phan tu can chen
        int j = i - 1;

        // day cac phan tu lon hon x sang phai
        while (j >= 0 && b[j] > x) {
            b[j + 1] = b[j];
            j--;
        }

        // chen x vao dung vi tri
        b[j + 1] = x;
    }
}

int main() {
    double A[MAX], B[MAX];
    int nA, nB;

    // nhap mang A va B
    nhapMang(A, &nA, 'A');
    nhapMang(B, &nB, 'B');

    // in mang ban dau
    printf("\n--- MANG BAN DAU ---\n");
    xuatMang(A, nA, 'A');
    xuatMang(B, nB, 'B');

    // sap xep B theo thu tu tang dan
    sapXepChenTaiCho(B, nB);

    // noi tung phan tu cua A vao B theo thu tu tang dan
    for (int i = 0; i < nA; i++) {
        chenTangDan(B, &nB, A[i]);
    }

    // in ket qua cuoi cung
    printf("\n--- MANG B SAU KHI NOI A (TANG DAN) ---\n");
    xuatMang(B, nB, 'B');

    return 0;
}
