#include <stdio.h>
#include <math.h>

#define EPSILON 1e-12   // chính xác hơn cho double

// ham kiem tra gia tri double co hop le cho canh tam giac hay khong
double nhap_canh(const char *ten)
{
    double x;
    while (1)
    {
        printf("Nhap canh %s: ", ten);

        if (scanf("%lf", &x) == 1 && x > 0)
            return x;

        printf("Gia tri khong hop le, phai > 0. Nhap lai.\n");
        while (getchar() != '\n'); // xoa bo dem
    }
}

// ham kiem tra 3 canh co tao thanh tam giac hay khong
int la_tam_giac(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// ham tinh dien tich tam giac (Heron)
double dien_tich(double a, double b, double c)
{
    double p = (a + b + c) / 2.0;
    double S2 = p * (p - a) * (p - b) * (p - c);

    if (S2 <= EPSILON) return 0; // tam giac suy bien

    return sqrt(S2);
}

// ham tinh chieu cao
void tinh_chieu_cao(double a, double b, double c)
{
    double S = dien_tich(a, b, c);
    if (S == 0)
    {
        printf("Tam giac suy bien → khong co chieu cao.\n");
        return;
    }

    printf("Chieu cao ha = %.6lf\n", 2*S/a);
    printf("Chieu cao hb = %.6lf\n", 2*S/b);
    printf("Chieu cao hc = %.6lf\n", 2*S/c);
}

// ham tinh duong trung tuyen
void tinh_trung_tuyen(double a, double b, double c)
{
    printf("Trung tuyen ma = %.6lf\n", sqrt(2*b*b + 2*c*c - a*a)/2);
    printf("Trung tuyen mb = %.6lf\n", sqrt(2*a*a + 2*c*c - b*b)/2);
    printf("Trung tuyen mc = %.6lf\n", sqrt(2*a*a + 2*b*b - c*c)/2);
}

// ham tinh duong phan giac
void tinh_phan_giac(double a, double b, double c)
{
    printf("Phan giac la = %.6lf\n", sqrt(b*c * (1 - a*a/((b+c)*(b+c)))));
    printf("Phan giac lb = %.6lf\n", sqrt(a*c * (1 - b*b/((a+c)*(a+c)))));
    printf("Phan giac lc = %.6lf\n", sqrt(a*b * (1 - c*c/((a+b)*(a+b)))));
}

// ham tinh ban kinh noi tiep va ngoai tiep
void tinh_ban_kinh(double a, double b, double c)
{
    double S = dien_tich(a, b, c);
    double p = (a + b + c)/2.0;

    if (S == 0)
    {
        printf("Tam giac suy bien → khong ton tai ban kinh noi/ngoai tiep.\n");
        return;
    }

    printf("Ban kinh noi tiep r = %.6lf\n", S/p);
    printf("Ban kinh ngoai tiep R = %.6lf\n", a*b*c/(4*S));
}

void xu_ly()
{
    printf("Nhap ba canh cua tam giac\n");

    double a = nhap_canh("a");
    double b = nhap_canh("b");
    double c = nhap_canh("c");

    if (!la_tam_giac(a, b, c))
    {
        printf("Ba canh khong tao thanh tam giac.\n");
        return;
    }

    if (fabs(a + b - c) < EPSILON ||
        fabs(a + c - b) < EPSILON ||
        fabs(b + c - a) < EPSILON)
    {
        printf("Day la tam giac SUY BIEN.\n");
        return;
    }

    printf("\n=== Ket qua tinh toan ===\n");

    // a. chieu cao
    tinh_chieu_cao(a, b, c);

    // b. duong trung tuyen
    tinh_trung_tuyen(a, b, c);

    // c. duong phan giac
    tinh_phan_giac(a, b, c);

    // d. ban kinh noi tiep & ngoai tiep
    tinh_ban_kinh(a, b, c);
}

int main()
{
    xu_ly();
    return 0;
}

/*
Thuat toan:
- Nhap lan luot a, b, c theo dung chuan C
- Kiem tra dieu kien tam giac: a + b > c, ...
- Tinh dien tich theo cong thuc Heron
- Dung cong thuc h = 2S / a de tinh chieu cao
- Cong thuc trung tuyen: ma = sqrt(2b^2 + 2c^2 - a^2)/2
- Cong thuc phan giac: la = sqrt(b*c*(1 - a^2/(b+c)^2))
- Ban kinh noi tiep r = S/p
- Ban kinh ngoai tiep R = abc/(4S)
Tat ca tinh toan dung theo chuan so thuc cua C, dung ham rieng de tach ro bai toan.
*/
