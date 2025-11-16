#include <stdio.h>
#include <math.h>

void for_function(int n) {
	long long int i,chan=1,le=1;
	for(i=1;i<=n;i++) {
		if(i%2==0) chan *= i;
		else le*= i;
	}
	printf("for N chan : %lld\n", chan);
	printf("for N le : %lld\n", le);
}

void while_function(int n) {
	long long int i=1,chan=1,le=1;
	while(i<=n) {
		if(i%2==0) chan *= i;
		else le *= i;
		i++;
	}
	printf("while N chan : %lld\n", chan);
	printf("while N le : %lld\n", le);
}

void do_while_function(int n) {
	long long int i=1,chan=1,le=1;
	do {
		if(i%2==0) chan *= i;
		else le*= i;
		i++;
	} while(i<=n);
	printf("do_while N chan : %lld\n", chan);
	printf("do_while N le : %lld\n", le);
}

long long int de_quy_le(int n) {
    if (n == 1) return 1;      
    if (n % 2 == 1)
        return n * de_quy_le(n - 2);  
    else
        return de_quy_le(n - 1);     
}

long long int de_quy_chan(int n) {
    if (n < 2) return 1;       
    if (n == 2) return 2;      
    if (n % 2 == 0)
        return n * de_quy_chan(n - 2);  
    else
        return de_quy_chan(n - 1);     
}

void program() {
	int n;
	printf("n : "); scanf("%d", &n);
	for_function(n);
	while_function(n);
	do_while_function(n);
	printf("de_quy_le : %lld\n", de_quy_le(n));
	printf("de_quy_chan : %lld", de_quy_chan(n));
}

int main() {
    program();
    printf("\n---------\n");
    return 0;
}

