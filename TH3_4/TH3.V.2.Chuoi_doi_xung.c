#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

int doi_xung(char str[MAX]) {
	int i, n = strlen(str);
	for(i = 0;i < n/2;i++) {
		if(str[i] != str[n-i-1]) {
			return 0;
		}
	}
	return 1;
}

void program() {
	char str[MAX];
	printf("str : ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	if(doi_xung(str) == 1) {
		printf("Chuoi doi xung !");
	} else {
		printf("Chuoi khong doi xung !");
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

