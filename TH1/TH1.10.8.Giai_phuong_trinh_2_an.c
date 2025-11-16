#include <stdio.h>
#include <math.h>

void program() {
    double a1, b1, c1, a2, b2, c2, x, y;
    
    printf("Nhap he phuong trinh:\n");
    printf("a1 = "); scanf("%lf", &a1);
    printf("b1 = "); scanf("%lf", &b1);
    printf("c1 = "); scanf("%lf", &c1);
    printf("a2 = "); scanf("%lf", &a2);
    printf("b2 = "); scanf("%lf", &b2);
    printf("c2 = "); scanf("%lf", &c2);
    
    printf("He phuong trinh:\n");
    printf("%.2lfx + %.2lfy = %.2lf\n", a1, b1, c1);
    printf("%.2lfx + %.2lfy = %.2lf\n", a2, b2, c2);
    
    double D  = a1*b2 - a2*b1;
    double D1 = c1*b2 - c2*b1;
    double D2 = a1*c2 - a2*c1;
    
    if (D == 0) {
        if (D1 == 0 && D2 == 0)
            printf("He phuong trinh co vo so nghiem!\n");
        else
            printf("He phuong trinh vo nghiem!\n");
    } else {
        x = D1 / D;
        y = D2 / D;
        printf("He phuong trinh co nghiem duy nhat:\n");
        printf("x = %.3lf\n", x);
        printf("y = %.3lf\n", y);
    }
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

