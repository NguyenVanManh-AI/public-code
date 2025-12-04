#include <stdio.h>
#include <string.h>

/* Ham nhap chuoi so nguyen duong */
void nhap_chuoi(char *s, int max_len)
{
    while (1)
    {
        printf("Nhap chuoi so nguyen duong a: ");
        scanf("%s", s); // nhap chuoi, khong dung space

        int i;
        int hop_le = 1;

        /* Kiem tra toan ky tu la so */
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
            return; // chuoi hop le

        printf("Chuoi khong hop le. Nhap lai.\n");
    }
}

/* Ham kiem tra chuoi co doi xung khong */
int la_doi_xung(const char *s)
{
    int l = 0;
    int r = strlen(s) - 1;

    while (l < r)
    {
        if (s[l] != s[r])
            return 0; // khong doi xung

        l++;
        r--;
    }

    return 1; // doi xung
}

int main(void)
{
    char a[105]; // du cho chuoi lon

    nhap_chuoi(a, 105); // nhap chuoi so hop le

    if (la_doi_xung(a))
        printf("Chuoi tu doi xung\n");
    else
        printf("Chuoi khong tu doi xung\n");

    return 0;
}

/*
Thuat toan:
- Nhap chuoi ky tu (de xu ly so rat lon).
- Kiem tra:
    + Tat ca ky tu phai la '0'..'9'
- Kiem tra doi xung:
    + So sanh ky tu s[l] va s[r] tu 2 dau lien tuc thu hep
- Neu toan bo giong nhau => doi xung
*/
