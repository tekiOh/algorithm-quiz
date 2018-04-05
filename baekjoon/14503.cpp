//
// Created by vkdne on 2018-04-05.
//
#include <iostream>

using namespace std;

int map[51][51];
int visit[51][51];
int direction; //0 : 북, 1 : 동, 2 : 남, 3 : 서
int dx[4] = {0,1,0,-1}; //북동남서
int dy[4] = {-1,0,1,0}; //북동남서
int N,M;
int sol;
int changeDirection(int a){
    if(a == 0)
        return 3;
    else
        return a - 1;
}
int goback(int a){
    if(a == 0)
        return 2;
    if(a == 1)
        return 3;
    if(a == 2)
        return 0;
    if(a == 3)
        return 1;
}
int main(){
    int posy,posx;
    cin >> N >> M;
    cin >> posy >> posx >> direction ;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            cin >> map[i][j];
    posx++;
    posy++;
    //초기 위치 청소
    sol++;
    visit[posy][posx] = 1;
    int nd,ny,nx;
    while(1){
        //4방향을 검사했을 때 다 청소할수없는지 판단하는 변수
        bool chk = false;
        //4방향검사
        for(int i = 0 ; i < 4 ;i++) {
            //현재 방향의 왼쪽 = 현재 방향 - 1 (북 -> 서만 예외처리)
            nd = changeDirection(direction);
            ny = posy + dy[nd];
            nx = posx + dx[nd];
            //새로운 방향에 청소할게 있는지 검사
            //있다면
            //이동 후 청소하고 다시 4방향검사
            if(visit[ny][nx] == 0 && map[ny][nx] == 0){
                posy = ny;
                posx = nx;
                direction = nd;
                sol++;
                visit[posy][posx] = 1;
                chk = true;
                break;
            }
            //없다면
            //방향을 회전하고 다음 왼쪽 방향 검사
            else{
                direction = nd;
            }
        }
        //4방향을 다 청소할수없다면or 벽이라면
        if(!chk){
            //방향 유지하고 후진을 하는데

            ny = posy + dy[goback(direction)];
            nx = posx + dx[goback(direction)];
            //벽이라 할수없다면 작동을 멈춤
            if(map[ny][nx] == 1){
                break;
            }
            else{
                posy = ny;
                posx = nx;
            }

        }
    }

    cout << sol << endl;

    return 0;
}