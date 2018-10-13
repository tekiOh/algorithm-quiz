//
// Created by vkdne on 2018-10-13.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char map[50][50];
int visit[50][50];
int dp[50][50];
int N, M;
bool cycle = false;
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct yx {
    int y, x,cnt;
};
queue<yx> q;
bool chk(int y, int x){
    if(x >= 0 && x < M && y >= 0 && y < N)
        return true;
    return false;
}

void dfs(int y, int x){
    int nx,ny;
    for(int i = 0 ; i < 4 ; i++){
        nx = x + dx[i]*(map[y][x]-48);
        ny = y + dy[i]*(map[y][x]-48);
        if(chk(ny,nx)){
            if(map[ny][nx] == 'H'){
                continue;
            }
            //첫방문
            if(!visit[ny][nx]){
                visit[ny][nx] = 1;
                dfs(ny,nx);
                visit[ny][nx] = 0;
            }
            //사이클
            else{
                cycle = true;
                return;
            }
        }
    }
}
int sol(int y,int x){
    int nx,ny;
    if(!chk(y,x) || map[y][x] == 'H')
        return 0;
    int& ret = dp[y][x];
    if(ret) {
        cout <<x <<","<<y<<":"<<ret<<endl;
        return ret;
    }
    for(int i = 0 ; i < 4 ; i++){
        nx = x + dx[i]*(map[y][x]-'0');
        ny = y + dy[i]*(map[y][x]-'0');
        ret = max(ret,1+sol(ny,nx));
    }
    cout <<x <<","<<y<<":"<<ret<<endl;
    return ret;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    visit[0][0] = 1;
    dfs(0,0);
    if(cycle) {
        cout << -1 << endl;
    }
    else{
        cout << sol(0,0) << endl;
    }
    return 0;
}