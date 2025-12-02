#include <stdio.h>
#include <stdlib.h>

// 1. Ham nhap ma tran
void nhapMat(float a[][50], int m, int n) {
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%f", &a[i][j]);
        }
}

// 2. Ham xuat ma tran
void xuatMat(float a[][50], int m, int n) {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%8.2f", a[i][j]);
        printf("\n");
    }
}

// 3. Ham nhan ma tran A (m x n) va B (n x q)
void nhanMat(float A[][50], float B[][50], float C[][50], int m, int n, int q) {
    for(int i=0;i<m;i++)
        for(int j=0;j<q;j++){
            C[i][j] = 0;
            for(int k=0;k<n;k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// 4. Ham chuyen vi ma tran
void chuyenVi(float a[][50], float b[][50], int m, int n) {
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            b[j][i] = a[i][j];
}

// 5. Tim phan tu lon nhat tren 1 dong
float timMaxDong(float a[][50], int n, int dong){
    float max = a[dong][0];
    for(int j=1; j<n; j++) 
        if(a[dong][j] > max) max = a[dong][j];
    return max;
}

// 6. Tim phan tu nho nhat trong 1 cot
float timMinCot(float a[][50], int n, int cot){
    float min = a[0][cot];
    for(int i=1;i<n;i++)
        if(a[i][cot] < min) min = a[i][cot];
    return min;
}

// 5. Doi sang co so bat ky tu 2 den 16
void doiCoSo(int so, int base){
    char cs[] = "0123456789ABCDEF";
    char kq[50];
    int i=0;

    if(so == 0){
        printf("0");
        return;
    }

    while(so > 0){
        kq[i++] = cs[so % base];
        so /= base;
    }

    for(int j=i-1; j>=0; j--) printf("%c", kq[j]);
}

// 7. Tinh hang cua ma tran bang Gauss
int rankMatrix(float a[][50], int m, int n){
    int rank = n;

    for(int r=0; r<rank; r++){
        if(a[r][r] != 0){
            for(int i=0; i<m; i++){
                if(i != r){
                    float ratio = a[i][r] / a[r][r];
                    for(int j=0; j<rank; j++)
                        a[i][j] -= ratio * a[r][j];
                }
            }
        } else {
            int reduce = 1;

            for(int i=r+1; i<m; i++){
                if(a[i][r] != 0){
                    for(int j=0; j<rank; j++){
                        float temp = a[r][j];
                        a[r][j] = a[i][j];
                        a[i][j] = temp;
                    }
                    reduce = 0;
                    break;
                }
            }

            if(reduce){
                rank--;
                for(int i=0; i<m; i++)
                    a[i][r] = a[i][rank];
            }
            r--;
        }
    }

    return rank;
}

int main(){
    int m,n,q;
    float A[50][50], B[50][50], C[50][50], T[50][50];

    printf("Nhap m,n,q: ");
    scanf("%d%d%d",&m,&n,&q);

    printf("Nhap ma tran A:\n");
    nhapMat(A,m,n);

    printf("Nhap ma tran B:\n");
    nhapMat(B,n,q);

    printf("Ma tran A:\n"); 
    xuatMat(A,m,n);

    printf("Ma tran B:\n"); 
    xuatMat(B,n,q);

    // 3. Nhan ma tran
    nhanMat(A,B,C,m,n,q);
    printf("A * B = \n"); 
    xuatMat(C,m,q);

    // 4. Chuyen vi ma tran tich
    chuyenVi(C,T,m,q);
    printf("Chuyen vi cua tich:\n"); 
    xuatMat(T,q,m);

    // 5. Neu A la ma tran vuong
    if(m == n){
        int sum = 0;
        for(int i=0;i<n;i++){
            float maxx = timMaxDong(A,n,i);
            A[i][i] = maxx; // dua phan tu lon nhat len duong cheo
            sum += maxx;
        }

        printf("Ma tran A sau khi dua max len duong cheo chinh:\n");
        xuatMat(A, m, n);

        int base;
        printf("Tong = %d\nNhap co so (2-16): ", sum);
        scanf("%d",&base);

        printf("Tong doi sang co so %d: ", base);
        doiCoSo(sum, base);
        printf("\n");
    }

    // 6. Neu B la ma tran vuong
    if(n == q){
        for(int i=0;i<n;i++){
            float minn = timMinCot(B,n,i);
            B[i][n-1-i] = minn; // dua phan tu nho nhat len duong cheo phu
        }
        printf("Ma tran B sau khi dua min len cheo phu:\n");
        xuatMat(B,n,q);
    }

    // 7. Tinh hang cua ma tran B
    float temp[50][50];
    for(int i=0;i<n;i++)
        for(int j=0;j<q;j++)
            temp[i][j] = B[i][j];

    printf("Rank(B) = %d\n", rankMatrix(temp, n, q));

    return 0;
}

