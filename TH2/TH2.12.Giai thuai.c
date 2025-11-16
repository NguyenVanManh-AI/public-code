#include <stdio.h>
#include <conio.h>

void Swap1(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Swap2(int *a, int *b) {
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

    Swap1(&a, &b);
    printf("\nSau Swap1 (cong - tru): a = %d, b = %d\n", a, b);

    Swap2(&a, &b);
    printf("Sau Swap2 (bien tam): a = %d, b = %d\n", a, b);

    getch(); 
    return 0;
}

