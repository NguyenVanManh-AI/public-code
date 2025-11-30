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
            if (n > 0 && n <= 7000000)
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
    int temp = N;

    /* Luu lai cac so cp */
    int cp[100];
    int mu[100];
    int cnt = 0;

    while (temp > 0)
    {
        int sq = so_cp_lon_nhat(temp); // số chính phương lớn nhất
        int k = (int)sqrt(sq);         // lấy số mũ để in dạng k^2

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
- N hap N đảm bảo là số tự nhiên và <= 7 triệu.
- Lặp:
      lấy số chính phương lớn nhất <= N
      trừ dần đến khi về 0
- Lưu lại cả sq = k*k và k để in ra k^2
- In kết quả theo dạng k1^2 + k2^2 + ...
*/
