#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define SIZE 20003

int x[20003];
int y[20003];

void merge(int piv[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int i_ = p, j_ = q+1, k_ = p;

    int tmp[20003];
    int tmp_[20003];

    for(int i=0; i<SIZE; ++i) {
        tmp[i] = 0;
        tmp_[i] = 0;
    }

    while(i<=q && j<=r) {
        if(piv[i] <= piv[j]) {
            tmp[k++] = piv[i++];
            tmp_[k_++] = y[i_++];
        }
        else {
            tmp[k++] = piv[j++];
            tmp_[k_++] = y[j_++];
        }
    }

    while(i<=q) {
        tmp[k++] = piv[i++];
        tmp_[k_++] = y[i_++];
    }

    while(j<=r) {
        tmp[k++] = piv[j++];
        tmp_[k_++] = y[j_++];
    }

    for(int a = p; a<=r; a++) {
        piv[a] = tmp[a];
        y[a] = tmp_[a];
    }
}

void mergeSort(int data[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}

int sPow(int x) {
    return x * x;
}

int uDistance(int* x, int* y, int n) {

    int min = INT_MAX;
    int dis;
    int point;

    for(int i=0; i<n-1; ++i) { // 마지막 문자는 비교대상으로 지정
        dis = sqrt((sPow(abs(x[i + 1] - x[i])) + sPow(abs(y[i + 1] - y[i])))); // uclid distance
        if (dis > 0) {  // overflow
            if(min > dis) {
                min = dis;
                point = i; // 최솟값 좌표 위치
            }
        }
    }
    return point;
}

void moveArr(int *x, int *y, int point, int length) {
    for(int i=point; i<length; ++i) {
        x[i] = x[i + 1];
        y[i] = y[i + 1];
    }
}

int main(){
    int n;

    scanf("%d", &n);

    // 입력
    for(int i=0; i<n; ++i)
        scanf("%d %d", &x[i], &y[i]);

    // merge sort
    for(int i=0; i<n; ++i) {
        mergeSort(x, 0, n);
    }

    // 배열에서 merge sort를 위한 피벗(0,0) 단 1개 삭제 (input으로 0,0 들어올 수 있기때문)
    bool flag = true;
    for(int i=0; i<n; ++i) {
        if (x[i] == 0 && y[i] == 0 && flag == true) {
            moveArr(&x, &y, i, n);
            flag = false;
        }
    }

    int point;
    //uclid distance 구하기
    point = uDistance(&x, &y, n);

    // 출력
    // x의 값이 같을경우
    if(x[point] == x[point + 1]) {
        if(y[point] < y[point + 1])
            printf("(%d, %d) (%d, %d)", x[point], y[point], x[point + 1], y[point + 1]);
        else
            printf("(%d, %d) (%d, %d)", x[point + 1], y[point + 1], x[point], y[point]);
    }
    else
        printf("(%d, %d) (%d, %d)", x[point], y[point], x[point + 1], y[point + 1]);
    return 0;
}



