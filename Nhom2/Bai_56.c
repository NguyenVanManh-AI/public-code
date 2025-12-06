#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* ham doc chuoi nguoi dung nhap, giu dung dinh dang, khong kiem tra hop le */
void nhap_chuoi(const char *ten, char *out)
{
    printf("Nhap %s: ", ten); // in loi nhac nhap
    scanf("%s", out); // doc chuoi vao bien out
}

/* ham kiem tra chuoi co phai so nguyen (cho phep dau am), khong duoc co dau cham */
int la_so_nguyen(const char *s)
{
    int i = 0;

    if (s[0] == '-' && s[1] != '\0')
        i = 1; // bo qua dau tru neu co

    for (; s[i]; i++)
        if (!isdigit(s[i]))   /* neu co ky tu khong phai chu so thi khong hop le */
            return 0;

    return 1; // neu tat ca ky tu la chu so
}

/* ham chuyen chuoi so nguyen sang long long (khong kiem tra tran so) */
long long to_ll(const char *s)
{
    long long x = 0;
    int dau = (s[0] == '-') ? -1 : 1; // xac dinh dau cua so
    int i = (s[0] == '-') ? 1 : 0; // bo qua vi tri 0 neu la dau tru

    for (; s[i]; i++)
        x = x * 10 + (s[i] - '0'); // cong don gia tri

    return dau * x; // tra ve gia tri cuoi cung
}

/* ham kiem tra so hoan hao: tong cac uoc so duong (khong tinh chinh no) bang chinh no */
int so_hoan_hao(long long x)
{
    if (x <= 0) return 0; // so hoan hao phai duong

    long long sum = 0;
    long long i;

    for (i = 1; i <= x / 2; i++) // duyet cac uoc tu 1 toi x/2
        if (x % i == 0)
            sum += i; // cong uoc vao sum

    return (sum == x); // so hoan hao khi tong uoc = x
}

int main()
{
    int n = 0;
    char buf[100];
    int i;

    /* Nhap n, yeu cau n > 0 */
    while (1)
    {
        n = 0; // dat lai n = 0 de tranh lay gia tri cu

        nhap_chuoi("so luong phan tu n", buf); // nhap chuoi so

        if (la_so_nguyen(buf)) // kiem tra chuoi hop le
        {
            n = (int)to_ll(buf); // chuyen sang so
            if (n > 0)
                break; // hop le thi dung vong lap
        }

        printf("n phai la so nguyen duong > 0. Nhap lai.\n"); // neu khong hop le thi bat nhap lai
    }

    char A[200][100]; // mang cac chuoi
    char ten[50];

    printf("\n=== Nhap cac phan tu cua mang A ===\n");
    for (i = 0; i < n; i++)
    {
        sprintf(ten, "A[%d]", i); // tao ten hien thi A[i]
        nhap_chuoi(ten, A[i]); // nhap tung phan tu
    }

    printf("\n=== Mang A vua nhap ===\n");
    for (i = 0; i < n; i++)
        printf("%s ", A[i]); // in ra cac phan tu da nhap

    printf("\n\n=== Cac so hoan hao trong mang ===\n");
    int co = 0;
    long long val;

    for (i = 0; i < n; i++)
    {
        if (la_so_nguyen(A[i]))    /* chi kiem tra so nguyen */
        {
            val = to_ll(A[i]); // chuyen chuoi thanh so
            if (so_hoan_hao(val)) // kiem tra so hoan hao
            {
                printf("%lld ", val); // in ra so hoan hao
                co = 1; // danh dau la co it nhat 1 so
            }
        }
    }

    if (!co)
        printf("Khong co so hoan hao nao."); // khong tim thay so hoan hao

    printf("\n");
    return 0;
}

/*
thuat toan chuong trinh:
1. nhap so n dang chuoi, dam bao la so nguyen duong
2. nhap n phan tu cua mang A (dang chuoi)
3. in lai mang vua nhap
4. duyet tung phan tu:
   - neu la so nguyen thi chuyen sang long long
   - kiem tra xem co phai so hoan hao khong
5. in ra tat ca cac so hoan hao tim duoc
luu y:
- ham la_so_nguyen kiem tra chat che, khong chap nhan ky tu khac chu so
- ham to_ll khong kiem tra tran long long
- so hoan hao rat hiem (6, 28, 496, 8128,...)
*/
