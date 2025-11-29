#include <stdio.h>
#include <math.h>

// ham kiem tra gia tri float co hop le cho canh tam giac hay khong
float nhap_canh(const char *ten)
{
    float x;
    while (1)
    {
        printf("Nhap canh %s: ", ten);
        scanf("%f", &x);

        if (x > 0)
            return x;

        printf("Gia tri khong hop le, phai > 0. Nhap lai.\n");
    }
}

// ham kiem tra 3 canh co tao thanh tam giac hay khong
int la_tam_giac(float a, float b, float c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// ham tinh dien tich tam giac (Heron)
float dien_tich(float a, float b, float c)
{
    float p = (a + b + c) / 2.0f;   // nua chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// ham tinh chieu cao
void tinh_chieu_cao(float a, float b, float c)
{
    float S = dien_tich(a, b, c);

    float ha = 2 * S / a;
    float hb = 2 * S / b;
    float hc = 2 * S / c;

    printf("Chieu cao ha = %.6f\n", ha);
    printf("Chieu cao hb = %.6f\n", hb);
    printf("Chieu cao hc = %.6f\n", hc);
}

// ham tinh duong trung tuyen
void tinh_trung_tuyen(float a, float b, float c)
{
    float ma = sqrt(2*b*b + 2*c*c - a*a) / 2.0f;
    float mb = sqrt(2*a*a + 2*c*c - b*b) / 2.0f;
    float mc = sqrt(2*a*a + 2*b*b - c*c) / 2.0f;

    printf("Trung tuyen ma = %.6f\n", ma);
    printf("Trung tuyen mb = %.6f\n", mb);
    printf("Trung tuyen mc = %.6f\n", mc);
}

// ham tinh duong phan giac
void tinh_phan_giac(float a, float b, float c)
{
    float la = sqrt(b*c * (1 - (a*a) / ((b + c)*(b + c))));
    float lb = sqrt(a*c * (1 - (b*b) / ((a + c)*(a + c))));
    float lc = sqrt(a*b * (1 - (c*c) / ((a + b)*(a + b))));

    printf("Phan giac la = %.6f\n", la);
    printf("Phan giac lb = %.6f\n", lb);
    printf("Phan giac lc = %.6f\n", lc);
}

// ham tinh ban kinh noi tiep va ngoai tiep
void tinh_ban_kinh(float a, float b, float c)
{
    float S = dien_tich(a, b, c);
    float p = (a + b + c) / 2.0f;

    float r = S / p;      // ban kinh noi tiep
    float R = (a*b*c) / (4.0f * S);  // ban kinh ngoai tiep

    printf("Ban kinh noi tiep r = %.6f\n", r);
    printf("Ban kinh ngoai tiep R = %.6f\n", R);
}

// ham xu ly chinh
void xu_ly()
{
    printf("Nhap ba canh cua tam giac\n");
    float a = nhap_canh("a");
    float b = nhap_canh("b");
    float c = nhap_canh("c");

    if (!la_tam_giac(a, b, c))
    {
        printf("Ba canh khong tao thanh tam giac.\n");
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
