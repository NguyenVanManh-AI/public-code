#include <stdio.h>

#define MAX 1000

// Ham loai bo trung lap trong mang
int loaiBoTrungLap(int a[], int n) {
    int b[MAX], m = 0;

    for (int i = 0; i < n; i++) {
        int tonTai = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai) {
            b[m++] = a[i];
        }
    }

    for (int i = 0; i < m; i++)
        a[i] = b[i];

    return m;
}

// Hop hai tap hop
int hop(int a[], int na, int b[], int nb, int kq[]) {
    int m = 0;

    // Them tat ca phan tu cua A
    for (int i = 0; i < na; i++)
        kq[m++] = a[i];

    // Them phan tu cua B neu chua co trong ket qua
    for (int i = 0; i < nb; i++) {
        int tonTai = 0;
        for (int j = 0; j < m; j++) {
            if (b[i] == kq[j]) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai)
            kq[m++] = b[i];
    }

    return m;
}

// Giao hai tap hop
int giao(int a[], int na, int b[], int nb, int kq[]) {
    int m = 0;

    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                kq[m++] = a[i];
                break;
            }
        }
    }

    return m;
}

// Hieu A - B
int hieu(int a[], int na, int b[], int nb, int kq[]) {
    int m = 0;

    for (int i = 0; i < na; i++) {
        int tonTai = 0;
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                tonTai = 1;
                break;
            }
        }
        if (!tonTai)
            kq[m++] = a[i];
    }

    return m;
}

// Kiem tra A co la tap con cua B hay khong
int tapCon(int a[], int na, int b[], int nb) {
    for (int i = 0; i < na; i++) {
        int timThay = 0;
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                timThay = 1;
                break;
            }
        }
        if (!timThay)
            return 0;
    }
    return 1;
}

// Ham in tap hop
void inTap(int a[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("}\n");
}

// ================== MAIN ==================
int main() {
    int A[MAX], B[MAX], nA, nB;

    printf("Nhap so phan tu tap A: ");
    scanf("%d", &nA);
    if(nA > 0) {
        printf("Nhap cac phan tu tap A: ");
        for (int i = 0; i < nA; i++)
            scanf("%d", &A[i]);
    }
    printf("Nhap so phan tu tap B: ");
    scanf("%d", &nB);
    if(nB > 0) {
        printf("Nhap cac phan tu tap B: ");
        for (int i = 0; i < nB; i++)
            scanf("%d", &B[i]);
    }

    // Loai bo trung lap
    nA = loaiBoTrungLap(A, nA);
    nB = loaiBoTrungLap(B, nB);

    int KQ[MAX];
    int nKQ;

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

    // Hieu A - B
    nKQ = hieu(A, nA, B, nB, KQ);
    printf("Hieu (A - B): ");
    inTap(KQ, nKQ);

    // Kiem tra tap con
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
