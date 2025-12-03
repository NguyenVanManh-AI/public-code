#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

/* Hàm nhập số nguyên nghiêm ngặt + KHÔNG CHO 6.0 */
long long nhap_so_nguyen_ll(const char *ten)
{
    char s[100];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* cho phép dấu âm */
        if (s[0] == '-' && s[1] != '\0')
            i = 1;

        /* kiểm tra từng ký tự phải là chữ số */
        for (; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (!hop_le)
        {
            printf("Gia tri khong hop le (chi nhap so nguyen). Nhap lai.\n");
            continue;
        }

        /* kiểm tra tràn long long khi convert */
        long long x = 0;
        int dau = (s[0] == '-') ? -1 : 1;
        i = (s[0] == '-') ? 1 : 0;

        for (; s[i] != '\0'; i++)
        {
            int digit = s[i] - '0';

            /* kiểm tra tràn trước khi x = x*10 + digit */
            if (x > (LLONG_MAX - digit) / 10)
            {
                hop_le = 0;
                break;
            }

            x = x * 10 + digit;
        }

        if (!hop_le)
        {
            printf("So qua lon, vuot gioi han long long. Nhap lai.\n");
            continue;
        }

        return dau * x;
    }
}

/* Hàm kiểm tra số hoàn hảo */
int so_hoan_hao(long long x)
{
    if (x <= 0) return 0;

    long long sum = 0;
    for (long long i = 1; i <= x / 2; i++)
        if (x % i == 0)
            sum += i;

    return (sum == x);
}

int main()
{
    int n;

    /* giữ nguyên cách nhập n của bạn */
    n = nhap_so_nguyen_ll("so luong phan tu n");
    while (n <= 0)
    {
        printf("n phai > 0. Nhap lai.\n");
        n = nhap_so_nguyen_ll("so luong phan tu n");
    }

    long long A[200];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (int i = 0; i < n; i++)
    {
        char ten[50];
        sprintf(ten, "A[%d]", i);
        A[i] = nhap_so_nguyen_ll(ten);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (int i = 0; i < n; i++)
        printf("%lld ", A[i]);

    printf("\n\n=== Cac so hoan hao trong mang ===\n");
    int co = 0;
    for (int i = 0; i < n; i++)
    {
        if (so_hoan_hao(A[i]))
        {
            printf("%lld ", A[i]);
            co = 1;
        }
    }

    if (!co)
        printf("Khong co so hoan hao nao.");

    printf("\n");
    return 0;
}
