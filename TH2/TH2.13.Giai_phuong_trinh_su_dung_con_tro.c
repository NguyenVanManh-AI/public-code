#include <stdio.h>
#include <math.h>

float ptb2(float a, float b, float c, float *x1, float *x2);

int main() {
    float a, b, c, x1, x2;
    printf("Nhap a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    ptb2(a, b, c, &x1, &x2);

    return 0;
}

float ptb2(float a, float b, float c, float *x1, float *x2) {
    float d; // bi?t th?c delta

    if (a != 0) {
        d = b * b - 4 * a * c;

        if (d > 0) {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);
            printf("Phuong trinh co 2 nghiem: x1 = %f, x2 = %f\n", *x1, *x2);
        }
        else if (d == 0) {
            *x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x = %f\n", *x1);
        }
        else {
            printf("Phuong trinh vo nghiem thuc\n");
        }
    }
    else { // a == 0
        if (b != 0) {
            *x1 = -c / b;
            printf("Phuong trinh bac nhat: x = %f\n", *x1);
        } else {
            if (c == 0)
                printf("Phuong trinh vo so nghiem\n");
            else
                printf("Phuong trinh vo nghiem\n");
        }
    }

    return 0;
}

