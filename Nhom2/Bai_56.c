#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Hàm đọc chuỗi (giữ nguyên dạng người dùng nhập) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiểm tra chuỗi có phải là số nguyên (không chứa dấu chấm) */
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

/* Chuyển chuỗi số nguyên sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;
    int i = (s[0] == '-') ? 1 : 0;

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0');

    return dau * x;
}

/* Kiểm tra số hoàn hảo */
int so_hoan_hao(long long x)
{
    if (x <= 0) return 0;

    long long sum = 0;

    for (long long i = 1; i * 1LL <= x / 2; i++)
        if (x % i == 0)
            sum += i;

    return (sum == x);
}

int main()
{
    int n = 0;

    /* Nhập n, yêu cầu n > 0 */
    while (1)
    {
        n = 0;
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

    printf("\n\n=== Cac so hoan hao trong mang ===\n");
    int co = 0;

    for (int i = 0; i < n; i++)
    {
        if (la_so_nguyen(A[i]))         // chỉ kiểm tra số nguyên
        {
            long long val = to_ll(A[i]);
            if (so_hoan_hao(val))
            {
                printf("%lld ", val);
                co = 1;
            }
        }
    }

    if (!co)
        printf("Khong co so hoan hao nao.");

    printf("\n");
    return 0;
}
