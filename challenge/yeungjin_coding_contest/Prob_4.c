#include <stdio.h>
#define SIZE 10

int secretArr[5];
int guessArr[5];
int checkStrike() { // 숫자가 정확히 일치할 때 카운트하는 함수
    int strike = 0;
    for(int i=0; i<4; ++i)
        if(secretArr[i] == guessArr[i])
            strike++;
    return strike;
}
int checkBall() { // 숫자가 포함되어있지만 다른자리에 있을 때 카운트하는 함수
    int ball = 0;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j) {
            if (secretArr[i] == guessArr[j] && i != j) // 숫자가 포함되어있지만, 자리 수가 다를 때 로직
                ball++;
        }
    }
    return ball;
}

int main() {
    int secretNum; // 비밀 수
    int guessNum; // 맞추는 수

    scanf("%d %d", &secretNum, &guessNum);

    for(int i=0; i<4; ++i) { // C에서는 각 자리를 일일히 분리할 수 없어서 이렇게 직접 떼줘야함.. 아니면 문자열로 처리하면 되긴하는데 이게 젤 편함
        secretArr[i] = secretNum % SIZE;
        guessArr[i] = guessNum % SIZE;
        secretNum /= SIZE;
        guessNum /= SIZE;
    }

    printf("%d ", checkStrike()); // 스트라이크 출력
    printf("%d", checkBall()); // 볼 출력
    return 0;
}