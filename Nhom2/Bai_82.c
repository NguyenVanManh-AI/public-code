#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham nhap chuoi (khong lay dau cach) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Ham kiem tra chuoi co phai so nguyen hay khong */
int la_so_nguyen(const char *s)
{
    int i = 0;

    /* Neu co dau tru o dau thi bo qua vi tri do */
    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    /* Kiem tra tung ky tu */
    for (; s[i]; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

/* Chuyen chuoi so ve kieu long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    /* Xu ly tung ky tu so */
    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

/* Ham xuat ma tran */
void xuatMat(int a[][100], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
}

/* Tao ma tran xoan tu ngoai vao trong */
void xoanNgoaiVao(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    int i, j;

    /* Lap den khi cac bien gioi han giao nhau */
    while (top <= bottom && left <= right) {

        /* Di ngang tu trai sang phai */
        for (j = left; j <= right; j++)
            a[top][j] = num++;
        top++;

        /* Di xuong duoi o cot right */
        for (i = top; i <= bottom; i++)
            a[i][right] = num++;
        right--;

        /* Di ngang tu phai sang trai */
        if (top <= bottom) {
            for (j = right; j >= left; j--)
                a[bottom][j] = num++;
            bottom--;
        }

        /* Di len tren o cot left */
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                a[i][left] = num++;
            left++;
        }
    }
}

/* Tao ma tran xoan tu trong ra ngoai */
void xoanTrongRaNgoai(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = n * m;

    int i, j;

    /* Lap nguoc so, di tu trong ra ngoai */
    while (top <= bottom && left <= right) {

        for (j = left; j <= right; j++)
            a[top][j] = num--;
        top++;

        for (i = top; i <= bottom; i++)
            a[i][right] = num--;
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--)
                a[bottom][j] = num--;
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--)
                a[i][left] = num--;
            left++;
        }
    }
}

int main() {
    int n = 0, m = 0;
    char buf[100];
    int A[100][100];

    /* Nhap so dong n */
    while (1)
    {
        nhap_chuoi("so dong n", buf);

        if (la_so_nguyen(buf)) {
            n = (int)to_ll(buf);
            if (n > 0 && n <= 100) break;
        }

        printf("n phai la so nguyen duong. Nhap lai.\n");
    }

    /* Nhap so cot m */
    while (1)
    {
        nhap_chuoi("so cot m", buf);

        if (la_so_nguyen(buf)) {
            m = (int)to_ll(buf);
            if (m > 0 && m <= 100) break;
        }

        printf("m phai la so nguyen duong. Nhap lai.\n");
    }

    printf("\n--- Ma tran xoan tu ngoai vao trong ---\n");
    xoanNgoaiVao(A, n, m);
    xuatMat(A, n, m);

    printf("\n--- Ma tran xoan tu trong ra ngoai ---\n");
    xoanTrongRaNgoai(A, n, m);
    xuatMat(A, n, m);

    return 0;
}
