#include <stdio.h>

int arr[8] = {100, 50, 20, 10, 5, 2, 1};

int sub(int left, int right) {
    if(left > right) return left - right;
    else return right - left;
}

int dp(int num){
    int cnt = 0;
    int tmp = 0;

    for(int i=0; i<7; ++i) {
        if (num >= arr[i]) {
            tmp = num / arr[i];
            num -= tmp * arr[i];
            cnt += tmp;
        }
        //printf("arr[i] = %d, num = %d, cnt = %d\n", arr[i], num, tmp);
        if(num == 0) return cnt;
    }
}

int main() {
    int n; // 2 <= n <= 10,000
    int rock;

    int Left = 0;
    int Right = 0;

    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        scanf("%d", &rock);

        /*      setting     */
        if(i == 0) {
            Left += rock;
            continue;
        }
        if(i == 1) {
            Right += rock;
            continue;
        }

        if(Left == Right) Left += rock;
        else {
            if(Left < Right) Left += rock;
            else Right += rock;
        }
    }

    printf("%d", dp(sub(Left, Right)));

    return 0;
}
