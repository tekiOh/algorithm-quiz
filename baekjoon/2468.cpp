//
// Created by vkdne on 2018-03-27.
//

#include <iostream>
#include <queue>
#include <set>
using namespace std;

int arr[101][101];
int visit[101][101];
struct xy{
    int x,y;
};
queue<xy> q;
set<int> s;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N;
int sol = -1;
int cnt;
void BFS(int a){
    while(q.size()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= N && visit[nx][ny] == 0 && arr[nx][ny] >= a){
                visit[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }
    }

    for(auto it = s.begin(); it != s.end(); it++){
        fill_n(&visit[0][0],101*101,0);
        cnt = 0;
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                if(visit[i][j] == 0 && arr[i][j] >= *it){
                    cnt++;
                    visit[i][j] = 1;
                    q.push({i,j});
                    BFS(*it);
                }
            }
        }
        if(cnt > sol)
            sol = cnt;
    }

    cout << sol << endl;

    return 0;
}