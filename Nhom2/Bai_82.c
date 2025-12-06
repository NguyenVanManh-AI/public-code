#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham nhap chuoi (khong lay dau cach) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten); // thong bao
    scanf("%s", out);         // nhap chuoi
}

/* 
 * Ham kiem tra chuoi co phai so nguyen hay khong
 * Tra ve 1 neu hop le, 0 neu khong
 */
int la_so_nguyen(const char *s)
{
    int i = 0;

    /* Neu co dau tru o dau thi bo qua */
    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    /* Kiem tra tung ky tu */
    for (; s[i]; i++)
        if (!isdigit(s[i]))
            return 0; // khong phai so

    return 1; // hop le
}

/* 
 * Chuyen chuoi so ve kieu long long
 * Tra ve gia tri long long
 */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1; // xac dinh dau
    int i = (s[0] == '-') ? 1 : 0;    // bat dau tu ky tu dau so

    /* Xu ly tung ky tu so */
    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

/* 
 * Ham xuat ma tran n x m
 */
void xuatMat(int a[][100], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%5d ", a[i][j]); // in canh le 5 ky tu
        printf("\n");
    }
}

/* 
 * Tao ma tran xoan tu ngoai vao trong
 * n: so dong, m: so cot
 * a: ma tran dua ra
 */
void xoanNgoaiVao(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1; // gia tri bat dau

    int i, j;

    /* Lap den khi cac bien giao nhau */
    while (top <= bottom && left <= right) {

        /* Di ngang tu trai sang phai */
        for (j = left; j <= right; j++)
            a[top][j] = num++;
        top++;

        /* Di xuong o cot phai */
        for (i = top; i <= bottom; i++)
            a[i][right] = num++;
        right--;

        /* Di ngang tu phai sang trai */
        if (top <= bottom) {
            for (j = right; j >= left; j--)
                a[bottom][j] = num++;
            bottom--;
        }

        /* Di len o cot trai */
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                a[i][left] = num++;
            left++;
        }
    }
}

/* 
 * Tao ma tran xoan tu trong ra ngoai
 * n: so dong, m: so cot
 * a: ma tran dua ra
 */
void xoanTrongRaNgoai(int a[][100], int n, int m) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = n * m; // gia tri bat dau

    int i, j;

    /* Lap den khi cac bien giao nhau */
    while (top <= bottom && left <= right) {

        /* Di ngang tu trai sang phai */
        for (j = left; j <= right; j++)
            a[top][j] = num--;
        top++;

        /* Di xuong o cot phai */
        for (i = top; i <= bottom; i++)
            a[i][right] = num--;
        right--;

        /* Di ngang tu phai sang trai */
        if (top <= bottom) {
            for (j = right; j >= left; j--)
                a[bottom][j] = num--;
            bottom--;
        }

        /* Di len o cot trai */
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                a[i][left] = num--;
            left++;
        }
    }
}

/* --- MAIN --- */
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

    /* Tao va xuat ma tran xoan tu ngoai vao trong */
    printf("\n--- Ma tran xoan tu ngoai vao trong ---\n");
    xoanNgoaiVao(A, n, m);
    xuatMat(A, n, m);

    /* Tao va xuat ma tran xoan tu trong ra ngoai */
    printf("\n--- Ma tran xoan tu trong ra ngoai ---\n");
    xoanTrongRaNgoai(A, n, m);
    xuatMat(A, n, m);

    return 0;
}

/**
 * THUAT TOAN CHUONG TRINH
 * 1. Nhap so dong n va so cot m bang ham nhap_chuoi va chuyen sang so nguyen an toan
 * 2. Tao ma tran A theo hai cach: (Tao ma tran => sau do xuat ma tran)
 *    - xoanNgoaiVao: di tu ngoai vao trong, tang tu 1 den n*m 
        + Di tu Trai sang phai => Tren xuong => Phai sang trai => Duoi len
        + start = 1
 *    - xoanTrongRaNgoai: di tu trong ra ngoai, giam tu n*m den 1 
        + Di tu Trai sang phai => Tren xuong => Phai sang trai => Duoi len
        + Tuong tu , nhung start = m*n 
 * 3. In ma tran vua tao ra man hinh
 *
 * LUU Y
 * - Su dung bien top, bottom, left, right de dieu khien bien gioi han
 * - Su dung bien num de gan gia tri tang/giam
 * - Vong lap ket thuc khi top > bottom hoac left > right
 * - Ma tran toi da 100 x 100
 */
