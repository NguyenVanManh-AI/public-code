#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAXLEN 100   // độ dài tối đa mỗi chuỗi

// Hàm loại bỏ trùng lặp
int loaiBoTrungLap(char a[][MAXLEN], int n) {
    char b[MAX][MAXLEN];
    int m = 0;

    for (int i = 0; i < n; i++) {
        int tonTai = 0;
        for (int j = 0; j < m; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai) {
            strcpy(b[m++], a[i]);
        }
    }

    for (int i = 0; i < m; i++)
        strcpy(a[i], b[i]);

    return m;
}

// Hợp A ∪ B
int hop(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;

    // Thêm A vào kq
    for (int i = 0; i < na; i++)
        strcpy(kq[m++], a[i]);

    // Thêm B nếu chưa có
    for (int i = 0; i < nb; i++) {
        int tonTai = 0;
        for (int j = 0; j < m; j++) {
            if (strcmp(b[i], kq[j]) == 0) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai)
            strcpy(kq[m++], b[i]);
    }

    return m;
}

// Giao A ∩ B
int giao(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;

    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                strcpy(kq[m++], a[i]);
                break;
            }
        }
    }

    return m;
}

// Hiệu A – B
int hieu(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;

    for (int i = 0; i < na; i++) {
        int tonTai = 0;
        for (int j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai)
            strcpy(kq[m++], a[i]);
    }

    return m;
}

// Kiểm tra tập con: A ⊆ B ?
int tapCon(char a[][MAXLEN], int na, char b[][MAXLEN], int nb) {
    for (int i = 0; i < na; i++) {
        int timThay = 0;
        for (int j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                timThay = 1;
                break;
            }
        }
        if (!timThay)
            return 0;
    }
    return 1;
}

// In tập hợp
void inTap(char a[][MAXLEN], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++)
        printf("%s ", a[i]);
    printf("}\n");
}

// MAIN
int main() {
    char A[MAX][MAXLEN], B[MAX][MAXLEN], KQ[MAX][MAXLEN];
    int nA, nB, nKQ;

    printf("Nhap so phan tu tap A: ");
    scanf("%d", &nA);
    printf("Nhap cac phan tu tap A:\n");
    for (int i = 0; i < nA; i++)
        scanf("%s", A[i]);

    printf("Nhap so phan tu tap B: ");
    scanf("%d", &nB);
    printf("Nhap cac phan tu tap B:\n");
    for (int i = 0; i < nB; i++)
        scanf("%s", B[i]);

    // Loại trùng lặp
    nA = loaiBoTrungLap(A, nA);
    nB = loaiBoTrungLap(B, nB);

    printf("\nTap A: ");
    inTap(A, nA);

    printf("Tap B: ");
    inTap(B, nB);

    // Hợp
    nKQ = hop(A, nA, B, nB, KQ);
    printf("\nHop (A union B): ");
    inTap(KQ, nKQ);

    // Giao
    nKQ = giao(A, nA, B, nB, KQ);
    printf("Giao (A intersect B): ");
    inTap(KQ, nKQ);

    // Hiệu
    nKQ = hieu(A, nA, B, nB, KQ);
    printf("Hieu (A - B): ");
    inTap(KQ, nKQ);

    // Tập con
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
