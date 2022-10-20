#include <stdio.h>
#include <string.h>

int w = 0, h = 0;
int count = 0;

int visit[51][51] = {-1, }; // 방문 배열

int map[51][51] = {0, }; // 문제에 명시된 맵 크기 : 50

// 좌, 하, 우, 상
int dy[5] = {-1, 0, 1, 0};
int dx[5] = {0, -1, 0, 1};

void visitMap(int y, int x){
    visit[y][x] = 1; // 방문표시
    count++;
    for (int i = 0; i < 4; ++i){
        int my = y + dy[i];
        int mx = x + dx[i];

        if (0 <= my && my <= h && 0 <= mx && mx <= w && map[my][mx] == 1 && visit[my][mx] == -1){ // 범위 설정 잘못한듯 ㅜ.ㅜ
            visitMap(my, mx);
        }
    }
}

int main(void)
{
    int t;
    char inputMap[51];

    scanf("%d", &t);
    for(int l=0; l<t; ++l){
        int result = 0;
        int max = 0;

        memset(visit, -1, sizeof(visit));
        memset(map, '\0', sizeof(map));
        memset(inputMap, '\0', sizeof(inputMap));

        scanf("%d %d", &w, &h);

        for(int i=0; i<h; ++i) {

            scanf("%s", inputMap);

            for(int j=0; j<w; ++j) {
                if(inputMap[j] == '.')
                    map[i][j] = 0;

                if(inputMap[j] == '*')
                    map[i][j] = 1;
            }
        }
        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j)
                if(map[i][j] == 1)
                    visit[i][j] == -1;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == 1 && visit[i][j] == -1){ // 한번도 방문하지 않은 땅일경우 진입
                    visitMap(i, j);
                    ++result;
                    if(max < count) max = count;
                    count = 0;
                }
            }
        }

        printf("%d %d\n", result, max);
    }
    return 0;
}
