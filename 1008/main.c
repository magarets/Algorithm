#include <stdio.h>

int main() {
    double x, y;
    double x_1;
    int y_1;
    int a, b;

    int cnt = 0;

    scanf("%lf %lf", &x, &y);

    x_1 = x / y; // x_1는 몫
    y_1 = (int)x % (int)y; // y_1는 나머지
    if(y_1 == 0) {
        printf("%d", (int) x_1);
        return 0;
    }

    if(x > y) { // 왼쪽이 클때. 결과값이 무조건 정수임
        printf("%d.", (int) x_1);
        a = y_1;
        b = (int) y;
        while(a % b != 0) { // a 에 10을 곱한 뒤, b를 나눈 나머지가 0일때까지.
            a *= 10;
            printf("%d", a / b); // 한글자씩 떼서 나눈다음에 소수점 뒤에 붙임
            a %= b;
            cnt ++;
            if(cnt > 32) return 0; // anti-infinite_roop
        }
    }
    else { // 오른쪽이 클 때. 즉 결과값이 무조건 실수 일
        printf("0.");
        a = y_1;
        b = (int) y;
        while(a % b != 0) {
            a *= 10;
            printf("%d", a / b);
            a %= b;
            cnt ++;
            if(cnt > 32) return 0;
        }
    }
}