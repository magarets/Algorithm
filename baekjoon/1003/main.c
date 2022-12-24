#include <stdio.h>

int memo_one[42];
int memo_zero[42];

int FiboOne(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }
    if(memo_one[n] != 0) {
        return memo_one[n];
    } else {
        memo_one[n] = FiboOne(n - 1) + FiboOne(n - 2);
        return memo_one[n];
    }
}
int FiboZero(int n) {
    if(n == 0) {
        return 1;
    } else if(n == 1) {
        return 0;
    }
    if(memo_zero[n] != 0) {
        return memo_zero[n];
    } else {
        memo_zero[n] = FiboZero(n - 1) + FiboZero(n - 2);
        return memo_zero[n];
    }
}

int main() {
    int cycle_count;
    int fibo_number;
    int count_one;
    int count_zero;

    scanf("%d", &cycle_count);

    for(int i = 0; i < cycle_count; ++i) {
        scanf("%d", &fibo_number);

        if(fibo_number == 0) {
            printf("1 0\n");
            continue;
        }

        for(int j = 1; j <= fibo_number; ++j) {
            count_one = FiboOne(j);
        }
        for(int j = 1; j <= fibo_number; ++j) {
            count_zero = FiboZero(j);
        }
        printf("%d %d\n", count_zero, count_one);
    }
    return 0;
}