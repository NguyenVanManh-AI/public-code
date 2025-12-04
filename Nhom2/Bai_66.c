#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Ham nhap chuoi */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Ham kiem tra chuoi co phai la so am */
int la_so_am(const char *s)
{
    return (s[0] == '-');
}

int main()
{
    int n;
    char buf[50];
    int hop_le;
    int i;
    int m = 0;

    /* Nhap n sao cho n > 0 */
    while (1)
    {
        printf("Nhap so luong phan tu n: ");
        scanf("%s", buf);

        hop_le = 1;

        for (i = 0; buf[i] != '\0'; i++)
        {
            if (!isdigit(buf[i]))
                hop_le = 0;
        }

        if (hop_le)
        {
            n = 0;
            for (i = 0; buf[i] != '\0'; i++)
                n = n * 10 + (buf[i] - '0');

            if (n > 0)
                break;
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n");
    }

    char A[200][100];
    char B[200][100];
    char ten[20];

    /* Nhap mang A */
    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%d]", i);
        nhap_chuoi(ten, A[i]);
    }

    /* Xuat mang A */
    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%s ", A[i]);

    /* Xoa cac so am */
    printf("\n\n=== Mang A sau khi xoa cac so am ===\n");

    for (i = 0; i < n; i++)
    {
        if (!la_so_am(A[i]))   /* Chi giu cac chuoi khong bat dau bang dau tru */
        {
            strcpy(B[m], A[i]);
            m++;
        }
    }

    for (i = 0; i < m; i++)
        printf("%s ", B[i]);

    printf("\n");
    return 0;
}
