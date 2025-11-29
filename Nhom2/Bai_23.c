#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Ham nhap so thuc (cho a) */
double nhap_so_thuc(const char *ten)
{
    double x;
    while (1)
    {
        printf("Nhap %s: ", ten);
        if (scanf("%lf", &x) == 1)
            return x;

        printf("Gia tri khong hop le. Nhap lai.\n");
        while (getchar() != '\n');
    }
}

/* Ham nhap so tu nhien NGHIEM NGAT (khong cho phep 2.0, 3.0, ...) */
int nhap_so_tu_nhien(const char *ten)
{
    char s[100];
    int i;

    while (1)
    {
        int hop_le = 1;

        printf("Nhap %s: ", ten);
        scanf("%s", s);

        /* Kiem tra chuoi co chi gom chu so hay khong */
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)  /* Chuoi hop le => chuyen sang int */
        {
            int n = 0;
            for (i = 0; s[i] != '\0'; i++)
                n = n * 10 + (s[i] - '0');

            return n; /* n la so tu nhien */
        }

        printf("Gia tri n phai la so tu nhien (khong dau cham, khong thap phan!). Nhap lai.\n");
    }
}

/* Tinh a^n */
double tinh_mu(double a, int n)
{
    int i;
    double kq = 1;

    for (i = 0; i < n; i++)
        kq *= a;

    return kq;
}

/* Tinh tich a(a+1)...(a+n-1) */
double tinh_tich(double a, int n)
{
    int i;
    double kq = 1;

    for (i = 0; i < n; i++)
        kq *= (a + i);

    return kq;
}

/* Tinh tong 1/a + 1/[a(a+1)] + ... */
double tinh_tong(double a, int n, int *loi)
{
    int i;
    double tich = 1;
    double tong = 0;

    if (a == 0)
    {
        *loi = 1; /* loi chia 0 */
        return 0;
    }

    *loi = 0;

    for (i = 0; i <= n; i++)
    {
        if (i > 0)
            tich *= (a + i - 1);

        if (tich == 0)
        {
            *loi = 1;
            return 0;
        }

        tong += 1.0 / tich;
    }

    return tong;
}

int main(void)
{
    double a = nhap_so_thuc("a"); /* a la so thuc */
    int n = nhap_so_tu_nhien("n"); /* n la so tu nhien NGHIEM NGAT */

    printf("\n=== Ket qua ===\n");

    printf("a) a^n = %lf\n", tinh_mu(a, n));
    printf("b) Tich = %lf\n", tinh_tich(a, n));

    int loi;
    double tong = tinh_tong(a, n, &loi);

    if (loi)
        printf("c) Khong the tinh (do chia 0)\n");
    else
        printf("c) Tong = %lf\n", tong);

    return 0;
}

/*
Thuat toan:
- Ham nhap a: nhap so thuc (double).
- Ham nhap n: nhap so tu nhien NGHIEM NGAT, chi chap nhan cac ky tu '0'..'9'.
  => Cac gia tri nhu 2.0, 3.0, 001, -2, 5.1 deu bi tu choi.
- Tinh lan luot:
    + a^n
    + a(a+1)...(a+n-1)
    + 1/a + 1/[a(a+1)] + ...
- Xu li chia 0 trong cau C
*/
