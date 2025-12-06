#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* Ham nhap N la so tu nhien NGHIEM NGAT */
/* Khong chap nhan kieu 2.0, 3.0, 5.00 */
/* Chi chap nhan chuoi toan ky tu so */
int nhap_n()
{
    char s[100];   // mang luu chuoi nhap vao
    int i;

    while (1)
    {
        int hop_le = 1;  // gia su chuoi hop le

        printf("Nhap N (N <= 7000000): ");
        scanf("%s", s);  // nhap dang chuoi, tranh nhap so thuc

        /* Kiem tra tung ky tu trong chuoi */
        for (i = 0; s[i] != '\0'; i++)
        {
            // isdigit kiem tra ky tu co phai so tu '0'..'9'
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long n = 0;

            /* Chuyen tu chuoi sang so nguyen */
            for (i = 0; s[i] != '\0'; i++)
                n = n * 10 + (s[i] - '0');

            /* Kiem tra n trong pham vi */
            if (n >= 0 && n <= 7000000)
                return (int)n;
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham tim so chinh phuong lon nhat <= x */
/* Lay can bac 2 cua x => k */
/* So chinh phuong = k*k */
int so_cp_lon_nhat(int x)
{
    int k = (int)sqrt(x); // lay phan nguyen cua sqrt
    return k * k;         // tra ve k binh phuong
}

int main()
{
    int N = nhap_n();  // nhap so N hop le

    /* Xu ly truong hop N = 0 rieng */
    if (N == 0)
    {
        printf("0 = 0^2\n");
        return 0;
    }

    int temp = N;  // bien tam de tru dan

    int cp[100];   // luu cac so chinh phuong
    int mu[100];   // luu mu k tuong ung k^2
    int cnt = 0;   // dem so phan tu luu duoc

    /* Tach N thanh tong cac so chinh phuong */
    while (temp > 0)
    {
        int sq = so_cp_lon_nhat(temp); // so chinh phuong lon nhat <= temp
        int k = (int)sqrt(sq);         // tim k de in ra dang k^2

        cp[cnt] = sq;   // luu so chinh phuong
        mu[cnt] = k;    // luu mu k
        cnt++;

        temp -= sq;     // tru so chinh phuong vua tim
    }

    /* In ket qua: N = k1^2 + k2^2 + ... */
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

- N nhap vao phai la so tu nhien dang chuoi, khong chua ky tu khac
  va khong chua dau cham thap phan.

- Lap:
      + Tim so chinh phuong lon nhat <= temp
      + Luu lai k va k^2 (sq)
      + Tru temp -= sq
      + Lap den khi temp = 0

- Cuoi cung in theo dang:
      k1^2 + k2^2 + ...
*/
