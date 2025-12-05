#include <stdio.h>
#include <math.h>

#define EPSILON 1e-12   // nguong sai so de so sanh so thuc

/* ham kiem tra va nhap vao mot canh tam giac, dam bao canh > 0 */
double nhap_canh(const char *ten)
{
    double x;
    while (1)
    {
        printf("Nhap canh %s: ", ten);

        if (scanf("%lf", &x) == 1 && x > 0)   // kiem tra nhap dung va x > 0
            return x;

        printf("Gia tri khong hop le, phai > 0. Nhap lai.\n");
        while (getchar() != '\n'); // xoa bo dem de tranh doc nham lan sau
    }
}

/* ham kiem tra 3 so co tao thanh tam giac hay khong */
int la_tam_giac(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);  // dieu kien tam giac
}

/* ham tinh dien tich tam giac bang cong thuc Heron */
double dien_tich(double a, double b, double c)
{
    double p = (a + b + c) / 2.0;        // nua chu vi
    double S2 = p * (p - a) * (p - b) * (p - c); // S^2

    if (S2 <= EPSILON) return 0; // kiem tra tam giac suy bien

    return sqrt(S2); // tra ve dien tich
}

/* ham tinh ba chieu cao tu a, b, c */
void tinh_chieu_cao(double a, double b, double c)
{
    double S = dien_tich(a, b, c); // goi lai ham tinh dien tich
    if (S == 0)
    {
        printf("Tam giac suy bien -> khong co chieu cao.\n");
        return;
    }

    printf("Chieu cao ha = %.6lf\n", 2*S/a); // cong thuc h = 2S/a
    printf("Chieu cao hb = %.6lf\n", 2*S/b);
    printf("Chieu cao hc = %.6lf\n", 2*S/c);
}

/* ham tinh ba duong trung tuyen cua tam giac */
void tinh_trung_tuyen(double a, double b, double c)
{
    printf("Trung tuyen ma = %.6lf\n", sqrt(2*b*b + 2*c*c - a*a)/2); // cong thuc trung tuyen
    printf("Trung tuyen mb = %.6lf\n", sqrt(2*a*a + 2*c*c - b*b)/2);
    printf("Trung tuyen mc = %.6lf\n", sqrt(2*a*a + 2*b*b - c*c)/2);
}

/* ham tinh ba duong phan giac cua tam giac */
void tinh_phan_giac(double a, double b, double c)
{
    printf("Phan giac la = %.6lf\n", sqrt(b*c * (1 - a*a/((b+c)*(b+c))))); // cong thuc phan giac
    printf("Phan giac lb = %.6lf\n", sqrt(a*c * (1 - b*b/((a+c)*(a+c)))));
    printf("Phan giac lc = %.6lf\n", sqrt(a*b * (1 - c*c/((a+b)*(a+b)))));
}

/* ham tinh ban kinh noi tiep va ban kinh ngoai tiep cua tam giac */
void tinh_ban_kinh(double a, double b, double c)
{
    double S = dien_tich(a, b, c);  // dien tich tam giac
    double p = (a + b + c)/2.0;     // nua chu vi

    if (S == 0)
    {
        printf("Tam giac suy bien -> khong ton tai ban kinh noi/ngoai tiep.\n");
        return;
    }

    printf("Ban kinh noi tiep r = %.6lf\n", S/p);          // r = S/p
    printf("Ban kinh ngoai tiep R = %.6lf\n", a*b*c/(4*S)); // R = abc/(4S)
}

/* ham xu ly chinh: nhap du lieu, kiem tra va tinh toan */
void xu_ly()
{
    printf("Nhap ba canh cua tam giac\n");

    double a = nhap_canh("a"); // nhap canh a
    double b = nhap_canh("b"); // nhap canh b
    double c = nhap_canh("c"); // nhap canh c

    if (!la_tam_giac(a, b, c))  // neu khong phai tam giac
    {
        printf("Ba canh khong tao thanh tam giac.\n");
        return;
    }

    if (fabs(a + b - c) < EPSILON ||
        fabs(a + c - b) < EPSILON ||
        fabs(b + c - a) < EPSILON)  // kiem tra suy bien
    {
        printf("Day la tam giac suy bien.\n");
        return;
    }

    printf("\n=== Ket qua tinh toan ===\n");

    tinh_chieu_cao(a, b, c);      // goi ham tinh chieu cao
    tinh_trung_tuyen(a, b, c);    // goi ham tinh trung tuyen
    tinh_phan_giac(a, b, c);      // goi ham tinh phan giac
    tinh_ban_kinh(a, b, c);       // goi ham tinh ban kinh noi/ngoai tiep
}

int main()
{
    xu_ly(); // goi ham xu ly
    return 0;
}

/*
Thuat toan:
- Nhap 3 canh a, b, c (tat ca phai > 0)
- Kiem tra dieu kien tao thanh tam giac: a + b > c, a + c > b, b + c > a
- Neu suy bien thi ket thuc (a + b = c hoac tuong tu)
- Tinh dien tich bang cong thuc Heron: 
      p = (a + b + c) / 2
      S = sqrt(p * (p - a) * (p - b) * (p - c))
- Tinh chieu cao: ha = 2S / a, hb = 2S / b, hc = 2S / c
- Tinh trung tuyen:
      ma = sqrt(2b*b + 2c*c - a*a) / 2
      mb = sqrt(2a*a + 2c*c - b*b) / 2
      mc = sqrt(2a*a + 2b*b - c*c) / 2
- Tinh phan giac:
      la = sqrt(b*c * (1 - a*a / ((b + c)*(b + c))))
      lb = sqrt(a*c * (1 - b*b / ((a + c)*(a + c))))
      lc = sqrt(a*b * (1 - c*c / ((a + b)*(a + b))))
- Tinh ban kinh noi tiep r = S / p
- Tinh ban kinh ngoai tiep R = (a * b * c) / (4 * S)
*/
