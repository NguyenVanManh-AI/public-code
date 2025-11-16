#include <stdio.h>
#include <math.h>

void xuat(int arr[], int n) {
	printf("\n");
	int i;
	for(i = 0;i<n;i++) {
		printf("A[%d]=%d ", i, arr[i]);
	}
	printf("\n");
}

void xoa_am(int *arr, int *n) {
	int i = 0;
	while (i < *n) {
		if(arr[i] < 0) {
			int j;
			for(j = i;j<*n -1;j++) {
				arr[j] = arr[j+1];
			}
			(*n)--;
			continue;
		}
		i++;
	} 
}

void program() {
	int i,n;
	printf("n : "); scanf("%d", &n);
	int arr[n];

	// nhap xuat
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	xuat(arr,n);
	
	// xoa am
	xoa_am(arr, &n);
	
	printf("\nMang sau khi loai bo gia tri am");
	xuat(arr,n);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

