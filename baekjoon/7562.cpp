//
// Created by vkdne on 2018-03-27.
//

#include <iostream>
#include <queue>
using namespace std;
int visit[300][300];
int T,L;
int sx,ex,sy,ey;
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
struct xy{
    int x,y,cnt;
};
queue<xy> q;
int sol;
void BFS(){
    while(q.size()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();
        for(int i = 0; i < 8 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx == ex && ny == ey){
                sol = cnt + 1;
                return;
            }
            if(nx >= 0 && nx < L && ny >= 0 && ny < L && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                q.push({nx,ny,cnt+1});
            }

        }

    }
    return;
}

int main(){
    cin >> T;
    while(T--){
        sol = 0;
        while(q.size()){
            q.pop();
        }
        fill_n(&visit[0][0],300*300,0);
        cin >> L >> sx >> sy >> ex >> ey;
        if(sx == ex && sy == ey){
            cout << sol<< endl;
            continue;
        }
        visit[sy][sx] = 1;
        q.push({sx,sy,0});
        BFS();
        cout << sol << endl;
    }
    return 0;
}