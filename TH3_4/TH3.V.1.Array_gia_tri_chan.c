#include <stdio.h>
#include <math.h>
#define MAX 100

void nhap(int arr[MAX], int n) {
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
}

void xuat(int arr[], int n) {
	printf("\n");
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
	}
	printf("\n");
}

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n];

	nhap(arr,n);
	xuat(arr,n);
	
	printf("\nNhung gia tri chan cua mang: \n");
	for(i = 0;i<n;i++) {
		if(arr[i] % 2 ==0) {
			printf("A[%d]=%d ", i, arr[i]);
		}
	}
	printf("\n");
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

