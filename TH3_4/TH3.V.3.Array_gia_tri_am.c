#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, double arr[]) {
	printf("\n");
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d]=%lf ", i, arr[i]);
	}
	printf("\n");
}

void nhap(int n, double arr[]) {
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%lf", &arr[i]);
	}
}

void giatriam(int n, double arr[]) {
	printf("\n");
	int i;
	for(i = 0;i<n;i++) {
		if(arr[i] < 0) {
			printf("A[%d]=%lf ", i, arr[i]);
		}
	}
	printf("\n");
}

void program() {
	int n;
	printf("n : "); scanf("%d", &n);
	double arr[n];

	nhap(n,arr);
	xuat(n,arr);
	giatriam(n, arr);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

