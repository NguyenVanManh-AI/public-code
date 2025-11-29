#include <stdio.h>
#include <math.h>

/* Ham kiem tra co phai tam giac hay khong */
int la_tam_giac(double a, double b, double c) {
    /* Kiem tra dieu kien tam giac: tong 2 canh lon hon canh con lai */
    if (a + b > c && a + c > b && b + c > a) {
        return 1; // la tam giac
    }
    return 0;     // khong phai tam giac
}

/* Ham kiem tra loai tam giac */
void loai_tam_giac(double a, double b, double c) {
    if (a == b && b == c) {
        printf("Tam giac deu\n"); // 3 canh bang nhau
    } else if (a == b || a == c || b == c) {
        /* co 2 canh bang nhau */
        /* kiem tra them tam giac vuong can */
        double a2, b2, c2;
        a2 = a * a;
        b2 = b * b;
        c2 = c * c;
        if (fabs(a2 + b2 - c2) < 1e-9 ||
            fabs(a2 + c2 - b2) < 1e-9 ||
            fabs(b2 + c2 - a2) < 1e-9) {
            printf("Tam giac vuong can\n");
        } else {
            printf("Tam giac can\n");
        }
    } else {
        /* khong canh nao bang nhau */
        double a2, b2, c2;
        a2 = a * a;
        b2 = b * b;
        c2 = c * c;

        if (fabs(a2 + b2 - c2) < 1e-9 ||
            fabs(a2 + c2 - b2) < 1e-9 ||
            fabs(b2 + c2 - a2) < 1e-9) {
            printf("Tam giac vuong\n"); // dung dinh li Py-ta-go
        } else {
            printf("Tam giac thuong\n");
        }
    }
}

/* Ham nhap 3 canh */
void nhap_3_canh(double *a, double *b, double *c) {
    printf("Nhap canh a: ");
    scanf("%lf", a); // nhap so thuc
    printf("Nhap canh b: ");
    scanf("%lf", b);
    printf("Nhap canh c: ");
    scanf("%lf", c);
}

int main(void) {
    double a, b, c; // khai bao bien truoc khi su dung

    nhap_3_canh(&a, &b, &c); // goi ham nhap

    if (!la_tam_giac(a, b, c)) {
        printf("Khong phai 3 canh cua tam giac\n");
        return 0;
    }

    printf("Day la 3 canh cua tam giac\n");
    loai_tam_giac(a, b, c); // in loai tam giac

    return 0;
}

/*
Thuat toan:
- Nhap 3 so thuc a, b, c.
- Kiem tra dieu kien tam giac: a + b > c, a + c > b, b + c > a.
- Neu khong thoa: khong phai tam giac.
- Neu co:
    + Kiem tra deu: a = b = c.
    + Kiem tra can: co 2 canh bang nhau.
    + Kiem tra vuong: a^2 + b^2 = c^2 (su dung sai so double).
    + Uu tien xuat:
        - Vuong can
        - Deu
        - Can
        - Vuong
        - Thuong
*/
