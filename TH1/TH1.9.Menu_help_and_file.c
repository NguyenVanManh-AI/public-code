#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	char ch;
	printf("ch : "); scanf(" %c", &ch); // them khoang trang truoc %c de bo qua ki tu Enter
	if(ch == 'h' || ch == 'H') printf("Ban chon menu Help");
	if(ch == 'f' || ch == 'F') printf("Ban chon menu File");
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

