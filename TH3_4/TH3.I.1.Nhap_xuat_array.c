#include <stdio.h>
#include <math.h>

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n];
	// nhap 
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	
	// xuat 
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

