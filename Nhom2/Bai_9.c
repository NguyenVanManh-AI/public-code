#include <stdio.h>

/* Ham tinh tong theo thu tu tu trai sang phai (1 -> n) */
double tinh_trai_sang_phai(int n)
{
    int i;
    double tong = 0.0; // khoi tao tong

    for (i = 1; i <= n; i++) // TANG DAN
    {
        if (i % 2 == 0)
            tong -= 1.0 / i;  // so chan thi tru
        else
            tong += 1.0 / i;  // so le thi cong
    }
    return tong;
}

/* Ham tinh tong theo thu tu nguoc lai tu phai sang trai (n -> 1) */
double tinh_phai_sang_trai(int n)
{
    int i;
    double tong = 0.0;

    for (i = n; i >= 1; i--) // GIAM DAN
    {
        if (i % 2 == 0)
            tong -= 1.0 / i;  // chan tru
        else
            tong += 1.0 / i;  // le cong
    }
    return tong;
}

/* Ham tach thanh 2 tong: s1 (le) va s2 (chan), sau do tra ve s1 - s2 */
double tinh_tach_s1_s2(int n)
{
    int i;
    double s1 = 0.0; // tong cac so hang le
    double s2 = 0.0; // tong cac so hang chan

    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            s2 += 1.0 / i;  // cong vao tong chan
        else
            s1 += 1.0 / i;  // cong vao tong le
    }

    return s1 - s2; // theo cong thuc
}

/* Ham xu ly chinh: tinh 3 kieu tong va so sanh */
void xu_ly()
{
    int n = 10000; // so muc lay gan

    // a. tinh tu trai sang phai
    double kq_a = tinh_trai_sang_phai(n);
    printf("a. Tong tinh tu trai sang phai: %.15lf\n", kq_a); // 0.693097183059959

    // b. tinh tu phai sang trai
    double kq_b = tinh_phai_sang_trai(n);
    printf("b. Tong tinh tu phai sang trai: %.15lf\n", kq_b); // 0.693097183059945

    // c. tong theo cach tach s1 - s2
    double kq_c = tinh_tach_s1_s2(n);
    printf("c. Tong s1 - s2: %.15lf\n", kq_c); // 0.693097183059952

    // d. so sanh kq_b va kq_c
    if (kq_b == kq_c)
        printf("d. Ket qua b va c bang nhau\n");
    else
        printf("d. Ket qua b va c khac nhau\n");

    printf("   Ly do khac nhau: do sai so cham phan floating point khi tinh theo thu tu khac nhau.\n");
}

int main()
{
    xu_ly(); // goi ham xu ly
    return 0;
}

/*
THUAT TOAN & CAC BUOC CHINH:

1. Tinh tong dang S = 1/1 - 1/2 + 1/3 - 1/4 + ... ± 1/n theo 3 cach:
   - Cach 1: cong tru tu trai sang phai (1 -> n)
   - Cach 2: cong tru tu phai sang trai (n -> 1)
   - Cach 3: tach tong thanh:
        s1 = tong cac so hang le
        s2 = tong cac so hang chan
        ket qua = s1 - s2

2. Do ban chat so thuc double, tinh theo thu tu khac nhau se tao ra sai so cham phan khac nhau.
   -> Do cac so 1/n rat nho, cong tru lon voi nho gay mat do chinh xac.
   -> Ket qua b va c thuong gan nhu bang nhau nhung van lech o chu so cuoi.

3. Bai toan dung de minh hoa anh huong cua floating point va thu tu tinh toan.
    - vi du: 0.1 + 0.2 trong may tinh cho ra 0.30000000000000004 thay vi 0.3
    - ly do: 0.1 va 0.2 khong bieu dien chinh xac trong he nhi phan nen bi lam tron
    - khi cong nhieu so thuc nho nhu 1/10000 + 1/10001 sai so tich luy thanh lon hon
    - do thu tu cong khac nhau nen sai so lam ket qua cuoi khac nhau mot chut
*/
