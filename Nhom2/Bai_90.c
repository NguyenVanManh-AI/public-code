#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAXLEN 100   // do dai toi da moi chuoi

/* Ham loai bo trung lap trong mang chuoi */
int loaiBoTrungLap(char a[][MAXLEN], int n) {
    char b[MAX][MAXLEN];
    int m = 0;
    int i, j, tonTai;

    for (i = 0; i < n; i++) {
        tonTai = 0;
        for (j = 0; j < m; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                tonTai = 1;  // neu ton tai -> danh dau
                break;
            }
        }
        if (!tonTai) {
            strcpy(b[m++], a[i]); // them vao mang moi neu chua ton tai
        }
    }

    for (i = 0; i < m; i++)
        strcpy(a[i], b[i]); // cap nhat lai mang ban dau

    return m; // tra ve so luong phan tu khong trung lap
}

/* Ham tinh hop (A union B) */
int hop(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;
    int i, j, tonTai;

    // Them cac phan tu cua A vao ket qua
    for (i = 0; i < na; i++)
        strcpy(kq[m++], a[i]);

    // Them cac phan tu cua B neu chua co
    for (i = 0; i < nb; i++) {
        tonTai = 0;
        for (j = 0; j < m; j++) {
            if (strcmp(b[i], kq[j]) == 0) {
                tonTai = 1;  // neu ton tai -> khong them
                break;
            }
        }
        if (!tonTai)
            strcpy(kq[m++], b[i]); // them vao ket qua
    }

    return m; // tra ve so luong phan tu ket qua
}

/* Ham tinh giao (A intersect B) */
int giao(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;
    int i, j;

    for (i = 0; i < na; i++) {
        for (j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                strcpy(kq[m++], a[i]); // them vao ket qua neu tim thay
                break;
            }
        }
    }

    return m; // tra ve so luong phan tu ket qua
}

/* Ham tinh hieu (A - B) */
int hieu(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;
    int i, j, tonTai;

    for (i = 0; i < na; i++) {
        tonTai = 0;
        for (j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                tonTai = 1; // neu ton tai trong B -> bo qua
                break;
            }
        }
        if (!tonTai)
            strcpy(kq[m++], a[i]); // them vao ket qua neu khong ton tai
    }

    return m; // tra ve so luong phan tu ket qua
}

/* Ham kiem tra tap con: A subset B? */
int tapCon(char a[][MAXLEN], int na, char b[][MAXLEN], int nb) {
    int i, j, timThay;

    for (i = 0; i < na; i++) {
        timThay = 0;
        for (j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                timThay = 1; // phan tu a[i] ton tai trong B
                break;
            }
        }
        if (!timThay)
            return 0; // co phan tu khong co trong B -> khong phai tap con
    }
    return 1; // tat ca phan tu A co trong B -> la tap con
}

/* Ham in tap hop */
void inTap(char a[][MAXLEN], int n) {
    int i;
    printf("{ ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]); // in tung phan tu
    printf("}\n");
}

/* ======================= MAIN ====================== */
int main() {
    char A[MAX][MAXLEN], B[MAX][MAXLEN], KQ[MAX][MAXLEN];
    int nA, nB, nKQ;
    int i;

    printf("Nhap so phan tu tap A: ");
    scanf("%d", &nA);
    printf("Nhap cac phan tu tap A:\n");
    for (i = 0; i < nA; i++)
        scanf("%s", A[i]); // nhap phan tu tap A

    printf("Nhap so phan tu tap B: ");
    scanf("%d", &nB);
    printf("Nhap cac phan tu tap B:\n");
    for (i = 0; i < nB; i++)
        scanf("%s", B[i]); // nhap phan tu tap B

    // Loai bo phan tu trung lap
    nA = loaiBoTrungLap(A, nA);
    nB = loaiBoTrungLap(B, nB);

    printf("\nTap A: ");
    inTap(A, nA);

    printf("Tap B: ");
    inTap(B, nB);

    // Hop
    nKQ = hop(A, nA, B, nB, KQ);
    printf("\nHop (A union B): ");
    inTap(KQ, nKQ);

    // Giao
    nKQ = giao(A, nA, B, nB, KQ);
    printf("Giao (A intersect B): ");
    inTap(KQ, nKQ);

    // Hieu
    nKQ = hieu(A, nA, B, nB, KQ);
    printf("Hieu (A - B): ");
    inTap(KQ, nKQ);

    // Tap con
    if (tapCon(A, nA, B, nB))
        printf("\nTap A la tap con cua tap B\n");
    else
        printf("\nTap A khong la tap con cua tap B\n");

    if (tapCon(B, nB, A, nA))
        printf("Tap B la tap con cua tap A\n");
    else
        printf("Tap B khong la tap con cua tap A\n");

    return 0;
}

/* 
    THUAT TOAN VA LUONG XU LY CHUONG TRINH:

    1. Nhap so phan tu va cac phan tu cua 2 tap A va B.
    2. Loai bo cac phan tu trung lap trong tung tap.
    3. In lai cac tap sau khi loai trung lap.
    4. Tinh hop (A union B):
        - Them tat ca phan tu A vao ket qua.
        - Them cac phan tu B neu chua co trong ket qua.
    5. Tinh giao (A intersect B):
        - Lap tung phan tu A, neu phan tu do co trong B -> them vao ket qua.
    6. Tinh hieu (A - B):
        - Lap tung phan tu A, neu phan tu do khong co trong B -> them vao ket qua.
    7. Kiem tra tap con:
        - A subset B: tat ca phan tu A phai co trong B.
        - B subset A: tat ca phan tu B phai co trong A.
    8. In ket qua cac phep tap hop, giao, hieu va tap con.
    
    LUU Y:
    - Su dung strcmp va strcpy de thao tac chuoi.
    - Mang ket qua KQ luu cac phan tu cua phep tap.
    - Mang a va b co do dai toi da MAX va moi phan tu toi da MAXLEN.
    - Toan bo phep so sanh va sao chep phan tu su dung chuoi (string), khong phai so nguyen hay float.
*/
