#include <stdio.h>

int sqa(int x, int y) {
    int n = 1;
    if( y == 0 ) y = 4;
    for(int i=0; i<y; ++i) {
        n *= x;
        n %= 10;
    }
    if( n == 0) n = 10;
    return n;
}

int main() {
    int n;
    int a, b;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", sqa(a % 10, b % 4));
    }
}