#include <stdio.h>

/* ham tinh tu trai sang phai */
double tinh_trai_sang_phai() {
    int i;
    double sum;
    sum = 0.0;

    for (i = 1; i <= 10000; i++) {
        if (i % 2 == 1) {
            sum = sum + 1.0 / i;   /* so le cong */
        } else {
            sum = sum - 1.0 / i;   /* so chan tru */
        }
    }

    return sum;
}

/* ham tinh tu phai sang trai */
double tinh_phai_sang_trai() {
    int i;
    double sum;
    sum = 0.0;

    for (i = 10000; i >= 1; i--) {
        if (i % 2 == 1) {
            sum = sum + 1.0 / i;
        } else {
            sum = sum - 1.0 / i;
        }
    }

    return sum;
}

/* ham tinh tong s1 = 1 + 1/3 + 1/5 + ... + 1/9999 */
double tinh_s1() {
    int i;
    double sum;
    sum = 0.0;

    for (i = 1; i <= 9999; i += 2) {
        sum = sum + 1.0 / i;
    }

    return sum;
}

/* ham tinh tong s2 = 1/2 + 1/4 + ... + 1/10000 */
double tinh_s2() {
    int i;
    double sum;
    sum = 0.0;

    for (i = 2; i <= 10000; i += 2) {
        sum = sum + 1.0 / i;
    }

    return sum;
}

int main() {
    double a, b, s1, s2;

    a = tinh_trai_sang_phai(); 
    b = tinh_phai_sang_trai(); 
    s1 = tinh_s1();
    s2 = tinh_s2();

    printf("Ket qua tu trai sang phai: %.15f\n", a); // 0.693097183059959
    printf("Ket qua tu phai sang trai: %.15f\n", b); // 0.693097183059945

    printf("s1 = %.15f\n", s1); // 5.240351609552156
    printf("s2 = %.15f\n", s2); // 4.547254426492204

    /* giai thich: do sai so tich luy cua so thuc */
    printf("Ly do cach tinh cau a (trai sang phai) va b (phai sang trai) khac nhau: do sai so khi cong so thuc floating point.\n");

    return 0;
}
/*
Cong so thuc (double) bi sai so vi may tinh chi luu duoc so luong bit huu han.
Khi cong so lon truoc, sai so cua so nho bi nuot mat.
Khi cong so nho truoc, ket qua chinh xac hon vi sai so it bi cong don.
*/
