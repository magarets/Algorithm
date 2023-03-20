#include <stdio.h>

int main(){
    int n;
    int byte_size;

    scanf("%d", &n);

    byte_size = n % 4 == 0 ? n / 4 : n / 4 + 1;

    for(int i = 0; i < byte_size; ++i){
        printf("long ");
    }
    printf("int");
    return 0;
}
