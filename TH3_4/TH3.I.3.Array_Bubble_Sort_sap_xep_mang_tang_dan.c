#include <stdio.h>
#include <math.h>

void xuat(int arr[], int n) {
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

	// nhap 
	for(i = 0;i<n;i++) {
		printf("A[%d] : ", i); scanf("%d", &arr[i]);
	}
	
	// xuat goc
	xuat(arr,n);
	
	// Bubble Sort (Thuat toan sap xep co ban nhat)
	// sap xep mang // DUNG test case : 3 4 5 1 2 -> 1 2 3 4 5 
	int temp,j;
	for(i = 0;i < n;i++) {
//		for(j = 0;j < n - 1;j++) { // phai gan j = 0 , thay vi j = i  // Chua toi uu 
		for(j = 0; j < n - i - 1; j++) { // Toi uu , chi so toi phan chua sap xep
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	// xuat mang dao
	xuat(arr,n);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}


//	// sap xep mang // SAI , test case : 3 4 5 1 2 -> 3 1 2 4 5  
//	int temp,j;
//	for(i = 0;i < n;i++) {
//		for(j = i;j < n - 1;j++) {
//			if(arr[j] > arr[j+1]) {
//				temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
