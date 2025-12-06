#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** Ham nhap chuoi tu ban phim, luu vao out */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten); // in ten truong can nhap
    scanf("%s", out); // doc chuoi khong co khoang trang
}

/** Ham kiem tra chuoi co phai la so am hay khong */
int la_so_am(const char *s)
{
    return (s[0] == '-'); // neu ky tu dau la '-' thi la so am
}

int main()
{
    int n; // bien luu so phan tu
    char buf[50]; // buf dung de nhap tam thoi n duoi dang chuoi
    int hop_le; // co phai so hop le hay khong
    int i; // bien lap
    int m = 0; // so luong phan tu sau khi loai bo so am

    /* Nhap n sao cho n > 0 */
    while (1) // lap den khi nhap dung
    {
        printf("Nhap so luong phan tu n: ");
        scanf("%s", buf); // nhap n duoi dang chuoi de kiem tra

        hop_le = 1; // gia su hop le truoc
        for (i = 0; buf[i] != '\0'; i++) // duyet tung ky tu
        {
            if (!isdigit(buf[i])) // neu co ky tu khong phai chu so
                hop_le = 0; // danh dau khong hop le
        }

        if (hop_le) // neu tat ca ky tu la chu so
        {
            n = 0;
            for (i = 0; buf[i] != '\0'; i++) // chuyen chuoi sang so nguyen
                n = n * 10 + (buf[i] - '0');

            if (n > 0) // kiem tra > 0
                break; // hop le, thoat vong lap
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n"); // thong bao nhap sai
    }

    char A[200][100]; // mang luu cac chuoi ban dau
    char B[200][100]; // mang luu cac chuoi sau khi xoa so am
    char ten[20]; // ten truong nhap

    /* Nhap mang A */
    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++) // duyet n phan tu
    {
        sprintf(ten, "A[%d]", i); // tao ten nhu A[0], A[1], ...
        nhap_chuoi(ten, A[i]); // goi ham nhap chuoi
    }

    /* Xuat mang A */
    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++) // in cac phan tu
        printf("%s ", A[i]);

    /* Xoa cac so am */
    printf("\n\n=== Mang A sau khi xoa cac so am ===\n");

    for (i = 0; i < n; i++) // duyet tung chuoi trong A
    {
        if (!la_so_am(A[i]))   /* Chi giu cac chuoi khong bat dau bang dau tru */
        {
            strcpy(B[m], A[i]); // copy vao mang B
            m++; // tang so luong phan tu hop le
        }
    }

    for (i = 0; i < m; i++) // in mang sau khi xoa am
        printf("%s ", B[i]);

    printf("\n");
    return 0;
}

/*
THUAT TOAN CHUONG TRINH
    1. Nhap n duoi dang chuoi de kiem tra tung ky tu, chi chap nhan n > 0
    2. Nhap n chuoi vao mang A
    3. In mang A
    4. Duyet mang A, su dung ham la_so_am de kiem tra chuoi bat dau bang '-' hay khong
    5. Neu khong am thi copy sang mang B
    6. In mang B sau khi loai cac so am
LUU Y
    - Chuong trinh xem "so am" la chuoi co ky tu dau la '-'
    - Chuoi co chu cai nhung bat dau bang '-' van bi xem la so am
    - Nhap chuoi dung scanf nen khong nhan duoc khoang trang
 */
