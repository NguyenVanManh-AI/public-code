#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 500

/* ------------------ KIEM TRA CHUOI LA SO THUC ------------------ */
/* Cho phep so am, so lon, co phan thap phan */
int la_so_thuc(const char *s)
{
    int i = 0, da_co_dau_cham = 0;

    if (s[0] == '-') i = 1;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] == '.')
        {
            if (da_co_dau_cham) return 0;
            da_co_dau_cham = 1;
        }
        else if (!isdigit(s[i]))
            return 0;
    }

    return 1;
}

/* ------------------ NHAP SO THUC N ------------------ */
double nhap_so_thuc()
{
    char s[MAX];
    double x;
    int hop_le;

    while (1)
    {
        printf("Nhap so thuc n (he thap phan): ");
        scanf("%s", s);

        hop_le = la_so_thuc(s);
        if (hop_le)
        {
            x = atof(s);
            return x;
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* ------------------ NHAP CO SO C (2..36) ------------------ */
int nhap_coso()
{
    char s[100];
    int i, hop_le;
    long long c;

    while (1)
    {
        hop_le = 1;
        printf("Nhap co so c (2 -> 36): ");
        scanf("%s", s);

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
            c = 0;
            for (i = 0; s[i] != '\0'; i++)
                c = c * 10 + (s[i] - '0');

            if (c >= 2 && c <= 36)
                return (int)c;
        }

        printf("Co so phai trong khoang 2..36. Nhap lai.\n");
    }
}

/* ------------------ DOI PHAN NGUYEN ------------------ */
void doi_phan_nguyen(long long nguyen, int coso, char *kq)
{
    char buf[300];
    int idx = 0, i;

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

    for (i = 0; i < idx; i++)
        kq[i] = buf[idx - 1 - i];
    kq[idx] = '\0';
}

/* ------------------ DOI PHAN THAP PHAN ------------------ */
void doi_phan_thap_phan(double thap_phan, int coso, char *kq)
{
    int i, digit;
    char buf[300];
    int idx = 0;

    for (i = 0; i < 40; i++)
    {
        thap_phan *= coso;
        digit = (int)thap_phan;

        if (digit < 10) buf[idx++] = '0' + digit;
        else             buf[idx++] = 'A' + (digit - 10);

        thap_phan -= digit;
        if (thap_phan == 0) break;
    }

    buf[idx] = '\0';
    strcpy(kq, buf);
}

/* ------------------ MAIN ------------------ */
int main()
{
    double n, thap_phan, n_abs;
    long long nguyen;
    int c;
    char kq_nguyen[300], kq_thap_phan[300];
    int am;

    n = nhap_so_thuc();
    c = nhap_coso();

    am = (n < 0);
    n_abs = fabs(n);

    nguyen = (long long)n_abs;
    thap_phan = n_abs - nguyen;

    doi_phan_nguyen(nguyen, c, kq_nguyen);
    doi_phan_thap_phan(thap_phan, c, kq_thap_phan);

    printf("\n=== Ket qua doi co so ===\n");
    if (am) printf("-");
    printf("%s", kq_nguyen);

    if (thap_phan > 0)
        printf(".%s", kq_thap_phan);

    printf("\n");
    return 0;
}
