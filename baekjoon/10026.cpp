//
// Created by vkdne on 2018-04-06.
//
#include <iostream>
#include <queue>
using namespace std;

struct xy{
    int x,y;
};

int arr[101][101]; //0 : R, 1 : G, 2 : B
int visit[101][101];
int N;
queue<xy> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs(int color){
    int nx,ny;
    while(!q.empty()){
        xy tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(nx>0 && nx <= N && ny>0 && ny <= N && visit[ny][nx] == 0 && arr[ny][nx] == color){
                visit[ny][nx] = 1;
                q.push({nx,ny});
            }
        }
    }
}

void bfs1(int color){
    int nx,ny;
    while(!q.empty()){
        xy tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(color != 2) {
                if (nx > 0 && nx <= N && ny > 0 && ny <= N && visit[ny][nx] == 0 && arr[ny][nx] != 2) {
                    visit[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }
            else{
                if (nx > 0 && nx <= N && ny > 0 && ny <= N && visit[ny][nx] == 0 && arr[ny][nx] == color) {
                    visit[ny][nx] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}



int main(){
    cin >> N;
    char a;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> a;
            if(a == 'R'){
               arr[i][j] = 0;
            }
            else if(a == 'G'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 2;
            }
        }
    }

    int sol = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            if(visit[i][j] == 0){
                sol++;
                visit[i][j] = 1;
                q.push({j,i});
                bfs(arr[i][j]);
            }
        }
    }
    cout << sol<<" ";

    while(!q.empty())
        q.pop();
    fill_n(&visit[0][0],101*101,0);
    sol = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            if(visit[i][j] == 0){
                sol++;
                visit[i][j] = 1;
                q.push({j,i});
                bfs1(arr[i][j]);
            }
        }
    }
    cout << sol << endl;
    return 0;
}