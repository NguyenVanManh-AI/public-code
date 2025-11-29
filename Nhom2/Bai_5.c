#include <stdio.h>
#include <math.h>

// ham kiem tra so thuc co phai la so nguyen dung nghia hay khong
int la_so_nguyen(float x)
{
    if (x == (int)x)
    {
        return 1;   // la so nguyen
    }
    return 0;       // khong phai so nguyen
}

// ham nhap so tu nhien voi ten bien (n1, n2, ...)
int nhap_so_tu_nhien_theo_ten(int index)
{
    float x;
    int lan_dau = 1;  // danh dau lan dau tien nhap

    while (1)
    {
        if (lan_dau == 1)
        {
            printf("n%d: ", index);   // chi in lan dau
        }

        scanf("%f", &x);

        if (la_so_nguyen(x) && (int)x >= 0)
        {
            return (int)x;           // tra ve so tu nhien hop le
        }

        // neu sai, thong bao nhung KHONG in lai "nX:" nua
        printf("Gia tri khong hop le, nhap lai, n%d: ", index);

        lan_dau = 0; // tu lan sau khong in "nX:" nua
    }
}

// ham tinh uscln 2 so theo thuat toan Euclid
int uscln_hai_so(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// ham tinh uscln nhieu so
int uscln_nhieu_so(int arr[], int m)
{
    int i;
    int kq = arr[0];

    for (i = 1; i < m; i++)
    {
        kq = uscln_hai_so(kq, arr[i]);
    }

    return kq;
}

// ham xu ly chinh
void xu_ly()
{
    int m;
    int i;
    int arr[1000];
    int tat_ca_zero = 1; // danh dau truong hop tat ca = 0

    // nhap so m
    float temp;
    printf("Nhap so luong m (m >= 2): ");
    while (1)
    {
        scanf("%f", &temp);

        if (la_so_nguyen(temp) && (int)temp >= 2)
        {
            m = (int)temp;
            break;
        }

        printf("Gia tri khong hop le, nhap lai: ");
    }

    // nhap n1..nm
    printf("Nhap %d so tu nhien:\n", m);
    for (i = 1; i <= m; i++)
    {
        arr[i - 1] = nhap_so_tu_nhien_theo_ten(i);
        if (arr[i - 1] != 0)
        {
            tat_ca_zero = 0; // neu co 1 so khac 0 -> khong phai tat ca zero
        }
    }

    // kiem tra truong hop tat ca = 0
    if (tat_ca_zero)
    {
        printf("Tat ca so tu nhien = 0, USCLN khong xac dinh\n");
    }
    else
    {
        printf("USCLN = %d\n", uscln_nhieu_so(arr, m));
    }
}

int main()
{
    xu_ly();
    return 0;
}

/*
Giai thich thuat toan:
- Kiem tra m phai la so nguyen dung nghia va >= 2
- Khi nhap tung n1, n2, n3,...:
    + In ra dung ten "nX:"
    + Neu sai (vi du 3.4), in: "Gia tri khong hop le, nhap lai, nX:"
- Neu tat ca so = 0 -> thong bao "USCLN khong xac dinh"
- Dung thuat toan Euclid de tinh USCLN 2 so
- Tinh USCLN nhie
*/