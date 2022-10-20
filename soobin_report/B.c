#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}array;

typedef struct {
    int a;
    int b;
    int c;
}thread;

typedef struct {
    int sub;
}gap;

// sorting arr
int sort(array* arr, int n) {
    int tmp;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j){
            if(arr[i].y > arr[j].y) {
                // y
                tmp = arr[i].y;
                arr[i].y = arr[j].y;
                arr[j].y = tmp;
                // x
                tmp = arr[i].x;
                arr[i].x = arr[j].x;
                arr[j].x = tmp;
            }
        }
    }
}
// sorting arr then equal y
int sort2(array* arr, int n) {
    int tmp;
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            if(arr[j].x > arr[j+1].x && arr[j].y == arr[j+1].y) {
                tmp = arr[j].x;
                arr[j].x = arr[j+1].x;
                arr[j+1].x = tmp;
            }
        }
    }
}

int greed(array* arr, int n) {
    thread th; // 마지막 작업시간
    gap gap[4];
    th.a = 0;
    th.b = 0;
    th.c = 0;

    int count = 1;
    th.a = arr[0].y;
    for(int i=1; i<n; ++i) { // 각 스레드별로 동적할당
        int flag = 0;
        gap[0].sub = -1;
        gap[1].sub = -1;
        gap[2].sub = -1;

        if(th.a <= arr[i].x) { // 피벗이 되는 스레드
            /*
            if(th.a == arr[i].x) { // 같으면 넣고 빠지기
                th.a = arr[i].y;
                count++;
                continue;
            }*/
            gap[0].sub = arr[i].x - th.a;
            flag = 1;
        }
        if(th.b <= arr[i].x) {
            /*
            if(th.b == arr[i].x) { // 같으면 넣고 빠지기

                th.b = arr[i].y;
                count++;
                continue;
            }*/
            gap[1].sub = arr[i].x - th.b;
            flag = 1;
        }
        if(th.c <= arr[i].x) {
            /*
            if(th.c == arr[i].x) { // 같으면 넣고 빠지기

                th.c = arr[i].y;
                count++;
                continue;
            }*/
            gap[2].sub = arr[i].x - th.c;
            flag = 1;
        }

        if(flag == 0)
            continue;

        // sub 의 최솟값 구하기
        int min = 99999;
        int p;
        for(int j=0; j<3; ++j) {
            if (min > gap[j].sub && gap[j].sub != -1) {
                min = gap[j].sub; // 차이가 최솟값을 가지고 있는 스레드 => 값을 업데이트 해주어야 될 스레드
                p = j + 1;
            }
        }

        /* update thread */
        // gap.end : 업데이트를 해야할 스레드 위치
        if(p == 1) {
            th.a = arr[i].y;
            //printf("1: %d <= %d %d\n", th.a, arr[i].x, arr[i].y);
            count++;
        }
        else if(p == 2) {
            th.b = arr[i].y;
            //printf("2: %d <= %d %d\n", th.b, arr[i].x, arr[i].y);
            count++;
        }
        else if(p == 3) {
            th.c = arr[i].y;
            //printf("3: %d <= %d %d\n", th.c, arr[i].x, arr[i].y);
            count++;
        }
    }
    return count;
}

int main() {

    array arr[1001] = {0}; // 구조체 배열
    int arrCount[250] = {0}; // 각 자리 숫자의 갯수 카운트
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; ++i) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        arrCount[arr[i].y]++;
    }

    // sort
    sort(arr, n);

    // x sort
    sort2(arr, n);

    printf("%d", greed(arr, n));
    return 0;
}
