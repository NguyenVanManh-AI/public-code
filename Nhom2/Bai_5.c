#include <stdio.h>

/* ham tim uscln cua 2 so */
int uscln_2_so(int a, int b) {
    int temp;
    /* dung thuat toan euclid */
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/* ham tim uscln cua mang m so */
int uscln_m_so(int arr[], int m) {
    int i;
    int result;

    /* uscln ban dau = so dau tien */
    result = arr[0];

    /* giam dan theo cong thuc uscln(uscln(...), n) */
    for (i = 1; i < m; i++) {
        result = uscln_2_so(result, arr[i]);
    }

    return result;
}

int main() {
    int m;
    int i;
    int arr[100];

    /* nhap so luong phan tu */
    printf("Nhap so m (m >= 2): ");
    scanf("%d", &m);

    /* nhap mang m so */
    for (i = 0; i < m; i++) {
        printf("Nhap so thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("USCLN cua cac so la: %d\n", uscln_m_so(arr, m));

    return 0;
}
