#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	double l,w;
	printf("l : "); scanf("%lf", &l);
	printf("w : "); scanf("%lf", &w);
	printf("Chu vi : %lf ; Dien tich : %lf", 2*(l+w),l*w); 
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

