#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Hàm nhập số nguyên nghiêm ngặt, trả về long long */
long long nhap_so_nguyen(const char *ten)
{
    char s[200];
    while (1)
    {
        int hop_le = 1;
        printf("Nhap %s: ", ten);
        scanf("%s", s);

        int i = 0;

        /* Cho phép số âm */
        if (s[0] == '-' && s[1] != '\0')
            i = 1;

        /* Kiểm tra từng ký tự */
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

            /* Chuyển chuỗi sang số long long */
            for (; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0');

            return dau * x;
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Hàm xóa phần tử tại vị trí k */
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

    /* Nhập vị trí k */
    int k = (int)nhap_so_nguyen("chi so k can xoa");
    while (k < 0 || k >= n)
    {
        printf("k phai nam trong [0 .. %d]. Nhap lai.\n", n - 1);
        k = (int)nhap_so_nguyen("chi so k can xoa");
    }

    /* Xóa phần tử */
    xoa_vi_tri(A, &n, k);

    /* Xuất kết quả */
    printf("\n=== Mang sau khi xoa A[%d] ===\n", k);
    for (int i = 0; i < n; i++)
        printf("%lld ", A[i]);

    printf("\n");
    return 0;
}
