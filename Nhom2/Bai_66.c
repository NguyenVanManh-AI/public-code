#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai so am */
int la_so_am(const char *s)
{
    return (s[0] == '-');
}

int main()
{
    int n;

    /* Nhap n > 0 */
    while (1)
    {
        char buf[50];
        printf("Nhap so luong phan tu n: ");
        scanf("%s", buf);

        int hop_le = 1;
        for (int i = 0; buf[i]; i++)
            if (!isdigit(buf[i]))
                hop_le = 0;

        if (hop_le)
        {
            n = 0;
            for (int i = 0; buf[i]; i++)
                n = n * 10 + (buf[i] - '0');

            if (n > 0) break;
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n");
    }

    char A[200][100];
    char B[200][100];
    int m = 0;

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (int i = 0; i < n; i++)
    {
        char ten[20];
        sprintf(ten, "A[%d]", i);
        nhap_chuoi(ten, A[i]);
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (int i = 0; i < n; i++)
        printf("%s ", A[i]);

    printf("\n\n=== Mang A sau khi xoa cac so am ===\n");

    for (int i = 0; i < n; i++)
    {
        if (!la_so_am(A[i])) 	// giu so >= 0, ke ca dang 999999999999.123
        {
            strcpy(B[m], A[i]);
            m++;
        }
    }

    for (int i = 0; i < m; i++)
        printf("%s ", B[i]);

    printf("\n");
    return 0;
}