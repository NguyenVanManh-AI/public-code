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

long long int UCLN(int a, int b) {
	long long uoc,i,min;
	
	min = (a < b) ? a : b;
	
	for(i=1;i<=min;i++) {
		if((a%i == 0) && (b%i == 0)) {
			uoc = i;
		}
	}
	return uoc;
}

// Slow // Chua toi uu 
long long int BCNN(int a, int b) {
	long long boi,i;

	for(i=a*b;i>=1;i--) {
		if((i%a == 0) && (i%b == 0)) {
			boi = i;
		}
	}
	return boi;
}

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n];

	// nhap 
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	// xuat 
	xuat(arr,n);
	
	
	long long int uoc_chung, boi_chung;
	// UCLN
	uoc_chung = arr[0];
	for(i = 1;i<n;i++) { // Chi can duyet tu 1 , UCLN(arr[0], arr[1])
		uoc_chung = UCLN(uoc_chung, arr[i]);
	}
	
	// BCNN
	boi_chung = arr[0];
	for(i = 1;i<n;i++) { // Chi can duyet tu 1 , BCNN(arr[0], arr[1])
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

