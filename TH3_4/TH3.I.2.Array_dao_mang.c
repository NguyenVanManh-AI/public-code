#include <stdio.h>
#include <math.h>

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n], arr2[n];
	// nhap 
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	
	// xuat goc
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
		arr2[n-i-1] = arr[i]; // dao mang
	}
	printf("\n");

	// xuat mang dao
	for(i = 0;i<n;i++) {
		printf("A2[%d]=%d ", i, arr2[i]);
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

