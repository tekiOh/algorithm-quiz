//
// Created by vkdne on 2018-09-25.
//

#include <iostream>

using namespace std;

int map[50][50];
int N, M, sy, sx, d;
int sol;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void clean() {
    int ny,nx,nd;
    nd = d;
    bool chk = false;
    //4방향 탐색
    for(int i = 0 ;i < 4; i++){
        //왼쪽으로 회전
        if(nd == 0)
            nd = 3;
        else
            nd--;
        //회전하고 전방에 있는 칸 검사
        nx = sx + dx[nd];
        ny = sy + dy[nd];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 0){
            map[ny][nx] = 3;
            sol++;
            sx = nx;
            sy = ny;
            d = nd;
            chk = true;
            break;
        }
    }
    //4방향이 다 청소되었거나 벽인 경우
    if(!chk){
        nd = (d+2)%4;
        nx = sx + dx[nd];
        ny = sy + dy[nd];
        //한칸 뒤로 후진, 후진할 수 없으면 정지
        if(nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] != 1){
            sx = nx;
            sy = ny;
            clean();
        }
        else{
            return;
        }
    }
    //4방향중 청소할곳이 있으면 그곳으로 이동후 다시 탐색
    if(chk)
        clean();
}

int main() {
    cin >> N >> M >> sy >> sx >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    map[sy][sx] = 3;
    sol++;
    clean();
    cout << sol << endl;
    return 0;
}