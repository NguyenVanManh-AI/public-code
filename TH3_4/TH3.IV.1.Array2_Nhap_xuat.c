#include <stdio.h>
#include <math.h>

void xuat(int n, int m, int arr[n][m]) {
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

void nhap(int n, int m, int arr[n][m]) { // Luu y : Phai khai bao int n, int m truoc arr[n][m]
	printf("\n");
	int i,j;
	for(i = 0;i<n;i++) {
		for(j = 0;j<m;j++) {
			printf("A[%d][%d]= ", i,j); scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
}

void program() {
	int n,m;
	printf("n : "); scanf("%d", &n);
	printf("m : "); scanf("%d", &m);
	int arr[n][m];

	nhap(n,m,arr);
	xuat(n,m,arr);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

