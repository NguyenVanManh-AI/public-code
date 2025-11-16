#include <stdio.h>
#include <conio.h>

// Hoán d?i không dùng bi?n t?m (c?ng – tr?)
void Swap1(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Hoán d?i không dùng bi?n t?m (dùng XOR)
void Swap2(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// Hoán d?i có dùng bi?n t?m
void Swap3(int *a, int *b) {
    int tam = *a;
    *a = *b;
    *b = tam;
}

int main() {
    int a, b;
    printf("Nhap a = ");
    scanf("%d", &a);
    printf("Nhap b = ");
    scanf("%d", &b);

    printf("\n--- Truoc khi hoan doi ---\n");
    printf("a = %d, b = %d\n", a, b);

    // G?i t?ng hàm
    Swap1(&a, &b);
    printf("\nSau Swap1 (c?ng-tr?): a = %d, b = %d\n", a, b);

    Swap2(&a, &b);
    printf("Sau Swap2 (XOR): a = %d, b = %d\n", a, b);

    Swap3(&a, &b);
    printf("Sau Swap3 (bi?n t?m): a = %d, b = %d\n", a, b);

    getch(); // ch? dùng du?c trong môi tru?ng Windows / Turbo C
    return 0;
}

