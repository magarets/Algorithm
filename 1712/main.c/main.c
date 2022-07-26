#include <stdio.h>

int main() {
    long FixedCost;
    long VariableCost;
    long Cost;
    long TotalCost;

    scanf("%d %d %d", &FixedCost, &VariableCost, &Cost);

    if(Cost - VariableCost <= 0) { // 손익분기점에 도달할 수 없는 경우
        printf("-1");
        return 0;
    }
    TotalCost = FixedCost / (Cost - VariableCost); // 점화식
    printf("%d", ++TotalCost);
    return 0;
}
