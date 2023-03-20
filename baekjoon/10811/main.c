#include <stdio.h>

int main(){

    int arr[101] = {0};

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i){
        arr[i] = i;
    }

    int a, b, tmp;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &a, &b);
        if(a == b){
            continue;
        }
        for(int j = a; j <= (a+b)/2; ++j){
            tmp = arr[b+a-j];
            arr[b+a-j] = arr[j];
            arr[j] = tmp;
        }
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ", arr[i]);
    }
    return 0;
}
