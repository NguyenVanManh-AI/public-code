#include <stdio.h>
#include <math.h>

/* Ham nhap mot so nguyen tu nhien n (0 <= n <= 99) */
/* Xu ly truong hop nhap sai dinh dang hoac nhap so thuc */
int nhap_so_tu_nhien() {
    double x; // bien tam luu gia tri nhap
    int n;    // bien so nguyen hop le

    while (1) {
        printf("Nhap n (0 <= n <= 99): ");

        if (scanf("%lf", &x) == 1) { // nhap thanh cong
            if (x == (int)x) {       // kiem tra x co phai so nguyen
                n = (int)x;
                if (n >= 0 && n <= 99)
                    return n;       // hop le
            }
        }

        printf("Gia tri khong hop le. Nhap lai!\n");
        while (getchar() != '\n'); // xoa bo dem
    }
}

/* Ham tinh tong lap phuong cac chu so cua n */
int tong_lap_phuong(int n) {
    int sum = 0; // tong
    int temp = n;
    int digit;   // bien luu tung chu so

    while (temp > 0) {
        digit = temp % 10;                  // lay chu so cuoi
        sum += digit * digit * digit;       // lap phuong chu so
        temp /= 10;                         // bo chu so cuoi
    }

    return sum;
}

/* Ham kiem tra n^2 co bang tong lap phuong cac chu so hay khong */
int kiem_tra(int n) {
    int n2 = n * n;                 // tinh n binh phuong
    int tong = tong_lap_phuong(n);  // tong lap phuong

    return n2 == tong;              // tra ve 1 neu bang nhau
}

int main() {
    int n = nhap_so_tu_nhien(); // nhap n

    if (kiem_tra(n)) {
        printf("Dung: n^2 = tong lap phuong cac chu so cua n\n");
    } else {
        printf("Sai: n^2 khong bang tong lap phuong cac chu so cua n\n");
    }

    return 0;
}

/*
Thuat toan:
- Nhap n theo dung chuan (xu ly nhap sai, nhap so thuc, nhap so vuot qua 99)
- Tach tung chu so cua n, tinh tong lap phuong
- So sanh n^2 voi tong lap phuong cac chu so
- Neu bang nhau → dung, nguoc lai → sai
*/
