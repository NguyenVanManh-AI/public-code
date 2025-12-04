#include <stdio.h>

#define MAX 100

void nhapMang(int a[], int *n, const char ten) {
    printf("Nhap so phan tu mang %c: ", ten);
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("%c[%d] = ", ten, i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n, const char ten) {
    printf("%c: ", ten);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Chèn x vào b sao cho b tăng dần (KHÔNG dùng mảng phụ) */
void chenTangDan(int b[], int *nB, int x) {
    int i = *nB - 1;
    while (i >= 0 && b[i] > x) {
        b[i + 1] = b[i];  // dời sang phải
        i--;
    }
    b[i + 1] = x;
    (*nB)++;
}

/* Sắp xếp lại B theo kiểu chèn dần (KHÔNG dùng mảng phụ) */
void sapXepChenTaiCho(int b[], int nB) {
    for (int i = 1; i < nB; i++) {
        int x = b[i];
        int j = i - 1;

        while (j >= 0 && b[j] > x) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = x;
    }
}

int main() {
    int A[MAX], B[MAX];
    int nA, nB;

    nhapMang(A, &nA, 'A');
    nhapMang(B, &nB, 'B');

    printf("\n--- MANG BAN DAU ---\n");
    xuatMang(A, nA, 'A');
    xuatMang(B, nB, 'B');

    /* Sắp xếp B theo thứ tự tăng dần, nhưng dùng đúng insertion sort tại chỗ */
    sapXepChenTaiCho(B, nB);

    /* Nối A vào B */
    for (int i = 0; i < nA; i++) {
        chenTangDan(B, &nB, A[i]);
    }

    printf("\n--- MANG B SAU KHI NOI A (TANG DAN) ---\n");
    xuatMang(B, nB, 'B');

    return 0;
}
