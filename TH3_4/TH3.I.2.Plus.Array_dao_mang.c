#include <stdio.h>
#include <math.h>

void xuat(int arr[], int n) {
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
	}
	printf("\n");
}

void program() {
	int i,n;

	do {
		printf("n : "); scanf("%d", &n);	
	} while(n<10);

	int arr[n];

	// nhap 
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	
	// xuat goc
	xuat(arr,n);
	
	// xu li dao mang
	int temp;
	for(i = 0;i < n/2;i++) {
		temp = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] = temp;
	}	

	// xuat mang dao
	xuat(arr,n);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

