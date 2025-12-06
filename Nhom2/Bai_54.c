#include <stdio.h>      // thu vien nhap xuat
#include <stdlib.h>     // thu vien ho tro ham atof
#include <string.h>     // thu vien xu ly chuoi
#include <math.h>       // thu vien ham toan hoc fabs

#define DAI_TOI_DA 256  // do dai toi da cua cac chuoi ket qua

/* Ham doi phan nguyen cua so sang co so moi */
void doi_phan_nguyen(long long so, int coso, char *ketqua) {
    char ky_tu[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // bang ky tu ung voi tung chu so
    char tam[DAI_TOI_DA];     // mang tam de luu cac chu so sau khi chia
    int i;
    int am;
    int dai;
    int j;

    i = 0;     // chi so luu ky tu vao mang tam
    am = 0;    // bien danh dau so am

    // Neu so = 0 thi ket qua la "0"
    if (so == 0) {
        strcpy(ketqua, "0");  // sao chep "0" vao ket qua
        return;               // ket thuc ham
    }

    // Kiem tra so am
    if (so < 0) {
        am = 1;   // danh dau so am
        so = -so; // doi sang so duong de xu ly
    }

    // Chia lien tuc de lay tung chu so
    while (so > 0) {
        tam[i++] = ky_tu[so % coso]; // lay chu so o co so moi
        so /= coso;                  // giam gia tri so
    }

    // Neu la so am thi them dau '-'
    if (am)
        tam[i++] = '-';              // them ky tu dau tru

    tam[i] = '\0';                   // ket thuc chuoi tam

    // Dao nguoc chuoi tam de thanh ket qua dung thu tu
    dai = strlen(tam);               // lay do dai chuoi tam
    for (j = 0; j < dai; j++) {
        ketqua[j] = tam[dai - j - 1]; // dao nguoc
    }
    ketqua[dai] = '\0';              // ket thuc chuoi ket qua
}

/* Ham doi phan thap phan sang co so moi */
void doi_phan_thap_phan(double phanle, int coso, char *ketqua) {
    char ky_tu[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // bang ky tu cho he so cao
    int gioihan;    // gioi han so chu so thap phan can lay
    int i;
    int so;

    gioihan = 20;   // lay toi da 20 chu so thap phan
    i = 0;          // chi so luu ky tu vao ket qua

    while (phanle > 1e-15 && i < gioihan) { // lap den khi het phan le hoac dat gioi han
        phanle *= coso;       // nhan voi co so moi
        so = (int)phanle;     // lay phan nguyen lam chu so
        ketqua[i++] = ky_tu[so]; // luu ky tu tuong ung
        phanle -= so;         // lay lai phan thap phan con lai
    }

    ketqua[i] = '\0';        // ket thuc chuoi ket qua
}

int main() {
    char chuoi_nhap[DAI_TOI_DA];   // buffer luu so nhap dang chuoi
    double so_nhap;                // so thap phan sau khi chuyen
    int coso;                      // co so can doi
    long long phan_nguyen;         // phan nguyen cua so
    double phan_thap_phan;         // phan thap phan
    char kq_nguyen[DAI_TOI_DA];    // ket qua doi phan nguyen
    char kq_thap_phan[DAI_TOI_DA]; // ket qua doi phan thap phan

    // Nhap so he 10
    printf("Nhap so he thap phan: ");
    scanf("%s", chuoi_nhap);       // nhap so dang chuoi

    // Vong lap bat buoc nhap lai co so neu sai
    do {
        printf("Nhap co so can doi (2 - 36): ");
        scanf("%d", &coso);        // nhap co so moi

        if (coso < 2 || coso > 36)
            printf("Co so khong hop le! Vui long nhap lai.\n"); // bao loi neu ngoai pham vi

    } while (coso < 2 || coso > 36); // lap den khi nhap dung

    so_nhap = atof(chuoi_nhap);      // chuyen chuoi thanh so double

    phan_nguyen = (long long)so_nhap;              // tach phan nguyen
    phan_thap_phan = fabs(so_nhap - phan_nguyen);  // lay phan thap phan tuyet doi

    doi_phan_nguyen(phan_nguyen, coso, kq_nguyen); // doi phan nguyen
    doi_phan_thap_phan(phan_thap_phan, coso, kq_thap_phan); // doi phan thap phan

    printf("Ket qua: %s", kq_nguyen);  // in phan nguyen da doi

    if (phan_thap_phan > 0)            // neu co phan thap phan thi in tiep
        printf(".%s\n", kq_thap_phan);
    else
        printf("\n");

    return 0; // ket thuc chuong trinh
}

/*
Thuat toan:
- Nguoi dung nhap mot so thap phan duoi dang chuoi de ho tro so lon va so thap phan.
- Chuoi duoc doi sang double de tach phan nguyen va phan thap phan.
- Phan nguyen duoc doi sang co so moi bang viec chia lien tuc lay phan du.
- Phan thap phan duoc doi bang viec nhan voi co so roi lay phan nguyen moi vong.
- Su dung bang ky tu de bieu dien chu so trong he co so den 36.
- Gioi han so chu so thap phan la 20 de tranh lap vo han va tranh sai so floating point.
- Ket qua ghep phan nguyen va phan thap phan thanh chuoi cuoi cung.

Ex : 12.375 -> co so 2 (12.375₁₀ = 1100.011₂)
| Chia   | Thuong | Du |
| ------ | ------ | -- |
| 12 / 2 | 6      | 0  |
| 6 / 2  | 3      | 0  |
| 3 / 2  | 1      | 1  |
| 1 / 2  | 0      | 1  |

| Nhan 2    | Ket qua | Phan nguyen |
| --------- | ------- | ----------- |
| 0.375 × 2 | 0.75    | 0           |
| 0.75 × 2  | 1.5     | 1           |
| 0.5 × 2   | 1.0     | 1           |

Ex : -12.375 -> co so 2 (12.375₁₀ = 1111 0011 1010₂)
B1 : 12.375₁₀ = 1100.011₂
B2 : 1100.011 = 0000 1100 0110 (8 bit nguyen + 4 bit phay => them 0 o cuoi)
B3 : 0000 1100 0110 -> dao bit -> 1111 0011 1001
B4 : 1111 0011 1001 + 1 => 1111 0011 1010
*/
