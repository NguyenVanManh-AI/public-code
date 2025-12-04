#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* Ham nhap N la so tu nhien NGHIEM NGAT, khong cho phep 2.0, 3.0, ... */
int nhap_n()
{
    char s[100];
    int i;

    while (1)
    {
        int hop_le = 1;

        printf("Nhap N (N <= 7000000): ");
        scanf("%s", s);

        /* Kiem tra chuoi chi gom chu so */
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))   // phat hien ky tu khong phai chu so
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long n = 0;

            /* Chuyen chuoi sang so */
            for (i = 0; s[i] != '\0'; i++)
                n = n * 10 + (s[i] - '0');

            /* Kiem tra pham vi */
            if (n >= 0 && n <= 7000000)
                return (int)n;
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Tim so chinh phuong lon nhat <= x */
int so_cp_lon_nhat(int x)
{
    int k = (int)sqrt(x);
    return k * k;
}

int main()
{
    int N = nhap_n();

    /* Xu ly rieng cho truong hop N = 0 */
    if (N == 0)
    {
        printf("0 = 0^2\n");
        return 0;
    }

    int temp = N;

    /* Luu lai cac so chinh phuong */
    int cp[100];
    int mu[100];
    int cnt = 0;

    while (temp > 0)
    {
        int sq = so_cp_lon_nhat(temp); // so chinh phuong lon nhat
        int k = (int)sqrt(sq);         // lay so mu de in dang k^2

        cp[cnt] = sq;
        mu[cnt] = k;
        cnt++;

        temp -= sq;
    }

    /* In ket qua */
    printf("%d = ", N);

    int i;
    for (i = 0; i < cnt; i++)
    {
        printf("%d^2", mu[i]);
        if (i < cnt - 1) printf(" + ");
    }

    printf("\n");

    return 0;
}

/*
Thuat toan:
- N la so tu nhien va <= 7 trieu.
- Lap:
      lay so chinh phuong lon nhat <= N
      tru dan den khi ve 0
- Luu lai ca sq = k*k va k de in ra k^2
- In ket qua theo dang k1^2 + k2^2 + ...
*/
