#include <stdio.h>
#include <math.h>
#include <string.h>


void program() {
	double a,b,c,max,min,x;
	printf("a : "); scanf("%lf", &a);
	printf("b : "); scanf("%lf", &b);
	printf("c : "); scanf("%lf", &c);
	
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	
	x = a + b + c - max - min;
	
	printf("Gia tri trung gian : %lf", x);
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

