#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham doc chuoi (giu nguyen dang nguoi dung nhap) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai la so nguyen (khong chua dau cham) */
int la_so_nguyen(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    for (; s[i]; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

/* Chuyen chuoi so nguyen sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

/* Kiem tra chinh phuong */
int la_chinh_phuong(long long x)
{
    if (x < 0) return 0;

    long long t = 1;
    while (t * t < x) t++;

    return (t * t == x);
}

int main()
{
    int n = 0;

    /* Nhap n, yeu cau n > 0 */
    while (1)
    {
        char buf[100];
        nhap_chuoi("so luong phan tu n", buf);

        if (la_so_nguyen(buf))
        {
            n = (int)to_ll(buf);
            if (n > 0)
                break;
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n");
    }

    char A[200][100];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (int i = 0; i < n; i++)
    {
        char ten[50];
        sprintf(ten, "A[%d]", i);
        nhap_chuoi(ten, A[i]);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (int i = 0; i < n; i++)
        printf("%s ", A[i]);

    printf("\n\n=== Cac so chinh phuong trong mang ===\n");
    int co = 0;
    long long tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (la_so_nguyen(A[i])) 	// chi nhan so nguyen
        {
            long long val = to_ll(A[i]);
            if (la_chinh_phuong(val))
            {
                printf("%lld ", val);
                tong += val;
                co = 1;
            }
        }
    }

    if (!co)
        printf("Khong co so chinh phuong nao.");

    printf("\nTong cac so chinh phuong = %lld\n", tong);

    return 0;
}