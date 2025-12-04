#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAXLEN 100   // do dai toi da moi chuoi

// Ham loai bo trung lap
int loaiBoTrungLap(char a[][MAXLEN], int n) {
    char b[MAX][MAXLEN];
    int m = 0;
    int i, j, tonTai;

    for (i = 0; i < n; i++) {
        tonTai = 0;
        for (j = 0; j < m; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai) {
            strcpy(b[m++], a[i]);
        }
    }

    for (i = 0; i < m; i++)
        strcpy(a[i], b[i]);

    return m;
}

// Hop A ∪ B
int hop(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;
    int i, j, tonTai;

    // Them A vao kq
    for (i = 0; i < na; i++)
        strcpy(kq[m++], a[i]);

    // Them B neu chua co
    for (i = 0; i < nb; i++) {
        tonTai = 0;
        for (j = 0; j < m; j++) {
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
    int i, j;

    for (i = 0; i < na; i++) {
        for (j = 0; j < nb; j++) {
            if (strcmp(a[i], b[j]) == 0) {
                strcpy(kq[m++], a[i]);
                break;
            }
        }
    }

    return m;
}

// Hieu A - B
int hieu(char a[][MAXLEN], int na, char b[][MAXLEN], int nb, char kq[][MAXLEN]) {
    int m = 0;
    int i, j, tonTai;

    for (i = 0; i < na; i++) {
        tonTai = 0;
        for (j = 0; j < nb; j++) {
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

// Kiem tra tap con: A ⊆ B ?
int tapCon(char a[][MAXLEN], int na, char b[][MAXLEN], int nb) {
    int i, j, timThay;

    for (i = 0; i < na; i++) {
        timThay = 0;
        for (j = 0; j < nb; j++) {
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

// In tap hop
void inTap(char a[][MAXLEN], int n) {
    int i;
    printf("{ ");
    for (i = 0; i < n; i++)
        printf("%s ", a[i]);
    printf("}\n");
}

// MAIN
int main() {
    char A[MAX][MAXLEN], B[MAX][MAXLEN], KQ[MAX][MAXLEN];
    int nA, nB, nKQ;
    int i;

    printf("Nhap so phan tu tap A: ");
    scanf("%d", &nA);
    printf("Nhap cac phan tu tap A:\n");
    for (i = 0; i < nA; i++)
        scanf("%s", A[i]);

    printf("Nhap so phan tu tap B: ");
    scanf("%d", &nB);
    printf("Nhap cac phan tu tap B:\n");
    for (i = 0; i < nB; i++)
        scanf("%s", B[i]);

    // Loai trung lap
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
