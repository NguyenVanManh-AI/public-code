#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Ham nhap chuoi giu nguyen ky tu nguoi dung nhap (ke ca dau +, -, chu, so...) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);  // doc ca xau khong khoang trang
}

/* Kiem tra chuoi co phai so nguyen hop le (co the co dau '-' o dau, khong co dau '.') */
int la_so_nguyen(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')   // cho phep so am
        i = 1;

    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))           // neu ky tu nao khong phai chu so => sai
            return 0;

    return 1; // hop le
}

/* Chuyen tu chuoi so nguyen sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;  // xac dinh dau
    int i = (s[0] == '-') ? 1 : 0;     // neu co dau thi bo qua

    for (; s[i] != '\0'; i++)
        x = x * 10 + (s[i] - '0');     // ghep so

    return dau * x;
}

/* Kiem tra so chinh phuong (so co can bac 2 la so nguyen) */
int la_chinh_phuong(long long x)
{
    if (x < 0)
        return 0;   // so am khong the la chinh phuong

    long long t = (long long)(sqrt((long double)x) + 0.5); // lam tron tranh sai so float

    return (t * t == x);
}

int main()
{
    int n = 0;
    char buf[100];
    int i;             /* khai bao bien i dung chung cho cac vong lap */
    char ten[50];      /* luu ten A[i] de hien thi khi nhap */

    /* Nhap n sao cho n la so nguyen duong */
    while (1)
    {
        nhap_chuoi("so luong phan tu n", buf);

        if (la_so_nguyen(buf))       // kiem tra n co phai so nguyen
        {
            n = (int)to_ll(buf);
            if (n > 0)               // n phai > 0
                break;
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n");
    }

    char A[300][100];   // mang luu cac phan tu duoi dang chuoi

    printf("\n=== Nhap cac phan tu cua mang A ===\n");

    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%d]", i);   // tao chuoi ten phan tu
        nhap_chuoi(ten, A[i]);      // nhap xau A[i]
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%s ", A[i]);

    printf("\n\n=== Cac so chinh phuong trong mang ===\n");

    int co = 0;         // danh dau co so chinh phuong hay khong
    long long tong = 0;
    long long val;      /* gia tri sau khi chuyen sang long long */

    for (i = 0; i < n; i++)
    {
        if (la_so_nguyen(A[i]))     // chi xu ly neu A[i] la so nguyen
        {
            val = to_ll(A[i]);      // chuyen xau -> so
            if (la_chinh_phuong(val))
            {
                printf("%lld ", val);
                tong += val;
                co = 1;
            }
        }
    }

    if (!co)
        printf("Khong co so chinh phuong nao.");  // neu khong co so chinh phuong

    printf("\nTong cac so chinh phuong = %lld\n", tong);

    return 0;
}

/*
THUAT TOAN + CAC BUOC XU LY:

input: 1e9
1. Nhap chuoi n, kiem tra neu n la so nguyen duong thi chap nhan.
2. Nhap n phan tu A[i] duoi dang chuoi (vi co the nhap dau, chu sai...).
3. In lai mang da nhap.
4. Duyet tung phan tu:
     - Neu A[i] la so nguyen hop le => chuyen sang long long.
     - Kiem tra xem so do co phai so chinh phuong:
            + so >= 0
            + sqrt(x) lam tron lai, binh phuong lai co bang x hay khong
5. Neu dung thi in ra va cong vao tong.
6. Neu khong co so chinh phuong nao thi thong bao.
7. In tong cuoi cung.

Luu y:
- Kiem tra chinh phuong dung sqrt + lam tron 0.5 de tranh loi sai so so thuc.
- Xu ly du lieu dau vao duoi dang chuoi de tranh tran so, sai dinh dang.
*/
