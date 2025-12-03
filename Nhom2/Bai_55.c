#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Ham nhap so nguyen nghiem ngat, tra ve long long */
long long nhap_so_nguyen(const char *ten)
{
    char s[200];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* Cho phep so am */
        if (s[0] == '-' && s[1] != '\0')
            i = 1;

        /* Kiem tra tung ky tu */
        for (; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long x = 0;
            int dau = (s[0] == '-') ? -1 : 1;
            i = (s[0] == '-') ? 1 : 0;

            /* Chuyen chuoi sang so long long */
            for (; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0');

            return dau * x;
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham xoa phan tu tai vi tri k */
void xoa_vi_tri(long long A[], int *n, int k)
{
    for (int i = k; i < *n - 1; i++)
        A[i] = A[i + 1];
    (*n)--;
}

int main()
{
    int n = (int)nhap_so_nguyen("so luong phan tu n");
    while (n <= 0)
    {
        printf("n phai > 0. Nhap lai.\n");
        n = (int)nhap_so_nguyen("so luong phan tu n");
    }

    long long A[200];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (int i = 0; i < n; i++)
    {
        char ten[50];
        sprintf(ten, "A[%d]", i);
        A[i] = nhap_so_nguyen(ten);
    }

    /* Nhap vi tri k */
    int k = (int)nhap_so_nguyen("chi so k can xoa");
    while (k < 0 || k >= n)
    {
        printf("k phai nam trong [0 .. %d]. Nhap lai.\n", n - 1);
        k = (int)nhap_so_nguyen("chi so k can xoa");
    }

    /* Xoa phan tu */
    xoa_vi_tri(A, &n, k);

    /* Xuat ket qua */
    printf("\n=== Mang sau khi xoa A[%d] ===\n", k);
    for (int i = 0; i < n; i++)
        printf("%lld ", A[i]);

    printf("\n");
    return 0;
}
