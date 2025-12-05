#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ham nhap so thuc cho bien a */
/* scanf("%lf") de bat duoc cac so thuc nhu 2.5, -3.2, 1e10 */
double nhap_so_thuc(const char *ten)
{
    double x;
    while (1)
    {
        printf("Nhap %s: ", ten);

        /* scanf tra ve 1 neu nhap thanh cong 1 so double */
        if (scanf("%lf", &x) == 1)
            return x;

        printf("Gia tri khong hop le. Nhap lai.\n");

        /* xoa cac ky tu con lai trong bo dem */
        while (getchar() != '\n');
    }
}

/* ham nhap so tu nhien NGHIEM NGAT */
/* chi chap nhan cac ky tu 0..9 */
/* tu choi cac gia tri: 2.0 , 3.00 , -4 , +5 , 01 , 1e3 , 5.1 */
int nhap_so_tu_nhien(const char *ten)
{
    char s[100];
    int i;

    while (1)
    {
        int hop_le = 1;

        printf("Nhap %s: ", ten);
        scanf("%s", s);

        /* kiem tra tung ky tu trong chuoi co phai chu so hay khong */
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i])) // <ctype.h>
            {
                hop_le = 0;
                break;
            }
        }

        /* neu chuoi chi toan chu so -> chuyen sang so nguyen */
        if (hop_le)
        {
            int n = 0;

            /* tu so '5' chuyen sang 5, '3' sang 3 */
            for (i = 0; s[i] != '\0'; i++)
                n = n * 10 + (s[i] - '0');

            return n; /* n la so tu nhien hop le */
        }

        printf("Gia tri n phai la so tu nhien (khong dau cham, khong thap phan!). Nhap lai.\n");
    }
}

/* ham tinh a^n bang vong lap */
/* khong dung pow de tranh sai so floating point */
double tinh_mu(double a, int n)
{
    int i;
    double kq = 1;

    for (i = 0; i < n; i++)
        kq *= a;

    return kq;
}

/* ham tinh tich a(a+1)(a+2)...(a+n-1) */
double tinh_tich(double a, int n)
{
    int i;
    double kq = 1;

    for (i = 0; i < n; i++)
        kq *= (a + i);

    return kq;
}

/* ham tinh tong: 1/a + 1/[a(a+1)] + ... + 1/[a(a+1)...(a+n)] */
/* loi = 1 neu bi chia cho 0 */
double tinh_tong(double a, int n, int *loi)
{
    int i;
    double tich;
    double tong;

    /* kiem tra truong hop chia 0 ngay o buoc dau */
    if (a == 0)
    {
        *loi = 1;
        return 0;
    }

    /* khoi tao */
    *loi = 0;
    tich = a;
    tong = 1.0 / a;

    /* tinh cac so hang tiep theo */
    for (i = 1; i <= n; i++)
    {
        /* neu gap a + i = 0 thi sau do bi chia 0 */
        if (a + i == 0)
        {
            *loi = 1;
            return 0;
        }

        /* nhan tich dung theo cong thuc: a(a+1)(a+2)... */
        tich *= (a + i);

        /* cong vao tong */
        tong += 1.0 / tich;
    }

    return tong;
}

int main(void)
{
    /* a la so thuc, n la so tu nhien nghiem ngat */
    double a = nhap_so_thuc("a");
    int n = nhap_so_tu_nhien("n");

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
- Nhap a la so thuc dung scanf("%lf") // 1e6 , 1e18 ,...
- Nhap n la so tu nhien nghiem ngat, chi gom ky tu 0..9 // 10, 1000000000, 9999999999 
- Tinh lan luot:
  + a^n bang vong lap
  + tich a(a+1)...(a+n-1)
  + tong 1/a + 1/[a(a+1)] + ...
- Xu ly chia 0 bang bien "loi"
*/
