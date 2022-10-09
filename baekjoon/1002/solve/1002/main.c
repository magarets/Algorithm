#include <stdio.h>

int map1[20001][20001];
int map2[20001][20001];

int min(int x, int y) {

    if(0 > y) {
        return 0 - y;
    }
    else
        return 0 - x;
    //return x > y ? y : x;
}

int main() {
    int x1, x2, y1, y2, r1, r2;
    int min_x;
    int min_y;
    int n;
    scanf("%d", &n); // input count

    for(int i=0; i<n; ++i) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        /*
         * x1, y1 : first
         * x2, y2 : second
         */
        min_x = min(x1, x2);
        min_y = min(y1, y2);
        // 좌표 이동
        x1 += min_x;
        x2 += min_x;
        y1 += min_y;
        y2 += min_y;
        printf("(%d, %d), (%d, %d)\n", x1, y1, x2, y2);
    }

    return 0;
}
