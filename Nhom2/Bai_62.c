#include <stdio.h>
#include <ctype.h>

/* Hàm nhập số nguyên không cho 2.0, 5.5, +3,... */
long long nhap_so_tu_nhien(const char *ten)
{
    char s[100];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* Không cho phép số âm và ký tự lạ */
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
            for (i = 0; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0');

            return x; /* số tự nhiên */
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Đếm số mũ của 2 hoặc 5 trong phân tích thừa số của x */
long long dem_so_mu(long long x, int p)
{
    long long dem = 0;
    while (x % p == 0 && x > 0)
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
    for (long long i = 0; i < n; i++)
    {
        char ten[50];
        sprintf(ten, "A[%lld]", i);
        A[i] = nhap_so_tu_nhien(ten);
    }

    printf("\n=== Day so vua nhap ===\n");
    for (long long i = 0; i < n; i++)
        printf("%lld ", A[i]);

    /* Tính số 0 tận cùng */
    long long tong_mu2 = 0, tong_mu5 = 0;

    for (long long i = 0; i < n; i++)
    {
        tong_mu2 += dem_so_mu(A[i], 2);
        tong_mu5 += dem_so_mu(A[i], 5);
    }

    long long so_0_tan_cung = (tong_mu2 < tong_mu5) ? tong_mu2 : tong_mu5;

    printf("\n\n=== So chu so 0 tan cung cua tich ===\n");
    printf("Ket qua: %lld\n", so_0_tan_cung);

    return 0;
}
