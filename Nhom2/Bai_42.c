#include <stdio.h>
#include <ctype.h>
#include <limits.h>

/* Ham nhap so nguyen bat ky (co the rat lon), ket thuc khi nhap 0 */
long long nhap_so_nguyen() {
    char s[200];
    int i;

    while (1) {
        int hop_le = 1;

        printf("Nhap so (0 de dung): ");
        scanf("%s", s);

        /* Kiem tra chuoi chi gom dau tru hoac chu so */
        i = 0;
        if (s[0] == '-') i = 1;     // cho phep so am

        for (; s[i] != '\0'; i++) {
            if (!isdigit(s[i])) {
                hop_le = 0;
                break;
            }
        }

        if (hop_le) {
            long long x = 0;
            int am = (s[0] == '-');

            /* Chuyen chuoi -> long long, kiem tra tran so */
            for (i = am ? 1 : 0; s[i] != '\0'; i++) {
                int digit = s[i] - '0';

                /* Kiem tra tran so long long */
                if (x > (LLONG_MAX - digit) / 10) {
                    hop_le = 0;
                    break;
                }

                x = x * 10 + digit;
            }

            if (hop_le) {
                return am ? -x : x;
            }
        }

        printf("Gia tri khong hop le. Nhap lai.\n");
    }
}

/* Ham tinh tong */
long long tinh_tong() {
    long long tong = 0;
    long long x;

    while (1) {
        x = nhap_so_nguyen();

        if (x == 0)
            break;

        /* Kiem tra tran tong */
        if ((tong > 0 && x > LLONG_MAX - tong) ||
            (tong < 0 && x < LLONG_MIN - tong)) {
            printf("Tong bi tran! Khong the cong them so nay.\n");
            continue;
        }

        tong += x;
    }

    return tong;
}

int main() {
    long long kq = tinh_tong();

    printf("Tong cac so da nhap = %lld\n", kq);

    return 0;
}
