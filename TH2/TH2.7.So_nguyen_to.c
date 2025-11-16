#include <stdio.h>
#include <math.h>

int soNguyenTo(long long int n) {
	long long int i, dem = 0;
	for(i=1;i<=n;i++) {
		if(n%i == 0) dem++;
	}
	if(dem == 2) return 1;
	else return 0;
}

void program() {
	long long int i,n=1000000;
	for(i=2;i<=n;i++) {
		if(soNguyenTo(i) == 1) {
			printf("%lld\n", i);
		}
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
        break;
    }
    return 0;
}

