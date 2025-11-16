#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {
	// ax^4 + bx^2 + c = 0;	
	double a, b, c, delta, x1, x2;
	printf("Nhap cac gia tri \n");

	do {
		printf("a = ");
	    scanf("%lf", &a);
	    if(a == 0) printf("Gia tri a phai khac 0 !\n");
	}
	while (a == 0);

	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);
	
	delta = b*b - 4*a*c;
	
	if(delta < 0) {
		printf("Phuong trinh vo nghiem !");
	} else if(delta == 0) {
		x1 = x2 = -b / (2*a);
		if(x1 == 0) {
			printf("Phuong trinh co 1 nghiem : \n");
			printf("x = %lf\n", x1);	
		} 
		if(x1 > 0) {
			printf("Phuong trinh co 2 nghiem : \n");
			printf("x1 = %lf\n", -sqrt(x1));	
			printf("x2 = %lf\n", sqrt(x1));	
		}
	} else {
		x1 = (-b - sqrt(delta)) / (2*a);
		x2 = (-b + sqrt(delta)) / (2*a);
		
		int so_no = 0;
		double x11,x12,x21,x22;
		if(x1 > 0) {
			x11 = -sqrt(x1);
			x12 = sqrt(x1);
			so_no += 2;
		}
		if(x2 > 0) {
			x21 = -sqrt(x2);
			x22 = sqrt(x2);
			so_no += 2;
		}
		
		if (so_no == 0) printf("Phuong trinh vo nghiem thuc!\n");
        else {
            printf("Phuong trinh co %d nghiem thuc:\n", so_no);
            if (x1 > 0) {
                printf("x1 = %.3lf\n", x11);
                printf("x2 = %.3lf\n", x12);
            }
            if (x2 > 0) {
                printf("x3 = %.3lf\n", x21);
                printf("x4 = %.3lf\n", x22);
            }
        }	
	}
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

