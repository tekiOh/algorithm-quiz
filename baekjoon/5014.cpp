//
// Created by vkdne on 2018-04-06.
//

#include <iostream>
#include <queue>
using namespace std;
struct f{
    int floor,d;
};
queue<f>q;
int visit[1000001];
int sol = -1;
int F,S,G,U,D;
void bfs(){
    while(!q.empty()){
        f tmp = q.front();
        q.pop();
        int u = tmp.floor + U;
        int d = tmp.floor - D;
        if(u == G){
            sol = tmp.d +1;
            return;
        }
        if(d == G){
            sol = tmp.d +1;
            return;
        }
        if(u <= F && visit[u] == 0){
            visit[u] = 1;
            q.push({u,tmp.d+1});
        }
        if(d >=1  && visit[d] == 0){
            visit[d] = 1;
            q.push({d,tmp.d+1});
        }
    }
}

int main(){
    cin >> F >> S >> G >> U >> D;
    if(S==G){
        cout <<0<<endl;
        return 0;
    }
    visit[S] = 1;

    q.push({S,0});
    bfs();
    if(sol == -1){
        cout << "use the stairs" << endl;
    }
    else
        cout << sol << endl;
    return 0;
}