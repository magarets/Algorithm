#include <stdio.h>

int main(){

    int arr[101] = {0};
    int n, m;
    int a, b;
    int tmp;
    
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i){
        arr[i] = i; 
    }
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &a, &b);
        tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}
