#include <stdio.h>
#include <math.h>

void program() {
	int f;
	double c;
	for(f=0;f<=300;f+=20) {
		printf("%d F <--> %lf C\n",f,5.0*(f - 32.0)/9.0);
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

