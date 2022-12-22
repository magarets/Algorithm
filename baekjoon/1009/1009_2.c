#include <stdio.h>

int getComputerNumber(int number, int exponent){
    int x = number;
    for(int i = 1; i < exponent; ++i) {
        x %= 10;
        x *= number;
    }
    return x % 10;
}


int main(){

    int cycle_count;
    int number;
    int exponent;
    int result;
    int i;

    scanf("%d", &cycle_count);

    for(i = 0; i < cycle_count; ++i) {
        scanf("%d %d", &number, &exponent);
        result = getComputerNumber(number, exponent % 4 != 0 ? (exponent % 4) : (4));
        printf("%d\n", result % 10 == 0 ? (10) : (result));
    }

    return 0;
}
