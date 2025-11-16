#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {	
	char ch;
	printf("ch : "); scanf(" %c", &ch); // co khoang trang de bo qua ki tu Enter truoc do 
	if('a' <= ch && ch <= 'z') printf("Uppercase of %c is %c", ch, (int) ch-32); // True : 'a' ; False : "a"
	else if ('A' <= ch && ch <= 'Z') printf("Lowercase of %c is %c", ch, (int) ch+32); // Phai su dung nhay don . Khong su dung nhay kep
	else printf("%c khong phai la chu cai!\n", ch); 
}

int main() {
	while(1) {
		program();
		printf("\n---------\n");
	}
	return 0;
}

