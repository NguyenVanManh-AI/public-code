#include <stdio.h>
#include <ctype.h>
#include <limits.h>

/* Ham nhap so nguyen bat ky dang chuoi */
/* Chap nhan so duong, so am, so rat lon */
/* Ket thuc khi nguoi dung nhap vao 0 */
long long nhap_so_nguyen() {
    char s[200];   // luu chuoi nhap vao
    int i;

    while (1) {
        int hop_le = 1;   // gia su chuoi hop le

        printf("Nhap so (0 de dung): ");
        scanf("%s", s);   // nhap dang chuoi de tranh tran so

        /* Kiem tra ky tu dau tien co the la '-' */
        i = 0;
        if (s[0] == '-') 
            i = 1;   // neu la so am thi bo qua dau '-'

        /* Kiem tra cac ky tu con lai phai la chu so */
        for (; s[i] != '\0'; i++) {
            if (!isdigit(s[i])) {   // phat hien ky tu khong phai so
                hop_le = 0;
                break;
            }
        }

        if (hop_le) {
            long long x = 0;
            int am = (s[0] == '-');   // danh dau la so am hay duong

            /* Chuyen tu chuoi sang so nguyen long long */
            for (i = am ? 1 : 0; s[i] != '\0'; i++) {
                int digit = s[i] - '0';

                /* Kiem tra tran so khi nhan 10 và cong digit */
                if (x > (LLONG_MAX - digit) / 10) {
                    hop_le = 0;
                    break;
                }

                x = x * 10 + digit;   // cong don dua tren he 10
            }

            if (hop_le) {
                return am ? -x : x;   // tra ve so am hoac duong
            }
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham tinh tong cac so do nguoi dung nhap vao */
/* Dung lai khi nhap 0 */
/* Co kiem tra tran tong */
long long tinh_tong() {
    long long tong = 0;
    long long x;

    while (1) {
        x = nhap_so_nguyen();  // nhap tung so

        if (x == 0)
            break;             // nhap 0 thi dung

        /* Kiem tra tran tong truoc khi cong */
        if ((tong > 0 && x > LLONG_MAX - tong) ||
            (tong < 0 && x < LLONG_MIN - tong)) {
            printf("Tong bi tran! Khong the cong them so nay.\n");
            continue;   // bo qua so nay, khong cong vao tong
        }

        tong += x;
    }

    return tong;
}

int main() {
    long long kq = tinh_tong();  // goi ham tinh tong

    printf("Tong cac so da nhap = %lld\n", kq);

    return 0;
}

/*
Thuat toan:
- Nguoi dung nhap tung so nguyen dang chuoi de tranh tran khi nhap.
    + input : 10000000000000 (khong nhap : 1e8)
- Moi chuoi duoc kiem tra:
    + Ky tu dau co the la dau tru '-'
    + Cac ky tu con lai phai la chu so '0'..'9'
- Neu hop le thi chuyen chuoi sang so long long bang cong don he 10.
- Moi so nhap vao duoc cong vao tong neu khong lam tran tong.
- Neu cong bi tran thi bo qua so do va thong bao cho nguoi dung.
- Nguoi dung nhap 0 thi dung va in tong cuoi cung.
*/
