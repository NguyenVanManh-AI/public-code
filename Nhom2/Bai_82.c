#include <stdio.h>

void xuatMat(int a[][100], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
}

// a. Tạo ma trận xoắn từ ngoài vào trong
void xoanNgoaiVao(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) a[top][j] = num++;
        top++;

        for (int i = top; i <= bottom; i++) a[i][right] = num++;
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) a[bottom][j] = num++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) a[i][left] = num++;
            left++;
        }
    }
}

// b. Tạo ma trận xoắn từ trong ra ngoài
void xoanTrongRaNgoai(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int num = n * m;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) a[top][j] = num--;
        top++;

        for (int i = top; i <= bottom; i++) a[i][right] = num--;
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) a[bottom][j] = num--;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) a[i][left] = num--;
            left++;
        }
    }
}

int main() {
    int n, m;
    int A[100][100];

    do {
        printf("Nhap so dong n > 0: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Nhap so cot m > 0: ");
        scanf("%d", &m);
    } while (m <= 0);

    printf("\n--- Ma tran xoan tu ngoai vao trong ---\n");
    xoanNgoaiVao(A, n, m);
    xuatMat(A, n, m);

    printf("\n--- Ma tran xoan tu trong ra ngoai ---\n");
    xoanTrongRaNgoai(A, n, m);
    xuatMat(A, n, m);

    return 0;
}
