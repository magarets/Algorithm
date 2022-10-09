#include <stdio.h>

int main() {
    int Arr_A[51] = {0};
    int Arr_B[51] = {0};
    int n;
    int tmp;
    int sum = 0;

    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%d", &Arr_A[i]); // input Arr_A
    for(int i=0; i<n; ++i) scanf("%d", &Arr_B[i]); // input Arr_B

    for(int i=n; i>0; --i) {
        for(int j=0; j<i; ++j) {
            if(Arr_A[j] < Arr_A[j+1]) {
                tmp = Arr_A[j];
                Arr_A[j] = Arr_A[j+1];
                Arr_A[j+1] = tmp;
            }
            if(Arr_B[j] < Arr_B[j+1]) {
                tmp = Arr_B[j];
                Arr_B[j] = Arr_B[j+1];
                Arr_B[j+1] = tmp;
            }
        }
    }

    for(int i=0; i<n; ++i) {
        sum += Arr_A[n - i - 1] * Arr_B[i];
    }
    printf("%d", sum);
    printf("hello");

    return 0;
}