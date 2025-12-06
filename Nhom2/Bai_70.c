#include <stdio.h>

#define MAX 100 // so phan tu toi da cua mang

/** 
   Ham nhapMang: nhap mot mang so thuc double tu ban phim
   a: mang can nhap
   n: so phan tu cua mang (tra ve)
   ten: ky tu ten mang (A hoac B) de hien thi
 */
void nhapMang(double a[], int *n, const char ten) {
    int i; // bien lap
    printf("Nhap so phan tu mang %c: ", ten); // thong bao nhap so luong phan tu
    scanf("%d", n); // nhap so phan tu

    for (i = 0; i < *n; i++) { // vong lap nhap tung phan tu
        printf("%c[%d] = ", ten, i); // in ten mang va chi so
        scanf("%lf", &a[i]);    // nhap gia tri double
    }
}

/**
   Ham xuatMang: xuat mang ra man hinh voi dinh dang 6 chu so thap phan
 */
void xuatMang(double a[], int n, const char ten) {
    int i; // bien lap
    printf("%c: ", ten); // in ten mang
    for (i = 0; i < n; i++)
        printf("%.6lf ", a[i]);  // in voi 6 chu so sau dau phay
    printf("\n");
}

void gopMang(double a[], int nA, double b[], int *nB) {
    int i_a, i_b, j_b; // cac bien lap
    double x; // bien tam de chen

    for (i_a = 0; i_a < nA; i_a++) { // duyet tung phan tu cua A
        b[*nB] = a[i_a]; // them phan tu A vao cuoi mang B
        (*nB)++; // tang so phan tu B

        for (i_b = 1; i_b < *nB; i_b++) { // insertion sort
            x = b[i_b]; // lay gia tri tai vi tri can chen
            j_b = i_b - 1; // vi tri ke truoc

            while (j_b >= 0 && b[j_b] > x) { 
                b[j_b + 1] = b[j_b]; // day phan tu lon hon qua phai
                j_b--; // lui ve ben trai
            }

            b[j_b + 1] = x; // chen x vao dung vi tri
        }
    }
}

int main() {
    double A[MAX], B[MAX]; // khai bao mang A va B
    int nA, nB; // so phan tu A va B

    nhapMang(A, &nA, 'A'); // nhap mang A
    nhapMang(B, &nB, 'B'); // nhap mang B

    printf("\n--- MANG BAN DAU ---\n");
    xuatMang(A, nA, 'A'); // xuat A
    xuatMang(B, nB, 'B'); // xuat B

    gopMang(A, nA, B, &nB); // ghep A vao B

    printf("\n--- MANG B SAU KHI NOI A ---\n");
    xuatMang(B, nB, 'B'); // xuat B sau khi gop

    return 0;
}

/**
THUAT TOAN CHUONG TRINH
   1. Nhap mang A va mang B 
   2. In hai mang ban dau
   3. Goi gopMang:
        - Tung phan tu cua mang A duoc them vao cuoi mang B
        - Sau moi lan them, thuc hien sap xep tang dan bang insertion sort
   4. In ra mang B sau khi da gop va sap xep
LUU Y
   - Co the toi da 100 phan tu cho moi mang
   - Mang B duoc sap xep lai moi khi them mot phan tu moi
   - Su dung insertion sort (phu hop khi so luong phan tu tang dan tung buoc)
 */
