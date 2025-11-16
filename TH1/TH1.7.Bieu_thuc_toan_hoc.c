#include <stdio.h>
#include <math.h>
#include <string.h>


void program() {
	// test : x = 90 , y = 45	
	double x,y,fx;
	printf("x : "); scanf("%lf", &x);
	printf("y : "); scanf("%lf", &y);
	
	while((x+y) <= 0) {
		printf("x + y phai lon hon 0\n");
		printf("x : "); scanf("%lf", &x);
		printf("y : "); scanf("%lf", &y);
	}
	
	fx = (pow(x*x + y*y, 1.0/3.0) - (log(x+y) / log(5))) / (atan(x-y) + M_PI/4);

         
	printf("f(x,y) : %lf", fx);
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

