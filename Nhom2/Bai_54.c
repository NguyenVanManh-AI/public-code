#include <stdio.h>

/* ham chuyen so n (he 10) sang he c, luu vao chuoi kq */
void doi_co_so(int n, int c, char kq[]) {
    char bang[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    int du;
    int so_luong;

    /* xu ly truong hop n = 0 */
    if (n == 0) {
        kq[0] = '0';
        kq[1] = '\0';
        return;
    }

    so_luong = 0;

    /* lay tung chu so he c */
    while (n > 0) {
        du = n % c;
        kq[so_luong] = bang[du];
        so_luong = so_luong + 1;
        n = n / c;
    }

    /* ket thuc chuoi */
    kq[so_luong] = '\0';

    /* dao nguoc chuoi ket qua */
    for (i = 0; i < so_luong / 2; i++) {
        char tmp;
        tmp = kq[i];
        kq[i] = kq[so_luong - 1 - i];
        kq[so_luong - 1 - i] = tmp;
    }
}

int main() {
    int n;
    int c;
    char ket_qua[50];

    printf("Nhap so nguyen he 10: ");
    scanf("%d", &n);

    printf("Nhap co so c (2..36): ");
    scanf("%d", &c);

    if (c < 2 || c > 36) {
        printf("Co so khong hop le\n");
        return 0;
    }

    doi_co_so(n, c, ket_qua);

    printf("Ket qua doi sang he %d: %s\n", c, ket_qua);

    return 0;
}
/*
Nhap vao:
- Mot so nguyen n o he thap phan
- Mot co so c (2 ≤ c ≤ 36)
Sau do doi n sang he c va in ra ket qua.
- Dung mang ky tu de luu cac chu so sau khi doi co so
- Lay phan du r = n % c, anh xa:
    0–9  → '0'–'9'
    10–35 → 'A'–'Z'
- Dao chuoi lai de ra ket qua
*/