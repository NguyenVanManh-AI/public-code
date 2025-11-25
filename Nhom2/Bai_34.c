#include <stdio.h>
#include <string.h>

/* ham kiem tra chuoi co chu so dung hay khong */
int kiem_tra_chu_so(char chuoi[]) {
    int i;
    int len;

    len = strlen(chuoi);

    /* kiem tra rong */
    if (len == 0) {
        return 0;
    }

    /* khong cho phep bat dau bang '0' */
    if (chuoi[0] == '0') {
        return 0;
    }

    /* kiem tra tung ky tu co phai la chu so */
    for (i = 0; i < len; i++) {
        if (chuoi[i] < '0' || chuoi[i] > '9') {
            return 0;
        }
    }

    return 1;
}

/* ham kiem tra tu doi xung */
int kiem_tra_doi_xung(char chuoi[]) {
    int i;
    int len;

    len = strlen(chuoi);

    for (i = 0; i < len / 2; i++) {
        if (chuoi[i] != chuoi[len - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char a[201];

    printf("Nhap chuoi so nguyen duong: ");
    scanf("%200s", a);

    if (!kiem_tra_chu_so(a)) {
        printf("Chuoi khong hop le hoac bat dau bang so 0\n");
    } else {
        if (kiem_tra_doi_xung(a)) {
            printf("Chuoi tu doi xung\n");
        } else {
            printf("Chuoi khong tu doi xung\n");
        }
    }

    return 0;
}
