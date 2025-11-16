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
	char str[256], unique_str[256] = "";
	printf("str : "); 
	//	gets(str); // Lien quan den bao mat
	fgets(str, sizeof(str), stdin); str[strcspn(str, "\n")] = '\0';
	
	int i;
	printf("|");
	for(i = 0;i<strlen(str);i++) {
		printf("%c", str[i]);
        if (strchr(unique_str, str[i]) == NULL) {
            int len = strlen(unique_str);
            unique_str[len] = str[i];
            unique_str[len + 1] = '\0';
        }
	}
	printf("|\n");
	
	for(i = 0;i<strlen(unique_str);i++) {
		printf("%c : %d\n", unique_str[i], dem_ki_tu(str, unique_str[i]));
	}
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

