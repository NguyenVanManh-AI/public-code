#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double x,y,gxy;
	printf("x : "); scanf("%lf", &x);
	printf("y : "); scanf("%lf", &y);
	
	gxy = (pow(M_E,x+y) + log(abs(x*x - y)+5)) / (cos(x+y) - sin(x) + 3);
	
	printf("g(x,y) = %lf", gxy);
	
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

