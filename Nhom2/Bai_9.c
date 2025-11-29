#include <stdio.h>

// ham tinh tong tu trai sang phai
double tinh_trai_sang_phai(int n)
{
    int i;
    double tong = 0.0;
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            tong -= 1.0 / i;  // so chan tru di
        else
            tong += 1.0 / i;  // so le cong len
    }
    return tong;
}

// ham tinh tong tu phai sang trai
double tinh_phai_sang_trai(int n)
{
    int i;
    double tong = 0.0;
    for (i = n; i >= 1; i--)
    {
        if (i % 2 == 0)
            tong -= 1.0 / i;
        else
            tong += 1.0 / i;
    }
    return tong;
}

// ham tinh s1 le + s2 chan va tra ve s1 - s2
double tinh_tach_s1_s2(int n)
{
    int i;
    double s1 = 0.0; // tong le
    double s2 = 0.0; // tong chan

    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            s2 += 1.0 / i;  // so chan
        else
            s1 += 1.0 / i;  // so le
    }

    return s1 - s2;
}

// ham xu ly chinh
void xu_ly()
{
    int n = 10000;

    // a. tinh tu trai sang phai
    double kq_a = tinh_trai_sang_phai(n);
    printf("a. Tong tinh tu trai sang phai: %.15lf\n", kq_a); // 0.693097183059959

    // b. tinh tu phai sang trai
    double kq_b = tinh_phai_sang_trai(n);
    printf("b. Tong tinh tu phai sang trai: %.15lf\n", kq_b); // 0.693097183059945

    // c. tinh s1 - s2
    double kq_c = tinh_tach_s1_s2(n);
    printf("c. Tong s1 - s2: %.15lf\n", kq_c); // 0.693097183059952

    // d. so sanh b va c
    if (kq_b == kq_c)
        printf("d. Ket qua b va c bang nhau\n");
    else
        printf("d. Ket qua b va c khac nhau\n");

    printf("   Ly do khac nhau: do sai so cham phan (floating point) khi cong tru cac so nho theo thu tu khac nhau.\n");
}

int main()
{
    xu_ly();
    return 0;
}

/*
Giai thich thuat toan:
- Ham tinh_trai_sang_phai: cong tru lien tiep tu 1 den n
- Ham tinh_phai_sang_trai: cong tru tu n ve 1
- Ham tinh_tach_s1_s2: tong le - tong chan
- KQ khac nhau: do cong thuc floating point khac nhau khi cong tru nhieu so nho theo thu tu khac
*/
