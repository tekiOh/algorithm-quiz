//
// Created by vkdne on 2018-04-06.
//

#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct xy{
    int x,y;
    int d;
};
queue<xy> q;
int map[51][51];
int visit[51][51];
int sol;
int N,M;

void bfs(){
    int nx,ny;
    while(!q.empty()){
        xy tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(map[ny][nx] == 1 && nx >= 1 && nx <= M && ny >= 1 && ny <= N && visit[ny][nx] ==0){
                visit[ny][nx] = 1;
                q.push({nx,ny,tmp.d+1});
                if(sol < tmp.d+1)
                    sol = tmp.d+1;
            }
        }
    }

}

int main(){
    cin >> N >> M;
    char a;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ;j++){
            cin >> a;
            if(a == 'W')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }

    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= M ; j++){
            if(map[i][j] == 1){
                visit[i][j] = 1;
                q.push({j,i,0});
                bfs();
                fill_n(&visit[0][0],51*51,0);
            }
        }
    }
    cout << sol;
    return 0;
}