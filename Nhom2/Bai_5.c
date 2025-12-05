#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Ham nhap chuoi tu ban phim, giu nguyen dang nguoi dung nhap */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten); // in ra ten truong can nhap
    scanf("%s", out); // doc chuoi khong co khoang trang
}

/* Kiem tra chuoi co phai so tu nhien hop le (chi gom cac ky tu 0-9) */
int la_so_tu_nhien(const char *s)
{
    int i = 0;
    if (s[0] == '\0') return 0; // kiem tra rong

    for (i = 0; s[i]; i++)
        if (!isdigit(s[i])) // neu co ky tu khong phai chu so
            return 0;

    return 1; // hop le
}

/* Chuyen chuoi so tu nhien sang long long */
long long to_ll(const char *s)
{
    long long x = 0;
    int i;
    for (i = 0; s[i]; i++)
        x = x * 10 + (s[i] - '0'); // chuyen ky tu so sang so nguyen
    return x;
}

/* Tinh USCLN 2 so theo thuat toan Euclid */
long long uscln2(long long a, long long b)
{
    long long t;
    while (b != 0) // lap den khi b = 0
    {
        t = a % b; // lay phan du
        a = b;     // gan lai a
        b = t;     // gan lai b
    }
    return a; // a la uscln
}

/* Tinh USCLN cua nhieu so (dung ham uscln2 gop don) */
long long uscln_nhieu(long long arr[], int n)
{
    int i;
    long long g = arr[0]; // lay so dau tien lam goc
    for (i = 1; i < n; i++)
        g = uscln2(g, arr[i]); // g = USCLN(g, so tiep theo)
        // Ta co : USCLN(a, b, c) = USCLN( USCLN(a, b), c )
    return g;
}

int main()
{
    char buf[100];
    int m = 0;

    /* ==== NHAP SO LUONG M ==== */
    while (1)
    {
        nhap_chuoi("so luong phan tu m", buf); // nhap m dang chuoi

        if (la_so_tu_nhien(buf)) // kiem tra hop le
        {
            m = (int)to_ll(buf); // chuyen sang so nguyen
            if (m >= 2) break; // m phai >= 2
        }

        printf("m phai la so tu nhien >= 2. Nhap lai.\n");
    }

    /* ==== NHAP CAC GIA TRI ==== */
    char A[200][100]; // mang chua cac chuoi nhap

    printf("\n=== Nhap %d gia tri bat ky ===\n", m);

    /* Dua khai bao bien i ra ngoai de dung chuan C89 */
    int i;
    for (i = 0; i < m; i++)
    {
        char ten[50];
        sprintf(ten, "n%d", i + 1); // dat ten truong: n1, n2, ...
        nhap_chuoi(ten, A[i]); // nhap chuoi
    }

    /* ==== LOC CAC SO TU NHIEN HOP LE ==== */
    long long hop_le[200]; // mang dung luu so hop le
    int dem = 0;

    for (i = 0; i < m; i++)
    {
        if (la_so_tu_nhien(A[i])) // neu A[i] la so tu nhien
        {
            hop_le[dem++] = to_ll(A[i]); // chuyen sang long long va luu lai
        }
    }

    /* ==== XU LY ==== */
    if (dem == 0)
    {
        printf("\nKhong co so tu nhien hop le nao.\n");
        return 0;
    }

    int tat_ca_bang_0 = 1;
    for (i = 0; i < dem; i++)
    {
        if (hop_le[i] != 0) // kiem tra xem co so nao != 0 khong
        {
            tat_ca_bang_0 = 0;
            break;
        }
    }

    if (tat_ca_bang_0)
    {
        printf("\nTat ca so tu nhien = 0, USCLN khong xac dinh\n");
        return 0;
    }

    long long ketqua = uscln_nhieu(hop_le, dem); // tinh uscln tat ca

    printf("\nUSCLN cua cac so tu nhien hop le = %lld\n", ketqua);

    return 0;
}

/*
THUAT TOAN & CAC BUOC XU LY CHINH:

1. Nguoi dung nhap m (so luong phan tu). Chi chap nhan m >= 2 va phai la so tu nhien.
2. Nguoi dung nhap m gia tri bat ky (co the la chu, so, ky tu, so lon,...).
3. Chuong trinh loc cac gia tri la so tu nhien hop le (chi gom cac chu so 0-9).
4. Chuyen cac chuoi hop le sang kieu long long.
5. Neu tat ca so hop le = 0 thi thong bao uscln khong xac dinh.
6. Neu co so hop le, tinh USCLN cua tat ca cac so bang cach:
       g = uscln2(g, arr[i]) lap lai cho den het.
       Ta co : USCLN(a, b, c) = USCLN( USCLN(a, b), c )
7. In ra ket qua.

LUU Y:
- Nhap chuoi thay vi nhap so de tranh tran so (overflow).
- Khong chap nhan chuoi am, chuoi co dau ., e, ky tu,... => chi cho phep 0-9.
- Thuat toan Euclid dam bao tinh nhanh va chinh xac USCLN.
*/
