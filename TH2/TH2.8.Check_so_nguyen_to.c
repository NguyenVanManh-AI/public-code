#include <stdio.h>
#include <math.h>

int soNguyenTo(long long int n) {
    if (n < 2) return 0;            // 0 và 1 khong phai la so nguyen to
    if (n == 2) return 1;           // 2 la so nguyen to chan duy nhat
    if (n % 2 == 0) return 0;       // loai bo cac so chan khac 2

	long long int i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void program() {
    long long int n;
    printf("n : "); scanf("%lld", &n);
    
    if (soNguyenTo(n)) printf("%lld La so nguyen to", n);
    else printf("%lld Khong phai la so nguyen to", n);
}

int main() {
	while(1) {
		program();
    	printf("\n---------\n");
	}
    return 0;
}

