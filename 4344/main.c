#include <stdio.h>
#include <string.h>

int InputNumber[10001] = {0};

int CountNumber(int m, float Everage) {

    int count = 0;

    for(int j=0; j<m; ++j)
        if( InputNumber[j] > Everage)
            count++;
    return count;
}

int main() {

    int n, m;
    int SumNum = 0;
    int count;
    float Everage;
    float FNumber;
    float SIZE = 100.0;

    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%d", &m);

        memset(InputNumber, 0, sizeof(InputNumber)); // clear InputNumber
        SumNum = 0; // 점수합 변수 초기화
        count = 0;


        for(int j=0; j<m; ++j) {
            scanf("%d", &InputNumber[j]);
            SumNum += InputNumber[j];
        }// 입력받고 합 저장

        Everage = SumNum / m; // 평균
        count = CountNumber(m, Everage); // 평균넘는 학생 수 계산



        printf("%.3f%%\n", (count / (float)m) * SIZE);
    }

    return 0;
}