#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DAI_TOI_DA 256

// Ham doi phan nguyen sang co so moi
void doi_phan_nguyen(long long so, int coso, char *ketqua) {
    char ky_tu[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char tam[DAI_TOI_DA];
    int i;
    int am;
    int dai;
    int j;

    i = 0;
    am = 0;

    // Neu so = 0 thi ket qua la "0"
    if (so == 0) {
        strcpy(ketqua, "0");
        return;
    }

    // Kiem tra so am
    if (so < 0) {
        am = 1;
        so = -so;
    }

    // Chia lien tuc de lay tung chu so
    while (so > 0) {
        tam[i++] = ky_tu[so % coso];
        so /= coso;
    }

    // Neu la so am thi them dau '-'
    if (am)
        tam[i++] = '-';

    tam[i] = '\0';

    // Dao nguoc chuoi tam
    dai = strlen(tam);
    for (j = 0; j < dai; j++) {
        ketqua[j] = tam[dai - j - 1];
    }
    ketqua[dai] = '\0';
}

// Ham doi phan thap phan
void doi_phan_thap_phan(double phanle, int coso, char *ketqua) {
    char ky_tu[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int gioihan;
    int i;
    int so;

    gioihan = 20;
    i = 0;

    while (phanle > 1e-15 && i < gioihan) {
        phanle *= coso;
        so = (int)phanle;
        ketqua[i++] = ky_tu[so];
        phanle -= so;
    }

    ketqua[i] = '\0';
}

int main() {
    char chuoi_nhap[DAI_TOI_DA];
    double so_nhap;
    int coso;
    long long phan_nguyen;
    double phan_thap_phan;
    char kq_nguyen[DAI_TOI_DA];
    char kq_thap_phan[DAI_TOI_DA];

    // Nhap so he 10
    printf("Nhap so he thap phan: ");
    scanf("%s", chuoi_nhap);

    // Vong lap bat buoc nhap lai co so neu sai
    do {
        printf("Nhap co so can doi (2 - 36): ");
        scanf("%d", &coso);

        if (coso < 2 || coso > 36)
            printf("Co so khong hop le! Vui long nhap lai.\n");

    } while (coso < 2 || coso > 36);

    so_nhap = atof(chuoi_nhap);

    phan_nguyen = (long long)so_nhap;
    phan_thap_phan = fabs(so_nhap - phan_nguyen);

    doi_phan_nguyen(phan_nguyen, coso, kq_nguyen);
    doi_phan_thap_phan(phan_thap_phan, coso, kq_thap_phan);

    printf("Ket qua: %s", kq_nguyen);

    if (phan_thap_phan > 0)
        printf(".%s\n", kq_thap_phan);
    else
        printf("\n");

    return 0;
}
