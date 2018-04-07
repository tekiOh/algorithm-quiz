//
// Created by vkdne on 2018-04-06.
//

#include <iostream>
#include <queue>
using namespace std;
char map[51][51];
int waterTime[51][51];
int visit[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int R,C;
int sol = -1;
struct xy{
    int y,x,t;
};
queue<xy> q;
void calcTime(){
    int nx,ny;
    while (!q.empty()) {
        xy tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if (nx > 0 && nx <= C && ny > 0 && ny <= R && map[ny][nx] != 'X' && map[ny][nx] != 'D' && visit[ny][nx] == 0) {
                visit[ny][nx] = 1;
                waterTime[ny][nx] = tmp.t + 1;
                q.push({ny, nx, tmp.t + 1});
            }
        }
    }
}

void bfs(int y, int x){
    int ny,nx;
    visit[y][x] = 1;
    q.push({y,x,0});
    while(!q.empty()){
        xy tmp = q.front();
        q.pop();
        for(int i  = 0 ; i < 4 ; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(map[ny][nx] == 'D'){
                sol = tmp.t + 1;
                return;
            }
            if(nx >0 && nx <= C && ny >0 && ny <= R && map[ny][nx] != 'X' && map[ny][nx] != '*' && visit[ny][nx] == 0 && waterTime[ny][nx] > tmp.t+1){
                visit[ny][nx] = 1;
                q.push({ny,nx,tmp.t+1});
            }
        }
    }
}

int main(){
    fill_n(&waterTime[0][0],51*51,99999999);
    cin >> R >> C;
    int wx = -1;
    int wy = -1;
    int x,y;
    for(int i = 1 ; i <= R ; i++) {
        for (int j = 1; j <= C; j++){
            cin >> map[i][j];
            if(map[i][j] == '*'){
                q.push({i,j,0});
            }
            if(map[i][j] == 'S'){
                y = i;
                x = j;
            }
        }
    }

    calcTime();
    fill_n(&visit[0][0],51*51,0);
    bfs(y,x);
    if(sol == -1)
        cout << "KAKTUS"<<endl;
    else
        cout << sol << endl;
    return 0;
}