#include <stdio.h>
#include <math.h>

long long int giai_thua(int n) {
	if(n == 1 || n ==0) return 1;
	else return n*giai_thua(n-1);
}

void program() {
	double x,sh_x=0.0,check,EPS = 1e-6;
	long long int n=0;
	
	printf("x : "); scanf("%lf", &x);
	
	do {
		check = (pow(x, 2*n+1)) / (giai_thua(2*n+1));
		sh_x += check;
		n++;
	}
	while(fabs(check) >= EPS && (n < 100));
	printf("sh(%lf) = %.6lf\n", x, sh_x);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

