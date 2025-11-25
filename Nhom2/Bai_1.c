#include <stdio.h>

/* ham kiem tra co phai tam giac hay khong */
int la_tam_giac(float a, float b, float c) {
    /* dieu kien tam giac */
    if (a > 0 && b > 0 && c > 0 &&
        a + b > c &&
        a + c > b &&
        b + c > a) {
        return 1;
    }
    return 0;
}

/* ham xac dinh loai tam giac */
void loai_tam_giac(float a, float b, float c) {
    /* tam giac deu */
    if (a == b && b == c) {
        printf("Tam giac deu\n");
        return;
    }

    /* tam giac can */
    if (a == b || a == c || b == c) {
        /* tam giac can vuong */
        if (a*a + b*b == c*c ||
            a*a + c*c == b*b ||
            b*b + c*c == a*a) {
            printf("Tam giac vuong can\n");
            return;
        }
        printf("Tam giac can\n");
        return;
    }

    /* tam giac vuong */
    if (a*a + b*b == c*c ||
        a*a + c*c == b*b ||
        b*b + c*c == a*a) {
        printf("Tam giac vuong\n");
        return;
    }

    /* tam giac thuong */
    printf("Tam giac thuong\n");
}

int main() {
    float a, b, c;

    /* nhap ba canh */
    printf("Nhap canh a: ");
    scanf("%f", &a);

    printf("Nhap canh b: ");
    scanf("%f", &b);

    printf("Nhap canh c: ");
    scanf("%f", &c);

    /* kiem tra tam giac */
    if (la_tam_giac(a, b, c)) {
        printf("Day la ba canh cua tam giac\n");
        loai_tam_giac(a, b, c);
    } else {
        printf("Khong phai ba canh cua tam giac\n");
    }

    return 0;
}
