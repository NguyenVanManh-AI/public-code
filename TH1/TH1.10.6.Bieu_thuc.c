#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double x,y,gxy;
	printf("x : "); scanf("%lf", &x);
	printf("y : "); scanf("%lf", &y);
	
	while((x*x - y) <= 0) {
		printf("Gia tri x*x - y phai >= 0 !\n");
		printf("x : "); scanf("%lf", &x);
		printf("y : "); scanf("%lf", &y);
	} 
	gxy = (pow(M_E,x+y) - log(x*x-y)) / (cos(x+y) - sin(x));
	
	printf("g(x,y) = %lf", gxy);
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

