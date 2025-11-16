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

int doi_xung(int n, int arr[MAX][MAX]) {
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(arr[i][j] != arr[j][i]) {
				return 0;
			}
		}
	}
	return 1;
}

void program() {
	int n;
	printf("n : "); scanf("%d", &n);
	int arr[MAX][MAX];

	nhap(n,n,arr);
	xuat(n,n,arr);
	
	if(doi_xung(n,arr) == 1) {
		printf("Ma tran doi xung !");
	} else {
		printf("Ma tran khong doi xung !");
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

