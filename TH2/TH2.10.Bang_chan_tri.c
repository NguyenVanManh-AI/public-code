#include <stdio.h>
#include <math.h>

void program() {
    printf("AND\n");
    printf("0 AND 0 = %d\n",0&&0);
    printf("0 AND 1 = %d\n",0&&1);
    printf("1 AND 0 = %d\n",1&&0);
    printf("1 AND 1 = %d\n",1&&1);
    
    printf("\nOR\n");
    printf("0 OR 0 = %d\n",0||0);
    printf("0 OR 1 = %d\n",0||1);
    printf("1 OR 0 = %d\n",1||0);
    printf("1 OR 1 = %d\n",1||1);
    
    printf("\nXOR\n");
    printf("0 XOR 0 = %d\n",0^0);
    printf("0 XOR 1 = %d\n",0^1);
    printf("1 XOR 0 = %d\n",1^0);
    printf("1 XOR 1 = %d\n",1^1);
    
    printf("\nNOT\n");
    printf("NOT 0 = %d\n",!0);
    printf("NOT 1 = %d\n",!1);
    
    printf("\nNAND = !AND\n");
    printf("0 NAND 0 = %d\n",!(0&&0));
    printf("0 NAND 1 = %d\n",!(0&&1));
    printf("1 NAND 0 = %d\n",!(1&&0));
    printf("1 NAND 1 = %d\n",!(1&&1));
    
    printf("\nNOR = !OR\n");
    printf("0 NOR 0 = %d\n",!(0||0));
    printf("0 NOR 1 = %d\n",!(0||1));
    printf("1 NOR 0 = %d\n",!(1||0));
    printf("1 NOR 1 = %d\n",!(1||1));
}

int main() {
    program();
    printf("\n---------\n");
    return 0;
}

