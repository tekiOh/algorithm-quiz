//
// Created by vkdne on 2018-04-06.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int visit[101];
struct chon{
    int v,d;
};
queue<chon> q;
int sol = -1;
int N;
int s,e;

void bfs(){
    q.push({s,0});
    visit[s] = 1;
    while(!q.empty()){
        chon tmp = q.front();
        q.pop();
        for(int i = 1 ; i <= N ; i++){
            if(arr[i][tmp.v] == 1 && visit[i] == 0){
                if(i == e){
                    sol = tmp.d + 1;
                    return;
                }
                visit[i] = 1;
                q.push({i,tmp.d+1});
            }
        }
    }
}

int main(){
    cin >> N >> s >> e;
    int m;
    cin >> m;
    int a,b;
    while(m--){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    bfs();
    cout << sol << endl;
    return 0;
}