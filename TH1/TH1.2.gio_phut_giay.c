#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int h,m,s,n;
	printf("h : "); scanf("%d", &h);
	printf("m : "); scanf("%d", &m);
	printf("s : "); scanf("%d", &s);
	printf("n : "); scanf("%d", &n);
	
	int total_seconds = h*60*60 + m*60 + s + n;
	int new_h = total_seconds / (60*60) % 24; // 24h  
	int new_m = (total_seconds % (60*60)) / 60;
	int new_s = (total_seconds % 60);

	printf("%02d:%02d:%02d", new_h, new_m, new_s); 
	return 0;
}

