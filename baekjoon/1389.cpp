//
// Created by vkdne on 2018-04-06.
//
#include <iostream>
#include <queue>
using namespace std;
int arr[101][101];
int visit[101];
int sol[101];
struct f{
    int v;
    int d;
};
queue<f> q;
int N,M;
void bfs(int a){
    while(!q.empty()){
        f tmp = q.front();
        q.pop();
        sol[a] += tmp.d;
        for(int i = 1 ; i <= N ; i++){
            if(arr[i][tmp.v] == 1 && visit[i] == 0){
                q.push({i,tmp.d+1});
                visit[i] = 1;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    int a,b;
    //그래프 생성
    for(int i = 0 ; i < M ; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i = 1 ; i <= N ; i++){
        visit[i] = 1;
        q.push({i,0});
        bfs(i);
        fill_n(visit,101,0);
    }
    int m = 9999999;
    int idx = -1;
    for(int i = 1; i <= N ; i++){
        if(sol[i] < m){
            m = sol[i];
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}