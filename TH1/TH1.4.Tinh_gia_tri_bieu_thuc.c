#include <stdio.h>
#include <math.h>
#include <string.h>


void program() {
	double x, f_x;
	printf("x : "); scanf("%lf", &x);
    
	f_x = (pow(x, 2.0/3.0) + pow(x, 5) + log(pow(x, 4) + 1)) // Phai la : 2.0 / 3.0 
          / (pow(x, 2) + M_PI/4);
          
	printf("%lf", f_x);
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

