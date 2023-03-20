#include <stdio.h>

int main(){

    int arr[101] = {0};
    int n, m;
    int x, y, z;

    scanf("%d %d ", &n, &m);

    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", &x, &y, &z);
        for(int j = x; j <= y; ++j){
            arr[j] = z;
        }
    }      
    for(int i = 1; i <= n; ++i){
        printf("%d ", arr[i]);
    }  
    return 0;
}
