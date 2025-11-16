#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, int m, int arr[MAX][MAX]) { 
	printf("\n");
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			printf("A[%d][%d]=%d ", i,j, arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void nhap(int n, int m, int arr[MAX][MAX]) {
	printf("\n");
	int i,j;
	for(i = 0;i<n;i++) {
		for(j = 0;j<m;j++) {
			printf("A[%d][%d]= ", i,j); 
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
}

int max(int n, int arr[MAX][MAX]) {
	int i,j;
	int max = arr[0][0];
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			max = (max > arr[i][j]) ? max : arr[i][j];
		}
	}
	return max;
}

void program() {
	int n;
	printf("n : "); scanf("%d", &n);
	int arr[MAX][MAX];

	nhap(n,n,arr);
	xuat(n,n,arr);
	
	printf("Gia tri lon nhat cua ma tran vuong la: %d", max(n,arr));
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

