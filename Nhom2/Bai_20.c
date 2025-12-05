#include <stdio.h>
#include <math.h>

/* ham nhap n la so nguyen tu nhien tu 0 den 99 */
/* xu ly truong hop nhap sai dinh dang hoac nhap so thuc */
int nhap_so_tu_nhien() {
    double x; // luu gia tri nhap vao de bat loi so thuc
    int n;    // luu so nguyen hop le

    while (1) {
        printf("Nhap n (0 <= n <= 99): ");

        // scanf tra ve 1 neu nhap thanh cong 1 so double
        if (scanf("%lf", &x) == 1) {

            // kiem tra x co phai so nguyen (khong co phan thap phan)
            if (x == (int)x) {
                n = (int)x;

                // kiem tra n nam trong mien hop le
                if (n >= 0 && n <= 99)
                    return n;
            }
        }

        printf("Gia tri khong hop le. Nhap lai!\n");

        // xoa bo dem de tranh lap vo han khi nhap sai
        while (getchar() != '\n');
    }
}

/* ham tinh tong lap phuong cac chu so cua n */
int tong_lap_phuong(int n) {
    int sum = 0; // tong lap phuong
    int temp = n;
    int digit;   // chu so tach ra

    while (temp > 0) {

        // lay chu so cuoi
        digit = temp % 10;

        // cong vao tong lap phuong chu so
        sum += digit * digit * digit;

        // bo chu so cuoi
        temp /= 10;
    }

    return sum;
}

/* ham kiem tra xem n^2 co bang tong lap phuong cac chu so hay khong */
int kiem_tra(int n) {
    int n2 = n * n;                // n binh phuong
    int tong = tong_lap_phuong(n); // tong lap phuong cac chu so
    return n2 == tong;             // tra ve 1 neu bang nhau
}

int main() {
    int n = nhap_so_tu_nhien(); // nhap n dung chuan

    // kiem tra dieu kien n^2 = tong lap phuong cac chu so
    if (kiem_tra(n)) {
        printf("Dung: n^2 = tong lap phuong cac chu so cua n\n");
    } else {
        printf("Sai: n^2 khong bang tong lap phuong cac chu so cua n\n");
    }

    return 0;
}

/*
thuat toan:
- nhap n tu 0 den 99 va xu ly nhap sai dinh dang
- tach tung chu so cua n va tinh tong lap phuong chu so
- tinh n^2 va so sanh voi tong lap phuong
- neu hai gia tri bang nhau thi dung nguoc lai la sai
*/
