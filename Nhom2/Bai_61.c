#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 200

/* Kiểm tra một chuỗi có phải là số nguyên thuần (không chứa dấu chấm) */
int la_so_nguyen_thuan(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

/* Kiểm tra số nguyên tố */
int la_nguyen_to(long long x)
{
    if (x < 2) return 0;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;
    char A[MAX][100];   // lưu chuỗi người dùng nhập
    long long val;
    long long tong = 0;

    printf("Nhap so luong phan tu n (>=15): ");
    scanf("%d", &n);

    while (n < 15)
    {
        printf("n phai >= 15. Nhap lai: ");
        scanf("%d", &n);
    }

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nhap A[%d]: ", i);
        scanf("%s", A[i]);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (int i = 0; i < n; i++)
        printf("%s ", A[i]);

    printf("\n\n=== Tong cac so nguyen to trong mang ===\n");

    for (int i = 0; i < n; i++)
    {
        if (la_so_nguyen_thuan(A[i]))      // chỉ nhận như "2" hoặc "17"
        {
            val = atoll(A[i]);             // chuyển chuỗi sang số
            if (la_nguyen_to(val))
                tong += val;
        }
    }

    printf("Tong = %lld\n", tong);

    return 0;
}
