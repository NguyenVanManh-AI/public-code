#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double a,b,h,s;
	printf("a : "); scanf("%lf", &a);
	printf("b : "); scanf("%lf", &b);
	printf("h : "); scanf("%lf", &h);
	
	s = (a + b)*h/2;
	
	printf("S = %lf", s);
	
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

