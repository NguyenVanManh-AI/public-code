#include <stdio.h>
#include <math.h>

// ham nhap mot canh cua tam giac
// IN "Nhap canh X: " chi lan dau, neu sai chi in "Gia tri khong hop le, nhap lai X:"
// va KHONG in lai "Nhap canh X:" lan thu 2
float nhap_canh(const char *ten)
{
    float x;
    char buffer[200];
    int lan_dau = 1;

    while (1)
    {
        if (lan_dau)
        {
            // in prompt lan dau tien
            printf("Nhap canh %s: ", ten);
        }

        // doc mot dong tu stdin (khong de lai ky tu trong buffer)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            // loi IO, yeu cau nhap lai (khong in prompt lan 2)
            printf("Gia tri khong hop le, nhap lai %s:", ten);
            lan_dau = 0;
            continue;
        }

        // neu nguoi dung nhan Enter rong (buffer chi co '\n') -> coi la sai
        {
            char tmp;
            // ktra xem buffer co chi la newline hay rong
            if (sscanf(buffer, " %c", &tmp) != 1)
            {
                printf("Gia tri khong hop le, nhap lai %s:", ten);
                lan_dau = 0;
                continue;
            }
        }

        // thu parse float tu dong vua doc
        if (sscanf(buffer, " %f", &x) == 1)
        {
            if (x > 0.0f)
            {
                return x; // hop le
            }
            else
            {
                // so <= 0 khong hop le
                printf("Gia tri khong hop le, phai > 0. Nhap lai %s:", ten);
                lan_dau = 0;
                continue;
            }
        }
        else
        {
            // parse khong duoc -> chuoi ko phai so
            printf("Gia tri khong hop le, nhap lai %s:", ten);
            lan_dau = 0;
            continue;
        }
    }
}

// kiem tra 3 canh co tao thanh tam giac hay khong
int la_tam_giac(float a, float b, float c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// dien tich theo Heron
float dien_tich(float a, float b, float c)
{
    float p = (a + b + c) / 2.0f;
    return sqrtf(p * (p - a) * (p - b) * (p - c));
}

// chieu cao
void tinh_chieu_cao(float a, float b, float c)
{
    float S = dien_tich(a, b, c);
    float ha = 2.0f * S / a;
    float hb = 2.0f * S / b;
    float hc = 2.0f * S / c;

    printf("Chieu cao ha = %.6f\n", ha);
    printf("Chieu cao hb = %.6f\n", hb);
    printf("Chieu cao hc = %.6f\n", hc);
}

// trung tuyen
void tinh_trung_tuyen(float a, float b, float c)
{
    float ma = sqrtf(2.0f*b*b + 2.0f*c*c - a*a) / 2.0f;
    float mb = sqrtf(2.0f*a*a + 2.0f*c*c - b*b) / 2.0f;
    float mc = sqrtf(2.0f*a*a + 2.0f*b*b - c*c) / 2.0f;

    printf("Trung tuyen ma = %.6f\n", ma);
    printf("Trung tuyen mb = %.6f\n", mb);
    printf("Trung tuyen mc = %.6f\n", mc);
}

// phan giac
void tinh_phan_giac(float a, float b, float c)
{
    float la = sqrtf(b*c * (1.0f - (a*a) / ((b + c)*(b + c))));
    float lb = sqrtf(a*c * (1.0f - (b*b) / ((a + c)*(a + c))));
    float lc = sqrtf(a*b * (1.0f - (c*c) / ((a + b)*(a + b))));

    printf("Phan giac la = %.6f\n", la);
    printf("Phan giac lb = %.6f\n", lb);
    printf("Phan giac lc = %.6f\n", lc);
}

// ban kinh noi tiep & ngoai tiep
void tinh_ban_kinh(float a, float b, float c)
{
    float S = dien_tich(a, b, c);
    float p = (a + b + c) / 2.0f;

    float r = S / p;
    float R = (a*b*c) / (4.0f * S);

    printf("Ban kinh noi tiep r = %.6f\n", r);
    printf("Ban kinh ngoai tiep R = %.6f\n", R);
}

// xu ly chinh
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
