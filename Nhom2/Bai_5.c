#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham doc chuoi (giu nguyen dang nguoi dung nhap) */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten);
    scanf("%s", out);
}

/* Kiem tra chuoi co phai so tu nhien hop le (chi gom chu so 0-9) */
int la_so_tu_nhien(const char *s)
{
    int i = 0;
    if (s[0] == '\0') return 0;

    for (i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return 0;

    return 1;
}

/* Chuyen chuoi so tu nhien sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int i;
    for (i = 0; s[i]; i++)
        x = x * 10 + (s[i] - '0');
    return x;
}

/* USCLN 2 so theo Euclid */
long long uscln2(long long a, long long b)
{
    long long t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

/* USCLN nhieu so */
long long uscln_nhieu(long long arr[], int n)
{
    int i;
    long long g = arr[0];
    for (i = 1; i < n; i++)
        g = uscln2(g, arr[i]);
    return g;
}

int main()
{
    char buf[100];
    int m = 0;

    /* ==== NHAP SO LUONG M ==== */
    while (1)
    {
        nhap_chuoi("so luong phan tu m", buf);

        if (la_so_tu_nhien(buf))
        {
            m = (int)to_ll(buf);
            if (m >= 2) break;
        }

        printf("m phai la so tu nhien >= 2. Nhap lai.\n");
    }

    /* ==== NHAP CAC GIA TRI (giữ nguyên chuỗi, không bắt nhập lại) ==== */
    char A[200][100];

    printf("\n=== Nhap %d gia tri bat ky ===\n", m);
    for (int i = 0; i < m; i++)
    {
        char ten[50];
        sprintf(ten, "n%d", i + 1);
        nhap_chuoi(ten, A[i]);
    }

    /* ==== LOC CAC SO TU NHIEN HOP LE ==== */
    long long hop_le[200];
    int dem = 0;

    for (int i = 0; i < m; i++)
    {
        if (la_so_tu_nhien(A[i]))
        {
            hop_le[dem++] = to_ll(A[i]);
        }
    }

    /* ==== XU LY === */
    if (dem == 0)
    {
        printf("\nKhong co so tu nhien hop le nao.\n");
        return 0;
    }

    long long ketqua = uscln_nhieu(hop_le, dem);

    printf("\nUSCLN cua cac so tu nhien hop le = %lld\n", ketqua);

    return 0;
}
