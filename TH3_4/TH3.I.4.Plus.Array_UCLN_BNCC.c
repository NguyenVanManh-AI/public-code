#include <stdio.h>
#include <math.h>

void xuat(int arr[], int n) {
	printf("\n");
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
	}
	printf("\n");
}

int UCLN(int a, int b) {
	if(a == 0) return b;
	if(b == 0) return a;
	
	a = fabs(a);
	b = fabs(b);
	
	//	Euclid
	while(b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int BCNN(int a, int b) {
	return fabs(a*b) / UCLN(a,b);
}

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n];

	// nhap xuat
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	xuat(arr,n);
	
	long long int uoc_chung, boi_chung;
	uoc_chung = arr[0];
	boi_chung = arr[0];
	for(i = 1;i<n;i++) {
		uoc_chung = UCLN(uoc_chung, arr[i]);
		boi_chung = BCNN(boi_chung, arr[i]);
	}
	
	printf("\nUCLN : %lld\n", uoc_chung);
	printf("BCNN : %lld", boi_chung);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

