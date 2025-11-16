#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	
	int n;
	do {
		printf("n : "); scanf("%d", &n);
	} while (n < 32 || n > 255);
	
	printf("ASCII of %d is %c", n,n);
	
	return 0;
}



