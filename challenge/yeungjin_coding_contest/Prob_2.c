
#include <stdio.h>

int bugCount(int frogEatBugs) {
    int frog = frogEatBugs / 2; // 개구리는 두꺼비의 반
    int dragonFly = frog / 5; // 잠자리는 개구리의 5분의 1
    int chicken = dragonFly * 20; // 암탉은 잠자리의 20배

    return frogEatBugs + frog + dragonFly + chicken ; // 총 파리 수
}
int main() {

    int frogEatBugs;

    scanf("%d", &frogEatBugs);
    printf("%d", bugCount(frogEatBugs));
    return 0;
}