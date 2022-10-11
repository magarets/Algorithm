#include <stdio.h>

int age(int Mod_3, int Mod_5, int Mod_7) {
    return((Mod_3 * 70) + (Mod_5 * 21) + (Mod_7 * 15)) % 105;
}

int main() {
    int Mod_3;
    int Mod_5;
    int Mod_7;

    scanf("%d %d %d", &Mod_3, &Mod_5, &Mod_7);

    printf("%d", age(Mod_3, Mod_5, Mod_7));
    return 0;
}