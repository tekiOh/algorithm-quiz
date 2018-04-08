//
// Created by vkdne on 2018-04-07.
//
#include <iostream>
#include <queue>
using namespace std;
int N,M;
int map[1001][1001];
int visit[1001][1001][2];
struct xy{
    int x,y,c,d;
};
queue<xy> q;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int sol = 999999999;
void bfs(){
    visit[1][1][0] = 1;
    visit[1][1][1] = 1;
    q.push({1,1,0,0});
    int nx,ny;
    while(!q.empty()){
        xy tmp = q.front();
        //cout <<tmp.x <<" "<< tmp.y << " "<< tmp.c << " " << tmp.d << endl;
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(ny == N && nx == M){
                if(sol > tmp.d+1)
                    sol = tmp.d+1;
            }

            if(nx > 0 && nx <= M && ny > 0 && ny <= N && ((visit[ny][nx][0] == 0 && tmp.c == 0)||(visit[ny][nx][1] == 0 && tmp.c == 1))){
                // /벽이 있다면
                if(map[ny][nx] == 1){
                    //그전에 벽을 부신적이 없다면
                    if(tmp.c == 0){
                        visit[ny][nx][0] = 1;
                        q.push({nx,ny,1,tmp.d+1});
                    }
                }
                //벽이 없다면
                else{
                    if(tmp.c == 0) {
                        visit[ny][nx][0] = 1;
                    } else
                        visit[ny][nx][1] = 1;
                    q.push({nx,ny,tmp.c,tmp.d+1});
                }
            }
        }
    }
}
int main() {
    cin >> N >> M;
    char a;
    for(int i = 1 ; i <= N ; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a;
            if(a == '1')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }
    if(N==1 && M==1){
        cout << 1 << endl;
        return 0;
    }
    bfs();
    if(sol == 999999999)
        cout << -1 << endl;
    else
        cout << sol+1 << endl;
    return 0;
}