//
// Created by vkdne on 2018-03-20.
//

#include <iostream>
#include <queue>
using namespace std;
struct xy{
    int x = 0;
    int y = 0;
};
int arr[101][101];
int visit[101][101];
queue<xy> q;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int N,M;
int sol = 10001;
void BFS(int cnt){
    int n = q.size();
    for(int i = 1; i <= n ; i++) {
        xy t = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx == N && ny == M) {
                if (sol > cnt + 1) {
                    sol = cnt + 1;
                    return;
                }
            }
            if (nx > 0 && nx <= N && ny > 0 && ny <= M && arr[nx][ny] == 1 && visit[nx][ny] == 0) {
                visit[nx][ny] = 1;
                xy temp;
                temp.x = nx;
                temp.y = ny;
                q.push(temp);
            }
        }
    }
    BFS(cnt+1);
};

int main(){
    cin >> N >> M;
    char a;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> a;
            if(a == '1')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    visit[1][1] = 1;
    xy t;
    t.x = 1;
    t.y = 1;
    q.push(t);
    BFS(1);
    cout << sol <<endl;
    return 0;
}