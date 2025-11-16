#include <stdio.h>
#include <math.h>
#define MAX 100

void xuat(int n, int m, int arr[MAX][MAX], char matrix) { 
	printf("\n");
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			printf("%c[%d][%d]=%d ", matrix, i,j, arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void nhap(int n, int m, int arr[MAX][MAX], char matrix) {
	printf("\n");
	int i,j;
	for(i = 0;i<n;i++) {
		for(j = 0;j<m;j++) {
			printf("%c[%d][%d]= ", matrix,i,j); 
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
}

void nhan_ma_tran(int m, int n, int p, int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX]) {
	int i,j,k;
	for(i=0;i<m;i++) {
		for(j=0;j<p;j++) {
			c[i][j] = 0;
			for(k=0;k<n;k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void program() {
	int m,n,p;
	printf("m : "); scanf("%d", &m);
	printf("n : "); scanf("%d", &n);
	printf("p : "); scanf("%d", &p);
	int a[MAX][MAX];
	int b[MAX][MAX];
	int c[MAX][MAX];

	nhap(m,n,a,'A');
	nhap(n,p,b,'B');
	xuat(m,n,a,'A');
	xuat(n,p,b,'B');
	
	nhan_ma_tran(m,n,p,a,b,c);
	xuat(m,p,c,'C');
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

