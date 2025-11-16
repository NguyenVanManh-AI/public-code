#include <stdio.h>
#include <math.h>
#include <string.h>

int dem_ki_tu(char str[], char kitu) {
	int i,dem = 0;
	
	for(i=0;i<strlen(str);i++) {
		if(kitu == str[i]) dem++;
	}
	return dem;
}

void program() {
	char str[256];
	printf("str : "); gets(str);
	
	int i;
	printf("|");
	for(i = 0;i<strlen(str);i++) {
		printf("%c", str[i]);
		if(i != strlen(str) - 1) printf(" ");
	}
	printf("|\n");
	
	for(i = 0;i<strlen(str);i++) {
		printf("%c : %d\n", str[i], dem_ki_tu(str, str[i]));
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

