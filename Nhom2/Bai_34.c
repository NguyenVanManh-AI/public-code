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
        int hop_le = 1; // gia su chuoi hop le

        /* Kiem tra tung ky tu trong chuoi */
        for (i = 0; s[i] != '\0'; i++)
        {
            // neu ky tu nay khong phai '0'..'9' thi khong hop le
            if (s[i] < '0' || s[i] > '9')
            {
                hop_le = 0;
                break;
            }
        }

        if (hop_le)
            return; // chuoi chi toan ky tu so => hop le

        printf("Chuoi khong hop le. Nhap lai.\n");
    }
}

/* Ham kiem tra chuoi co doi xung hay khong */
int la_doi_xung(const char *s)
{
    int l = 0;                // con tro trai bat dau tu dau chuoi
    int r = strlen(s) - 1;    // con tro phai bat dau tu cuoi chuoi

    while (l < r)
    {
        // neu 2 ky tu doi xung khong bang nhau thi khong doi xung
        if (s[l] != s[r])
            return 0;

        l++;   // tien con tro trai sang phai
        r--;   // lui con tro phai sang trai
    }

    return 1; // neu thoat vong lap ma khong sai => doi xung
}

int main(void)
{
    char a[105]; // mang chua chuoi, du lon de luu so co nhieu chu so

    nhap_chuoi(a, 105); // goi ham nhap chuoi so hop le

    // kiem tra va in ket qua
    if (la_doi_xung(a))
        printf("Chuoi tu doi xung\n");
    else
        printf("Chuoi khong tu doi xung\n");

    return 0;
}

/*
Giai thich thuat toan:

- Su dung chuoi de xu ly so rat lon, tranh tran so.
- Khi nhap chuoi:
    + Kiem tra tung ky tu co phai la so tu '0'..'9'
    + Neu co ky tu khac => bat nhap lai
- Kiem tra doi xung:
    + Dung 2 con tro: trai (l) va phai (r)
    + So sanh tung cap ky tu s[l] va s[r]
    + Neu khac nhau => khong doi xung
    + Neu tat ca giong nhau => chuoi doi xung
*/
