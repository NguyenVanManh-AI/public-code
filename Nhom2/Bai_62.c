#include <stdio.h>
#include <ctype.h>

/* Ham nhap so nguyen khong cho phep 2.0, 5.5, +3, -4,... */
long long nhap_so_tu_nhien(const char *ten)
{
    char s[100];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* Khong cho ky tu la va dau am */
        for (; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long x = 0;

            /* Chuyen chuoi sang so */
            for (i = 0; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0');

            return x; /* so tu nhien */
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham dem so mu cua thua so p trong phan tich cua x */
long long dem_so_mu(long long x, int p)
{
    long long dem = 0;

    while (x > 0 && x % p == 0)
    {
        dem++;
        x /= p;
    }
    return dem;
}

int main()
{
    long long n = nhap_so_tu_nhien("so luong phan tu n");

    while (n <= 0)
    {
        printf("n phai > 0. Nhap lai.\n");
        n = nhap_so_tu_nhien("so luong phan tu n");
    }

    long long A[250];

    printf("\n=== Nhap cac so tu nhien ===\n");

    long long i;   /* Khai bao ben ngoai for */
    char ten[50];  /* Khai bao ben ngoai for */

    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%lld]", i);
        A[i] = nhap_so_tu_nhien(ten);
    }

    printf("\n=== Day so vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%lld ", A[i]);

    /* Tinh tong so mu cua 2 va 5 */
    long long tong_mu2 = 0, tong_mu5 = 0;

    for (i = 0; i < n; i++)
    {
        tong_mu2 += dem_so_mu(A[i], 2);
        tong_mu5 += dem_so_mu(A[i], 5);
    }

    /* So chu so 0 tan cung = min(tong mu 2, tong mu 5) */
    long long so_0_tan_cung = (tong_mu2 < tong_mu5) ? tong_mu2 : tong_mu5;

    printf("\n\n=== So chu so 0 tan cung cua tich ===\n");
    printf("Ket qua: %lld\n", so_0_tan_cung);

    return 0;
}
