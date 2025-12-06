#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/* Ham doc chuoi nhap tu ban phim (giu nguyen ky tu nhap) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai la so nguyen (co the co dau -) NHUNG khong duoc co dau cham */
int la_so_nguyen(const char *s)
{
    int i = 0;

    /* Chap nhan dau tru o dau chuoi */
    if (s[0] == '-' && s[1] != '\0')
        i = 1;

    /* Tat ca cac ky tu con lai phai la chu so */
    for (; s[i] != '\0'; i++)
        if (!isdigit(s[i]))   // isdigit(): kiem tra ky tu co phai chu so 0–9 khong
            return 0;

    return 1;
}

/* Chuyen chuoi so sang kieu long long (tu code tu viet, khong dung atoll) */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1;     // lay dau
    int i = (s[0] == '-') ? 1 : 0;        // neu co '-', bo qua

    for (; s[i] != '\0'; i++)
        x = x * 10 + (s[i] - '0');        // chuyen ky tu thanh so

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
    long long so_nt_cuoi = -1;     // mac dinh khong tim thay so nguyen to

    /* Vong lap nhap N sao cho N > 0 */
    while (1)
    {
        nhap_chuoi("so luong phan tu N", buf);

        if (la_so_nguyen(buf))    // Kiem tra xem chuoi co phai so nguyen
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

    /* Tim so nguyen to cuoi cung trong mang */
    for (i = 0; i < N; i++)
    {
        if (la_so_nguyen(A[i]))   // Neu A[i] la so nguyen
        {
            val = to_ll(A[i]);    // Chuyen sang long long

            if (la_nguyen_to(val))    // Kiem tra nguyen to
                so_nt_cuoi = val;     // Cap nhat so nguyen to cuoi cung
        }
    }

    printf("\n\n=== So nguyen to cuoi cung trong mang ===\n");

    if (so_nt_cuoi == -1)
        printf("Khong co so nguyen to trong mang.\n");
    else
        printf("%lld\n", so_nt_cuoi);

    return 0;
}

/* ----------------------------------------------------------
   LUONG CHAY CHINH:
   - Nguoi dung nhap N -> kiem tra N la so nguyen > 0
   - Nhap N phan tu mang A (dang chuoi => co the la so, chu, dau tru,...)
   - Duyet mang:
        + Neu phan tu la so nguyen thi chuyen sang long long
        + Kiem tra co phai so nguyen to khong
        + Cap nhat so nguyen to cuoi cung
   - In ket qua
   ----------------------------------------------------------
*/
