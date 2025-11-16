#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, int m, int arr[MAX][MAX]) { // Note : arr[MAX][MAX] instead of arr[n][m]
// Neu khong se khong in ra dung ket qua. Hay thu su dung arr[n][m] sau do in ra se thay loi sai. 
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

void xoa_cot(int n, int m, int arr[MAX][MAX], int k) {
	int i,j;
	for(i = 0;i<n;i++) {
		for(j = k-1;j<m-1;j++) {
			arr[i][j] = arr[i][j+1];
		}
	}
}

void program() {
	int n,m,k;
	printf("n : "); scanf("%d", &n);
	printf("m : "); scanf("%d", &m);
	printf("k : "); scanf("%d", &k);
	int arr[MAX][MAX];

	nhap(n,m,arr);
	printf("Ma tran ban dau:\n");
	xuat(n,m,arr);

	xoa_cot(n,m,arr,k);
	m--;

	printf("Ma tran sau khi xoa cot %d:\n", k);
	xuat(n,m,arr);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

