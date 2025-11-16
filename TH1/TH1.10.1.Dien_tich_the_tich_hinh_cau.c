#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double r,s,v;
	printf("r : "); scanf("%lf", &r);
	s = 4*M_PI*pow(r,2);
	v = 4*M_PI*pow(r,3);
	printf("S : %lf ; V : %lf", s,v); 
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

