#include <stdio.h>
#define SIZE 100 // 문제에 지도 크기 범위에 대한 명시 X

int map[101][101]; // 문제에 지도 크기 범위에 대한 명시가 되어있지 않아 임의로 설정
int visit[101][101]; // map이랑 똑같음
int cnt;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int visitMap(int y, int x){ // 섬이 있는지 체크
    if(!map[y][x] || visit[y][x]) // 방문을 한번 한 섬이라면 다시 체크 ㄴㄴ
        return 0;

    visit[y][x] = 1;

    for(int i=0; i<sizeof(dy); ++i) {
        int my = y + dy[i];
        int mx = x + dx[i];

        if(my < 0 || mx < 0 || my > SIZE || mx > SIZE) // 맵 밖을 탐색하는거 방지
            continue;
        if(map[my][mx] && !visit[my][mx]) // 한번도 방문하지 않은 섬을 찾았을 경우
            visitMap(my, mx);
    }

    return 1;
}

int main() {
    int mapSize;

    scanf("%d", &mapSize);
    for(int i=0; i<mapSize; ++i)
        for(int j=0; j<mapSize; ++j)
            scanf("%d", &map[i][j]);

    for(int i=0; i<mapSize; ++i)
        for(int j=0; j<mapSize; ++j)
            cnt += visitMap(i, j);
    printf("%d", cnt);

    return 0;
}