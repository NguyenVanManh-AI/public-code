#include <stdio.h>

// ham tao ma tran xoan tu ngoai vao trong
void tao_xoan_ngoai_vao(int a[][100], int n, int m) {
    int top, bottom, left, right;
    int num;

    top = 0;
    bottom = n - 1;
    left = 0;
    right = m - 1;
    num = 1;

    while (top <= bottom && left <= right) {

        // chay hang tren
        int j;
        for (j = left; j <= right; j++) {
            a[top][j] = num++;
        }
        top++;

        // chay cot ben phai
        int i;
        for (i = top; i <= bottom; i++) {
            a[i][right] = num++;
        }
        right--;

        // chay hang duoi
        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                a[bottom][j] = num++;
            }
            bottom--;
        }

        // chay cot ben trai
        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                a[i][left] = num++;
            }
            left++;
        }
    }
}

// ham tao ma tran xoan tu trong ra ngoai
void tao_xoan_trong_ra(int a[][100], int n, int m) {
    int top, bottom, left, right;
    int num;

    top = 0;
    bottom = n - 1;
    left = 0;
    right = m - 1;

    num = n * m; // so lon nhat o tam

    while (top <= bottom && left <= right) {

        // chay hang tren
        int j;
        for (j = left; j <= right; j++) {
            a[top][j] = num--;
        }
        top++;

        // chay cot ben phai
        int i;
        for (i = top; i <= bottom; i++) {
            a[i][right] = num--;
        }
        right--;

        // chay hang duoi
        if (top <= bottom) {
            for (j = right; j >= left; j--) {
                a[bottom][j] = num--;
            }
            bottom--;
        }

        // chay cot ben trai
        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                a[i][left] = num--;
            }
            left++;
        }
    }
}

// ham xuat ma tran
void xuat(int a[][100], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100];
    int n, m;

    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    printf("\nMa tran xoan tu ngoai vao trong:\n");
    tao_xoan_ngoai_vao(a, n, m);
    xuat(a, n, m);

    printf("\nMa tran xoan tu trong ra ngoai:\n");
    tao_xoan_trong_ra(a, n, m);
    xuat(a, n, m);

    return 0;
}
/**
Ngoai -> Trong 
1   2   3   4   5
16  17  18  19   6
15  24  25  20   7
14  23  22  21   8
13  12  11  10   9

Trong -> Ngoai 
25  24  23  22  21
10   9   8   7  20
11   2   1   6  19
12   3   4   5  18
13  14  15  16  17
*/
