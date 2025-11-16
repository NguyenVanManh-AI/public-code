#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double x,gx;
	printf("x : "); scanf("%lf", &x);
	
	gx = (pow(x,3) + (log(abs(x-3)+2) / log(5))) / (pow(atan(x-5),2)+1);
	
	printf("g(x) = %lf", gx);
	
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

