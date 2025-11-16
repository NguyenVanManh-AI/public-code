#include <stdio.h>
#include <math.h>
#include <string.h>

// Dem so tu trong chuoi (so tu != ki tu) 

int dem_so_tu(char str[]) {
	int i = 0, in_word = 0, dem = 0;

	for(i = 0;i<strlen(str);i++) {
		if(str[i] != ' ') {
			if(in_word == 0) {
				dem++;
			}
			in_word = 1;
		} else {
			in_word = 0;
		}
	}

	return dem;
}

void program() {
	char str[256];
	printf("str : "); fgets(str, sizeof(str), stdin);
	str[strcspn(str,"\n")] = '\0';
	
	printf("\"%s\" co %d tu", str, dem_so_tu(str));
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

