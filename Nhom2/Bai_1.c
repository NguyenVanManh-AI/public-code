#include <stdio.h>
#include <math.h>

#define EPS 1e-9   // dung cho so sanh double

/* Ham nhap mot canh tam giac (su dung cach nhap cua bai truoc) */
double nhap_canh(const char *ten) 
{
    double x;
    while (1)
    {
        printf("Nhap canh %s: ", ten);

        // so thuc, nguyen -> return 1 , cac truong hop khac (abc, empty,... ) return 0 
        if (scanf("%lf", &x) == 1 && x > 0) // doc mot gia tri hop le tu ban phim
            return x;

        printf("Gia tri khong hop le, phai > 0. Nhap lai.\n");

        while (getchar() != '\n'); // xoa bo dem
    }
}

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
    if (fabs(a - b) < EPS && fabs(b - c) < EPS) {
        printf("Tam giac deu\n"); // 3 canh bang nhau
    } 
    else if (fabs(a - b) < EPS || fabs(a - c) < EPS || fabs(b - c) < EPS) {

        /* co 2 canh bang nhau */
        /* kiem tra them tam giac vuong can */
        double a2 = a * a, b2 = b * b, c2 = c * c;

        if (fabs(a2 + b2 - c2) < EPS ||
            fabs(a2 + c2 - b2) < EPS ||
            fabs(b2 + c2 - a2) < EPS)
        {
            printf("Tam giac vuong can\n");
        } 
        else {
            printf("Tam giac can\n");
        }
    } 
    else {
        /* khong canh nao bang nhau */
        double a2 = a * a, b2 = b * b, c2 = c * c;

        if (fabs(a2 + b2 - c2) < EPS ||
            fabs(a2 + c2 - b2) < EPS ||
            fabs(b2 + c2 - a2) < EPS)
        {
            printf("Tam giac vuong\n"); // dung dinh li Py-ta-go
        } 
        else {
            printf("Tam giac thuong\n");
        }
    }
}

/* Ham nhap 3 canh – GIỮ COMMENT CŨ, nhưng thay nội dung bằng nhap_canh */
void nhap_3_canh(double *a, double *b, double *c) {
    // Giữ nguyên comment gốc:
    *a = nhap_canh("a");

    *b = nhap_canh("b");

    *c = nhap_canh("c");
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
