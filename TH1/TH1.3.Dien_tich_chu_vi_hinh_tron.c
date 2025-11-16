#include <stdio.h>
#include <math.h>
#include <string.h>


void program() {
	double r;
	printf("r : "); scanf("%lf", &r);
	printf("S of circle : %lf \n", M_PI*r*r);
	printf("L of circle : %lf", 2*M_PI*r);
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

