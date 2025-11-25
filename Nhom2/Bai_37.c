#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAXN 7000000

/* ham phan tich N thanh tong cac so chinh phuong it nhat */
void phan_tich(int n) {
    static int dp[MAXN + 1];
    static int trace[MAXN + 1];

    int i;
    int j;
    int sq;
    int can;

    /* khoi tao dp */
    for (i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
        trace[i] = -1;
    }

    dp[0] = 0;

    /* lap tinh dp */
    for (i = 1; i <= n; i++) {
        can = (int)sqrt(i);
        for (j = can; j >= 1; j--) {
            sq = j * j;
            if (dp[i - sq] + 1 < dp[i]) {
                dp[i] = dp[i - sq] + 1;
                trace[i] = sq;
            }
        }
    }

    /* truy vet */
    i = n;
    printf("Phan tich: ");
    while (i > 0) {
        printf("%d ", trace[i]);
        i = i - trace[i];
    }
    printf("\n");
}

int main() {
    int n;

    printf("Nhap N (N <= 7000000): ");
    scanf("%d", &n);

    if (n < 0 || n > MAXN) {
        printf("N khong hop le\n");
        return 0;
    }

    phan_tich(n);

    return 0;
}
