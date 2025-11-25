#include <stdio.h>

// Ham nhap tap hop (khong cho trung nhau)
void nhap_tap(int a[], int *n) {
    int i, j, x, hop_le;

    printf("Nhap so phan tu: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++) {
        do {
            hop_le = 1;
            printf("Nhap phan tu thu %d: ", i + 1);
            scanf("%d", &x);

            // Kiem tra trung
            for (j = 0; j < i; j++) {
                if (a[j] == x) {
                    hop_le = 0;
                    printf("Phan tu bi trung, moi nhap lai.\n");
                }
            }
        } while (!hop_le);

        a[i] = x;
    }
}

// Ham xuat tap hop
void xuat_tap(int a[], int n) {
    int i;
    printf("{ ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("}\n");
}

// Ham kiem tra phan tu co thuoc tap hay khong
int thuoc_tap(int a[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == x) return 1;
    }
    return 0;
}

// Ham tinh tap hop
void tap_hop(int a[], int na, int b[], int nb, int c[], int *nc) {
    int i;

    *nc = 0;

    // Them A vao C
    for (i = 0; i < na; i++) {
        c[*nc] = a[i];
        (*nc)++;
    }

    // Them B vao C neu khong trung
    for (i = 0; i < nb; i++) {
        if (!thuoc_tap(c, *nc, b[i])) {
            c[*nc] = b[i];
            (*nc)++;
        }
    }
}

// Ham tinh tap giao
void tap_giao(int a[], int na, int b[], int nb, int c[], int *nc) {
    int i;

    *nc = 0;

    for (i = 0; i < na; i++) {
        if (thuoc_tap(b, nb, a[i])) {
            c[*nc] = a[i];
            (*nc)++;
        }
    }
}

// Ham tinh tap hieu (A - B)
void tap_hieu(int a[], int na, int b[], int nb, int c[], int *nc) {
    int i;

    *nc = 0;

    for (i = 0; i < na; i++) {
        if (!thuoc_tap(b, nb, a[i])) {
            c[*nc] = a[i];
            (*nc)++;
        }
    }
}

// Ham kiem tra A co la tap con cua B hay khong
int la_tap_con(int a[], int na, int b[], int nb) {
    int i;

    for (i = 0; i < na; i++) {
        if (!thuoc_tap(b, nb, a[i])) {
            return 0; // Co phan tu khong thuoc B
        }
    }
    return 1;
}

int main() {
    int A[100], B[100], C[100];
    int na, nb, nc;
    int lua_chon;

    printf("Nhap tap hop A:\n");
    nhap_tap(A, &na);

    printf("Nhap tap hop B:\n");
    nhap_tap(B, &nb);

    printf("\nChon phep toan:\n");
    printf("1. Hop\n");
    printf("2. Giao\n");
    printf("3. Hieu A - B\n");
    printf("4. Kiem tra A la tap con cua B\n");
    printf("Nhap lua chon: ");
    scanf("%d", &lua_chon);

    if (lua_chon == 1) {
        tap_hop(A, na, B, nb, C, &nc);
        printf("Tap hop A ∪ B = ");
        xuat_tap(C, nc);
    }
    else if (lua_chon == 2) {
        tap_giao(A, na, B, nb, C, &nc);
        printf("Tap giao A ∩ B = ");
        xuat_tap(C, nc);
    }
    else if (lua_chon == 3) {
        tap_hieu(A, na, B, nb, C, &nc);
        printf("Tap hieu A - B = ");
        xuat_tap(C, nc);
    }
    else if (lua_chon == 4) {
        if (la_tap_con(A, na, B, nb))
            printf("A la tap con cua B\n");
        else
            printf("A KHONG phai la tap con cua B\n");
    }
    else {
        printf("Lua chon khong hop le.\n");
    }

    return 0;
}
