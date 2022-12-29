#include <stdio.h>

int main() {
    int t;
    int n, m;
    int sub;

    scanf("%d", &t);

    for(int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &m);

        sub = 1;
        for (int j = 0; j < n; ++j) {
            sub *= m - j;
            sub /= j + 1;
        }
        printf("%d\n", sub);
    }
    return 0;
}