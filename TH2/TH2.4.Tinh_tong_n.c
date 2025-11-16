#include <stdio.h>
#include <math.h>

void program() {
	double i,n,s=0;
	printf("n : "); scanf("%lf", &n);
	
	for(i=1;i<=n;i++) {
		s += 1.0/i;
	}
	printf("s : %lf", s);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
        break;
    }
    return 0;
}

