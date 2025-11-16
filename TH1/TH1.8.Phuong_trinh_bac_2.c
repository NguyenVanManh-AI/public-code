#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	float a, b, c, delta, x1, x2;
	printf("Nhap cac gia tri \n");

	do {
		printf("a = ");
	    scanf("%f", &a);
	    if(a == 0) printf("Gia tri a phai khac 0 !\n");
	}
	while (a == 0);

	printf("b = ");
	scanf("%f", &b);
	printf("c = ");
	scanf("%f", &c);
	
	delta = b*b - 4*a*c;
	
	if(delta < 0) {
		printf("Phuong trinh vo nghiem !");
	} else if(delta == 0) {
		printf("Phuong trinh co nghiem nghiem kep : \n");
		x1 = x2 = -b / (2*a);
		printf("x1 = x2 = %f\n", x1);	
	} else {
		printf("Phuong trinh co nghiem la : \n");
		x1 = (-b - sqrt(delta)) / (2*a);
		x2 = (-b + sqrt(delta)) / (2*a);
		
		printf("x1 = %f\n", x1);	
		printf("x2 = %f", x2);	
	}
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

