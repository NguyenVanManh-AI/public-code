#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham nhap chuoi */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai so nguyen */
int la_so_nguyen(const char *s)
{
    int i = 0;
    if (s[0] == '-' && s[1] != '\0') i = 1;
    for (; s[i]; i++)
        if (!isdigit(s[i])) return 0;
    return 1;
}

/* Chuyen chuoi thanh so long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

void nhapMaTran(double a[][50], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
}

void xuatMaTran(double a[][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%15.3lf ", a[i][j]);
        printf("\n");
    }
}

double timMaxDong(double a[][50], int n, int dong) {
    double max = a[dong][0];
    for (int j = 1; j < n; j++)
        if (a[dong][j] > max)
            max = a[dong][j];
    return max;
}

int main() {
    int n = 0;
    char buf[100];

    while (1)
    {
        nhap_chuoi("n (n > 0)", buf);

        if (la_so_nguyen(buf)) {
            n = (int)to_ll(buf);
            if (n > 0 && n <= 50) break;
        }

        printf("n phai la so nguyen duong. Nhap lai!\n");
    }

    double A[50][50];

    // Nhap ma tran
    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    // Xuat ma tran ban dau
    printf("\nMa tran A vua nhap:\n");
    xuatMaTran(A, n);

    double sum = 0;

    // Dua max moi hang len duong cheo chinh
    for (int i = 0; i < n; i++) {
        double maxVal = timMaxDong(A, n, i);
        A[i][i] = maxVal;
        sum += maxVal;
    }

    // Xuat ma tran sau khi xu ly
    printf("\nMa tran sau khi dua max tung hang len duong cheo chinh:\n");
    xuatMaTran(A, n);

    // Tong
    printf("\nTong cac phan tu lon nhat duoc dua len duong cheo = %.3lf\n", sum);

    return 0;
}
