#include <stdio.h>
#include <math.h>
#include <string.h>

void program() {
	int age; 
	char name1[256] , name2[256];
	char ch;
	
	char diachi[] = "Thanh Pho Hue";
	char quocgia[256] = "Viet Nam";
	char kytu = 'A';
	char chuoikytu[4] = {'A','A','A','A'}; 
	
	printf("age : "); scanf("%d", &age);
	getchar(); // remove \n 
	
	printf("ch : "); scanf(" %c", &ch);
	
	printf("name1 : "); gets(name1);
	
	printf("name2 : ");
	fgets(name2, sizeof(name2), stdin);  
	name2[strcspn(name2, "\n")] = '\0';  
	
	
	
	printf("%d , %s , %s , %s , %c , %s , %s", age, name1, name2, diachi, kytu, quocgia, chuoikytu);
}

int main() {
    while (1) {
        program();
        printf("\n---------\n");
    }
    return 0;
}

