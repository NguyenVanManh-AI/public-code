#include <stdio.h>
#include <math.h>

/* ham kiem tra 3 canh co tao thanh tam giac hay khong
   dieu kien: a + b > c, a + c > b, b + c > a */
int la_tam_giac(double a, double b, double c) {
    if (a > 0 && b > 0 && c > 0 &&
        a + b > c &&
        a + c > b &&
        b + c > a) {
        return 1;
    }
    return 0;
}

/* ham tinh nua chu vi
   p = (a + b + c) / 2 */
double nua_chu_vi(double a, double b, double c) {
    return (a + b + c) / 2.0;
}

/* ham tinh dien tich theo cong thuc heron
   S = sqrt(p * (p - a) * (p - b) * (p - c)) */
double dien_tich(double a, double b, double c) {
    double p;
    p = nua_chu_vi(a, b, c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/* ham tinh duong cao tu canh a
   ha = 2S / a */
double duong_cao(double a, double dien_tich) {
    return (2.0 * dien_tich) / a;
}

/* ham tinh trung tuyen tu dinh A ung voi canh a
   ma = sqrt(2b^2 + 2c^2 - a^2) / 2 */
double trung_tuyen(double a, double b, double c) {
    return sqrt(2.0 * (b * b + c * c) - a * a) / 2.0;
}

/* ham tinh duong phan giac tu dinh A ung voi canh a
   la = sqrt(b * c * (1 - a^2 / (b + c)^2)) */
double phan_giac(double a, double b, double c) {
    return sqrt(b * c * (1.0 - (a * a) / ((b + c) * (b + c))));
}

/* ban kinh duong tron noi tiep
   r = S / p */
double ban_kinh_noi_tiep(double dien_tich, double p) {
    return dien_tich / p;
}

/* ban kinh duong tron ngoai tiep
   R = abc / (4S) */
double ban_kinh_ngoai_tiep(double a, double b, double c, double dien_tich) {
    return (a * b * c) / (4.0 * dien_tich);
}

int main() {
    double a, b, c;
    double p, s;
    double ha, hb, hc;
    double ma, mb, mc;
    double la, lb, lc;
    double r, R;

    printf("Nhap canh a: ");
    scanf("%lf", &a);

    printf("Nhap canh b: ");
    scanf("%lf", &b);

    printf("Nhap canh c: ");
    scanf("%lf", &c);

    /* kiem tra tam giac */
    if (!la_tam_giac(a, b, c)) {
        printf("Ba gia tri khong tao thanh tam giac\n");
        return 0;
    }

    /* tinh nua chu vi va dien tich */
    p = nua_chu_vi(a, b, c);
    s = dien_tich(a, b, c);

    /* tinh cac duong cao */
    ha = duong_cao(a, s);
    hb = duong_cao(b, s);
    hc = duong_cao(c, s);

    /* tinh cac trung tuyen */
    ma = trung_tuyen(a, b, c);
    mb = trung_tuyen(b, a, c);
    mc = trung_tuyen(c, a, b);

    /* tinh cac phan giac */
    la = phan_giac(a, b, c);
    lb = phan_giac(b, a, c);
    lc = phan_giac(c, a, b);

    /* tinh ban kinh noi tiep va ngoai tiep */
    r = ban_kinh_noi_tiep(s, p);
    R = ban_kinh_ngoai_tiep(a, b, c, s);

    printf("\n--- Ket qua ---\n");

    printf("Duong cao ha = %.4f\n", ha);
    printf("Duong cao hb = %.4f\n", hb);
    printf("Duong cao hc = %.4f\n", hc);

    printf("Trung tuyen ma = %.4f\n", ma);
    printf("Trung tuyen mb = %.4f\n", mb);
    printf("Trung tuyen mc = %.4f\n", mc);

    printf("Phan giac la = %.4f\n", la);
    printf("Phan giac lb = %.4f\n", lb);
    printf("Phan giac lc = %.4f\n", lc);

    printf("Ban kinh noi tiep r = %.4f\n", r);
    printf("Ban kinh ngoai tiep R = %.4f\n", R);

    return 0;
}
