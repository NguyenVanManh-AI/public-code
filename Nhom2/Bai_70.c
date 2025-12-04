#include <stdio.h>

#define MAX 100

/* Ham nhap mang so thuc (double) */
void nhapMang(double a[], int *n, const char ten) {
    int i;
    printf("Nhap so phan tu mang %c: ", ten);
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        printf("%c[%d] = ", ten, i);
        scanf("%lf", &a[i]);   /* Cho phep nhap so am, so thap phan, so dang 1e18 */
    }
}

/* Ham xuat mang so thuc */
void xuatMang(double a[], int n, const char ten) {
    int i;
    printf("%c: ", ten);
    for (i = 0; i < n; i++)
        printf("%.6lf ", a[i]);   /* In 6 chu so thap phan */
    printf("\n");
}

/* Ham chen phan tu x vao mang b sao cho mang b tang dan */
void chenTangDan(double b[], int *nB, double x) {
    int i;
    i = *nB - 1;

    /* Day cac phan tu lon hon x sang phai */
    while (i >= 0 && b[i] > x) {
        b[i + 1] = b[i];
        i--;
    }

    /* Chen x vao dung vi tri */
    b[i + 1] = x;
    (*nB)++;
}

/* Ham sap xep chen (insertion sort) tai cho */
void sapXepChenTaiCho(double b[], int nB) {
    int i, j;
    double x;

    for (i = 1; i < nB; i++) {
        x = b[i];
        j = i - 1;

        /* Day cac phan tu lon hon x sang ben phai */
        while (j >= 0 && b[j] > x) {
            b[j + 1] = b[j];
            j--;
        }

        /* Chen x vao dung vi tri */
        b[j + 1] = x;
    }
}

int main() {
    double A[MAX], B[MAX];
    int nA, nB;
    int i;

    /* Nhap mang A va B */
    nhapMang(A, &nA, 'A');
    nhapMang(B, &nB, 'B');

    /* Xuat mang ban dau */
    printf("\n--- MANG BAN DAU ---\n");
    xuatMang(A, nA, 'A');
    xuatMang(B, nB, 'B');

    /* Sap xep mang B tang dan */
    sapXepChenTaiCho(B, nB);

    /* Chen tung phan tu cua A vao B (van giu tang dan) */
    for (i = 0; i < nA; i++) {
        chenTangDan(B, &nB, A[i]);
    }

    /* Xuat ket qua cuoi cung */
    printf("\n--- MANG B SAU KHI NOI A (TANG DAN) ---\n");
    xuatMang(B, nB, 'B');

    return 0;
}
