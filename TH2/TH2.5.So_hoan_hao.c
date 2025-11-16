#include <stdio.h>
#include <math.h>

int soHoanHao(int n) {
	int i,s = 0;
	for(i=1;i<n;i++) {
		if(n%i == 0) s += i;
	}
	if(n == s) return 1;
	else return 0;
}

void program() {
	int i,n=1000;
	for(i=1;i<n;i++) {
		if(soHoanHao(i) == 1) {
			printf("%d\n", i);
		}
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
        break;
    }
    return 0;
}

