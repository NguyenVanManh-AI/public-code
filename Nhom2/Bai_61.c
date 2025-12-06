#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 200

/* ham kiem tra chuoi co phai so nguyen thuan (khong dau cham, chi gom chu so, co the co dau tru) */
int la_so_nguyen_thuan(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1; // bo qua dau tru neu co

    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))   /* neu ky tu khong phai chu so */
            return 0;

    return 1; // neu tat ca ky tu la chu so
}

/* ham kiem tra mot so co phai nguyen to khong */
int la_nguyen_to(long long x)
{
    long long i;
    if (x < 2) return 0; // so < 2 khong la nguyen to

    for (i = 2; i * i <= x; i++) // chi duyet toi can bac hai
        if (x % i == 0)         // neu ton tai uoc
            return 0;

    return 1; // khong co uoc => la so nguyen to
}

int main()
{
    int n;
    char A[MAX][100];
    long long val;
    long long tong = 0;
    int i;  /* bien i dung cho vong lap */

    printf("Nhap so luong phan tu n (>=15): ");
    scanf("%d", &n);

    while (n < 15) // bat buoc n >= 15
    {
        printf("n phai >= 15. Nhap lai: ");
        scanf("%d", &n);
    }

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++)
    {
        printf("Nhap A[%d]: ", i);
        scanf("%s", A[i]); // nhap chuoi, khong gioi han so am hay khac
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%s ", A[i]); // in lai mang

    printf("\n\n=== Tong cac so nguyen to trong mang ===\n");

    for (i = 0; i < n; i++)
    {
        if (la_so_nguyen_thuan(A[i]))   /* chi xu ly neu la chuoi so nguyen thuan */
        {
            val = atoll(A[i]); // chuyen chuoi sang long long (co the tran)
            if (la_nguyen_to(val)) // kiem tra nguyen to
                tong += val;       // cong vao tong
        }
    }

    printf("Tong = %lld\n", tong); // in ket qua tong cac so nguyen to

    return 0;
}

/*
Giai thich thuat toan:
1. nhap so n, bat buoc n >= 15
2. nhap n chuoi vao mang A
3. in lai mang A
4. duyet tung phan tu:
   - neu la chuoi co dang so nguyen thuan thi chuyen sang long long
   - kiem tra xem co la so nguyen to khong
   - neu dung thi cong vao tong
5. in tong cac so nguyen to

Luu y:
- ham la_so_nguyen_thuan tu cho phep dau tru, nhung so am khong bao gio la nguyen to
- ham atoll khong kiem tra tran so long long
- so nguyen to la so >1 va chi chia het cho 1 va chinh no
*/
