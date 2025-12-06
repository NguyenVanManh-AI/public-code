#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50 // kich thuoc toi da cua ma tran

void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten); // thong bao
    scanf("%s", out);         // nhap chuoi
}

/* 
 * Kiem tra chuoi co phai so nguyen hay khong
 * Tra ve 1 neu la so nguyen, 0 neu khong
 */
int la_so_nguyen(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1; /* bo qua dau tru neu co */

    for (; s[i]; i++)
        if (!isdigit(s[i]))
            return 0; /* ky tu khong phai so */

    return 1; // hop le
}

/* 
 * Chuyen chuoi sang so long long
 * Tra ve gia tri so nguyen
 */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1; // xac dinh dau
    int i = (s[0] == '-') ? 1 : 0;    // bat dau tu ky tu dau so

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0'); // cong don tung chu so

    return dau * x;
}

/* 
 * Ham nhap ma tran vuong n x n
 */
void nhapMaTran(double a[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i + 1, j + 1); // thong bao vi tri nhap
            scanf("%lf", &a[i][j]);               // nhap phan tu
        }
}

/* 
 * Ham xuat ma tran n x n
 */
void xuatMaTran(double a[][MAX], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%15.3lf ", a[i][j]); // in canh le 15 ky tu, 3 chu so thap phan
        printf("\n");
    }
}

/* 
 * Tim phan tu lon nhat tren 1 dong
 * dong: chi so dong can tim
 * Tra ve gia tri lon nhat
 */
double timMaxDong(double a[][MAX], int n, int dong)
{
    double max = a[dong][0]; // khoi tao max
    int j;

    for (j = 1; j < n; j++)
        if (a[dong][j] > max)
            max = a[dong][j]; // cap nhat max neu lon hon

    return max;
}

/* --- MAIN --- */
int main()
{
    int n = 0;
    char buf[100];
    double A[MAX][MAX];
    double sum = 0;
    int i;

    /* Nhap n theo cach an toan */
    while (1)
    {
        nhap_chuoi("n (n > 0)", buf); // nhap bang chuoi

        if (la_so_nguyen(buf))
        {
            n = (int)to_ll(buf); // chuyen sang so nguyen
            if (n > 0 && n <= MAX)
                break; // hop le thi dung vong lap
        }

        printf("n phai la so nguyen duong. Nhap lai!\n");
    }

    /* Nhap ma tran A */
    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    /* Xuat ma tran vua nhap */
    printf("\nMa tran A vua nhap:\n");
    xuatMaTran(A, n);

    /* Dua max tung hang len duong cheo chinh */
    for (i = 0; i < n; i++)
    {
        double maxVal = timMaxDong(A, n, i); // tim max tren dong i
        A[i][i] = maxVal;                    // gan len duong cheo chinh
        sum += maxVal;                        // cong vao tong
    }

    /* Xuat ket qua */
    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMaTran(A, n);

    printf("\nTong cac phan tu lon nhat duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}

/**
 * THUAT TOAN CHUONG TRINH
 * 1. Nhap n bang ham nhap_chuoi va chuyen sang so nguyen an toan
 * 2. Nhap ma tran vuong A n x n
 * 3. In ma tran vua nhap
 * 4. Duyet tung dong i:
 *      - Tim phan tu lon nhat tren dong i
 *      - Gan phan tu lon nhat len duong cheo chinh A[i][i]
 *      - Cong phan tu vao tong sum
 * 5. In ma tran sau khi dua max len duong cheo chinh
 * 6. In tong cac gia tri duoc dua len duong cheo
 *
 * LUU Y
 * - Khong doi cac phan tu khac tren dong, chi gan len duong cheo
 * - Su dung double de luu gia tri thap phan
 * - Su dung MAX = 50 gioi han kich thuoc ma tran
 */
