#include <stdio.h>
#include <math.h>

void program1() {
	int i,j;
	for(i=1;i<=10;i++) {
		for(j=2;j<=10;j++) {
			printf("%dx%d=%d\t",j,i,i*j);
		}
		printf("\n");
	}
}

void program2() {
	int i,j;
	for(i=1;i<=10;i++) {
		for(j=2;j<=10;j++) {
			printf("-------");
		}
		printf("\n");
		for(j=2;j<=10;j++) {
			printf("|"); printf("%dx%d=%2d",j,i,i*j); 
		}
		printf("\n");
	}
}

int main() {
    while (1) {
        program1();
        printf("\n\n");
        program2();
        printf("\n\n");
        break;
    }
    return 0;
}

