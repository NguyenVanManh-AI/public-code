#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ham nhap so nguyen nghiem ngat tu ban phim, kiem tra chuoi hop le, cho phep so am, tra ve long long */
long long nhap_so_nguyen(const char *ten)
{
    char s[200];
    while (1)
    {
        int hop_le = 1; // bien danh dau chuoi co hop le hay khong
        printf("Nhap %s: ", ten);
        scanf("%s", s); // doc chuoi nguoi dung nhap

        int i = 0;

        /* Cho phep so am */
        if (s[0] == '-' && s[1] != '\0')
            i = 1; // neu co dau tru thi bo qua vi tri 0

        /* Kiem tra tung ky tu */
        for (; s[i] != '\0'; i++)
        {
            if (!isdigit(s[i]))   /* ky tu khong phai chu so */
            {
                hop_le = 0; // danh dau chuoi khong hop le
                break;
            }
        }

        if (hop_le)
        {
            long long x = 0; 
            int dau = (s[0] == '-') ? -1 : 1; // xac dinh dau cua so
            i = (s[0] == '-') ? 1 : 0; // neu co dau tru thi bat dau tu vi tri 1

            /* Chuyen chuoi sang so long long */
            for (; s[i] != '\0'; i++)
                x = x * 10 + (s[i] - '0'); // cong don thanh so nguyen

            return dau * x; // tra ve ket qua cuoi cung
        }

        printf("Gia tri khong hop le. Nhap lai.\n"); // neu nhap sai thi yeu cau nhap lai
    }
}

/* ham xoa phan tu tai vi tri k trong mang, don cac phan tu ben phai sang trai */
void xoa_vi_tri(long long A[], int *n, int k)
{
    int i; /* khai bao bien i o ngoai for */

    for (i = k; i < *n - 1; i++)
        A[i] = A[i + 1]; // dich cac gia tri ben phai sang mot o

    (*n)--; // giam kich thuoc mang
}

int main()
{
    int n = (int)nhap_so_nguyen("so luong phan tu n"); // nhap so luong phan tu
    while (n <= 0)
    {
        printf("n phai > 0. Nhap lai.\n");
        n = (int)nhap_so_nguyen("so luong phan tu n"); // bat buoc nhap lai neu n <= 0
    }

    long long A[200];
    int i;      /* khai bao bien i dung cho vong lap */
    char ten[50];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%d]", i); // tao chuoi A[i] de hien thi
        A[i] = nhap_so_nguyen(ten); // nhap tung phan tu mang
    }

    /* Nhap vi tri k */
    int k = (int)nhap_so_nguyen("chi so k can xoa");
    while (k < 0 || k >= n)
    {
        printf("k phai nam trong [0 .. %d]. Nhap lai.\n", n - 1);
        k = (int)nhap_so_nguyen("chi so k can xoa"); // bat nhap lai neu k khong hop le
    }

    /* Xoa phan tu */
    xoa_vi_tri(A, &n, k); // goi ham xoa

    /* Xuat ket qua */
    printf("\n=== Mang sau khi xoa A[%d] ===\n", k);
    for (i = 0; i < n; i++)
        printf("%lld ", A[i]); // in ra mang sau khi xoa

    printf("\n");
    return 0;
}

/* 
thuat toan tong quat:
1. nhap so n va dam bao n > 0
2. nhap n phan tu mang voi kiem tra chuoi nghiem ngat
3. nhap chi so k va dam bao k nam trong pham vi hop le
4. xoa phan tu tai vi tri k bang cach dich cac phan tu ben phai sang trai
5. in ra mang sau khi xoa
luu y: ham nhap tu viet dam bao khong co loi bo dem, khong chap nhan ky tu khac so
*/
