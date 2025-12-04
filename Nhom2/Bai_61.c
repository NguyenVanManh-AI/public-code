#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 200

/* Kiem tra mot chuoi co phai la so nguyen thuan (khong chua dau cham) */
int la_so_nguyen_thuan(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))   /* ky tu khong phai chu so */
            return 0;

    return 1;
}

/* Kiem tra so nguyen to */
int la_nguyen_to(long long x)
{
    long long i;
    if (x < 2) return 0;
    for (i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;
    char A[MAX][100];
    long long val;
    long long tong = 0;
    int i;  /* khai bao bien i dung cho cac vong lap */

    printf("Nhap so luong phan tu n (>=15): ");
    scanf("%d", &n);

    while (n < 15)
    {
        printf("n phai >= 15. Nhap lai: ");
        scanf("%d", &n);
    }

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++)
    {
        printf("Nhap A[%d]: ", i);
        scanf("%s", A[i]);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%s ", A[i]);

    printf("\n\n=== Tong cac so nguyen to trong mang ===\n");

    for (i = 0; i < n; i++)
    {
        if (la_so_nguyen_thuan(A[i]))   /* chi nhan dang chuoi so nguyen thuan */
        {
            val = atoll(A[i]);
            if (la_nguyen_to(val))
                tong += val;
        }
    }

    printf("Tong = %lld\n", tong);

    return 0;
}
