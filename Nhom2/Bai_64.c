#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Ham doc chuoi */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai la so nguyen khong dau cham */
int la_so_nguyen(const char *s)
{
    int i = 0;

    /* Chap nhan dau tru o dau chuoi */
    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

/* Chuyen chuoi sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    for (; s[i] != '\0'; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

/* Kiem tra so nguyen to */
int la_nguyen_to(long long x)
{
    if (x < 2)
        return 0;

    long long j;
    for (j = 2; j * j <= x; j++)
        if (x % j == 0)
            return 0;

    return 1;
}

int main()
{
    int N = 0;
    char buf[100];
    char ten[50];
    int i;
    long long val;
    long long so_nt_cuoi = -1;

    /* Nhap N sao cho N > 0 */
    while (1)
    {
        nhap_chuoi("so luong phan tu N", buf);

        if (la_so_nguyen(buf))
        {
            N = (int)to_ll(buf);
            if (N > 0)
                break;
        }

        printf("N phai la so nguyen duong > 0. Nhap lai.\n");
    }

    char A[200][100];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < N; i++)
    {
        sprintf(ten, "A[%d]", i);
        nhap_chuoi(ten, A[i]);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < N; i++)
        printf("%s ", A[i]);

    /* Tim so nguyen to cuoi cung */
    for (i = 0; i < N; i++)
    {
        if (la_so_nguyen(A[i]))
        {
            val = to_ll(A[i]);
            if (la_nguyen_to(val))
                so_nt_cuoi = val;
        }
    }

    printf("\n\n=== So nguyen to cuoi cung trong mang ===\n");

    if (so_nt_cuoi == -1)
        printf("Khong co so nguyen to trong mang.\n");
    else
        printf("%lld\n", so_nt_cuoi);

    return 0;
}
