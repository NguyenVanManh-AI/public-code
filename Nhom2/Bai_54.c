#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Ham nhap so thuc n (he thap phan) */
double nhap_so_thuc(const char *ten)
{
    double x;
    while (1)
    {
        printf("Nhap canh %s: ", ten);

        if (scanf("%lf", &x) == 1 && x > 0)
            return x;

        printf("Gia tri khong hop le, phai > 0. Nhap lai.\n");
        while (getchar() != '\n'); // xoa bo dem
    }
}

/* Ham nhap so nguyen NGHIEM NGAT (khong chap nhan 2.0, 03, -5, ...) */
int nhap_so_nguyen_nghiem_ngat(const char *ten)
{
    char s[100];
    int i;

    while (1)
    {
        int hop_le = 1;

        printf("Nhap co so c (2 -> 36): ");
        scanf("%s", s);

        /* Kiem tra chuoi chi gom chu so */
        for (i = 0; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
        {
            long long c = 0;

            /* Chuyen chuoi sang so */
            for (i = 0; s[i] != '\0'; i++)
                c = c * 10 + (s[i] - '0');

            /* KIỂM TRA PHẠM VI CƠ SỐ */
            if (c >= 2 && c <= 36)
                return (int)c;
        }

        printf("Gia tri co so phai la so nguyen trong khoang 2..36. Nhap lai.\n");
    }
}

/* Ham doi phan nguyen */
void doi_phan_nguyen(long long nguyen, int coso, char *kq)
{
    char buf[200];
    int idx = 0;

    if (nguyen == 0)
    {
        kq[0] = '0';
        kq[1] = '\0';
        return;
    }

    while (nguyen > 0)
    {
        int r = nguyen % coso;
        if (r < 10) buf[idx++] = '0' + r;
        else        buf[idx++] = 'A' + (r - 10);
        nguyen /= coso;
    }

    /* dao chuoi */
    int i;
    for (i = 0; i < idx; i++)
        kq[i] = buf[idx - 1 - i];

    kq[idx] = '\0';
}

/* Ham doi phan thap phan */
void doi_phan_thap_phan(double thap_phan, int coso, char *kq)
{
    int i;
    char buf[200];
    int idx = 0;

    for (i = 0; i < 30; i++) /* lay 30 chu so thap phan */
    {
        thap_phan *= coso;
        int digit = (int)thap_phan;

        if (digit < 10) buf[idx++] = '0' + digit;
        else            buf[idx++] = 'A' + (digit - 10);

        thap_phan -= digit;
        if (thap_phan == 0) break;
    }

    buf[idx] = '\0';
    strcpy(kq, buf);
}

int main()
{
    double n = nhap_so_thuc("so thuc n (he thap phan)");
    int c = nhap_so_nguyen_nghiem_ngat("co so c (2-36)");

    if (c < 2 || c > 36)
    {
        printf("Co so phai trong khoang [2..36]\n");
        return 0;
    }

    long long nguyen = (long long)n;
    double thap_phan = n - nguyen;
    if (thap_phan < 0) thap_phan = -thap_phan;
    if (nguyen < 0) nguyen = -nguyen;

    char kq_nguyen[200], kq_thap_phan[200];

    doi_phan_nguyen(nguyen, c, kq_nguyen);
    doi_phan_thap_phan(thap_phan, c, kq_thap_phan);

    printf("\n=== Ket qua ===\n");

    if (n < 0) printf("-");
    printf("%s", kq_nguyen);

    if (thap_phan > 0)
        printf(".%s", kq_thap_phan);

    printf("\n");

    return 0;
}

/*
Thuat toan:
- Nhap n dang so thuc tu ban phim bang chuoi → kiem tra hop le.
- Nhap co so c bang chuoi → chi chap nhan chu so, khong chap nhan 2.0.
- Tach phan nguyen va thap phan:
      nguyen = (long long)n
      thap_phan = n - nguyen
- Doi phan nguyen → chia lay du.
- Doi phan thap phan → nhan coso lap 30 lan.
- In ket qua.
*/
