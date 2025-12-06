#include <stdio.h>
#include <ctype.h>

/* Ham nhap so tu nhien, chi chap nhan cac ky tu 0-9, 
   khong cho phep so am, dau cong, dau cham, so thap phan */
long long nhap_so_tu_nhien(const char *ten)
{
    char s[100];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* Kiem tra tung ky tu co phai chu so hay khong */
        for (; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))   // neu ky tu khong phai chu so thi sai
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long x = 0;

            /* Chuyen chuoi so sang so nguyen */
            for (i = 0; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0');  // cong thuc ghep so

            return x; /* so hop le => tra ve */
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham dem so mu cua thua so p trong phan tich cua x
   vi du: x = 40 thi mu cua 2 la 3 (40 = 2^3 * 5) */
long long dem_so_mu(long long x, int p)
{
    long long dem = 0;

    while (x > 0 && x % p == 0)  // lap toi khi x khong chia het cho p
    {
        dem++;       // tang so lan chia het
        x /= p;      // rut gon x
    }
    return dem;
}

int main()
{
    long long n = nhap_so_tu_nhien("so luong phan tu n");  // nhap n

    while (n <= 0)   // kiem tra n phai > 0
    {
        printf("n phai > 0. Nhap lai.\n");
        n = nhap_so_tu_nhien("so luong phan tu n");
    }

    long long A[250];  // mang chua cac so

    printf("\n=== Nhap cac so tu nhien ===\n");

    long long i;        /* bien i dung trong cac vong lap */
    char ten[50];       /* luu ten A[i] khi nhap */

    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%lld]", i);  // tao chuoi "A[0]", "A[1]", ...
        A[i] = nhap_so_tu_nhien(ten);  // nhap tung phan tu
    }

    printf("\n=== Day so vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%lld ", A[i]);   // in mang

    /* Tinh tong so mu cua 2 va so mu cua 5 trong tat ca cac so */
    long long tong_mu2 = 0, tong_mu5 = 0;

    for (i = 0; i < n; i++)
    {
        tong_mu2 += dem_so_mu(A[i], 2);  // dem mu 2
        tong_mu5 += dem_so_mu(A[i], 5);  // dem mu 5
    }

    /* Chu so 0 tan cung phu thuoc vao cap (2,5)
       so chu so 0 = min(tong mu 2, tong mu 5) */
    long long so_0_tan_cung = (tong_mu2 < tong_mu5) ? tong_mu2 : tong_mu5;

    printf("\n\n=== So chu so 0 tan cung cua tich ===\n");
    printf("Ket qua: %lld\n", so_0_tan_cung);

    return 0;
}

/*
Thuat toan xu ly:
input: 99999999 (khong cho nhap 1e9)
1. Nhap n va kiem tra n > 0.
2. Nhap n so tu nhien, chi cho phep ky tu 0-9.
3. Duyet tung phan tu:
      - Dem so lan x chia het cho 2 => cong vao tong_mu2.
      - Dem so lan x chia het cho 5 => cong vao tong_mu5.
4. So luong chu so 0 tan cung cua tich A[0] * A[1] * ... * A[n-1]
   = min(tong_mu2, tong_mu5).
5. In ket qua.

Ly do: Moi cap (2,5) tao ra mot chu so 0 o cuoi tich so.
Vi chi can biet co bao nhieu cap (2,5) , min(tong_mu2, tong_mu5) => so luong chu so 0.
*/
