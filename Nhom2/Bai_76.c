#include <stdio.h>

void nhapMaTran(double a[][50], int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("A[%d][%d] = ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
    }
}

void xuatMaTran(double a[][50], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%15.3f ", a[i][j]);
        }
        printf("\n");
    }
}

double minHang(double a[][50], int n, int dong){
    double min = a[dong][0];
    for(int j=1;j<n;j++){
        if(a[dong][j] < min) min = a[dong][j];
    }
    return min;
}

int main(){
    int n;
    double A[50][50];

    do{
        printf("Nhap n (n > 0): ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("Nhap ma tran A:\n");
    nhapMaTran(A, n);

    printf("Ma tran A vua nhap:\n");
    xuatMaTran(A, n);

    double sum = 0;

    for(int i=0;i<n;i++){
        double minn = minHang(A, n, i);    
        A[i][n-1-i] = minn;                
        sum += minn;
    }

    printf("Ma tran sau khi dua phan tu nho nhat tung hang len duong cheo phu:\n");
    xuatMaTran(A, n);

    printf("Tong cac phan tu nho nhat duoc dua len duong cheo phu = %.3f\n", sum);

    return 0;
}
