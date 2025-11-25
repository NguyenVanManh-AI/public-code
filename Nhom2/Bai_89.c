#include <stdio.h>
#include <string.h>

#define MAX 1000

// Ham dao chuoi
void dao_chuoi(char s[]) {  
    int i, j;
    char temp;
    i = 0;
    j = strlen(s) - 1;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// Ham xoa dau 0 o dau chuoi ket qua
void xoa_0_dau(char s[]) {
    int i = 0, j = 0;
    while (s[i] == '0' && s[i] != '\0') {
        i++;
    }
    while (s[i] != '\0') {
        s[j++] = s[i++];
    }
    s[j] = '\0';
    if (strlen(s) == 0) {
        strcpy(s, "0");
    }
}

// So sanh hai so lon (tra ve 1: a>b, -1: a<b, 0: a=b)
int so_sanh(char a[], char b[]) {
    if (strlen(a) > strlen(b)) return 1;
    if (strlen(a) < strlen(b)) return -1;
    return strcmp(a, b);
}

// Ham cong hai so lon
void cong_so_lon(char a[], char b[], char kq[]) {
    char x[MAX], y[MAX];
    strcpy(x, a);
    strcpy(y, b);
    dao_chuoi(x);
    dao_chuoi(y);

    int carry = 0, i;
    int lenx = strlen(x), leny = strlen(y);
    int maxlen = lenx > leny ? lenx : leny;

    for (i = 0; i < maxlen; i++) {
        int so1 = (i < lenx) ? x[i] - '0' : 0;
        int so2 = (i < leny) ? y[i] - '0' : 0;
        int tong = so1 + so2 + carry;
        kq[i] = tong % 10 + '0';
        carry = tong / 10;
    }

    if (carry > 0) {
        kq[i++] = carry + '0';
    }
    kq[i] = '\0';
    dao_chuoi(kq);
}

// Ham tru hai so lon (a - b), gia su a >= b
void tru_so_lon(char a[], char b[], char kq[]) {
    char x[MAX], y[MAX];
    strcpy(x, a);
    strcpy(y, b);
    dao_chuoi(x);
    dao_chuoi(y);

    int lenx = strlen(x), leny = strlen(y);
    int i, borrow = 0;

    for (i = 0; i < lenx; i++) {
        int so1 = x[i] - '0';
        int so2 = (i < leny) ? y[i] - '0' : 0;
        so1 -= borrow;

        if (so1 < so2) {
            so1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        kq[i] = (so1 - so2) + '0';
    }

    kq[i] = '\0';
    dao_chuoi(kq);
    xoa_0_dau(kq);
}

// Ham main
int main() {
    char a[MAX], b[MAX], kq[MAX];
    int lua_chon;

    printf("Nhap so thu nhat: ");
    scanf("%s", a);
    printf("Nhap so thu hai: ");
    scanf("%s", b);

    printf("Chon phep toan (1: cong, 2: tru): ");
    scanf("%d", &lua_chon);

    if (lua_chon == 1) {
        cong_so_lon(a, b, kq);
        printf("\nKet qua cong: %s\n", kq);
    }
    else if (lua_chon == 2) {
        int ss = so_sanh(a, b);
        if (ss == 0) {
            printf("\nKet qua tru: 0\n");
        }
        else if (ss == 1) {  // a > b
            tru_so_lon(a, b, kq);
            printf("\nKet qua tru: %s\n", kq);
        }
        else {  // a < b -> ket qua am
            tru_so_lon(b, a, kq);
            printf("\nKet qua tru: -%s\n", kq);
        }
    }
    else {
        printf("Lua chon khong hop le!\n");
    }

    return 0;
}
