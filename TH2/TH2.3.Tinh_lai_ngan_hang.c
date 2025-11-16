#include <stdio.h>
#include <math.h>

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	double d = 0.02, T = 1000000.0;
	for(i=1;i<=n;i++) {
		T += T*d;
	}
	printf("So tien sau %d thang : %lf", n, T);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
        break;
    }
    return 0;
}

