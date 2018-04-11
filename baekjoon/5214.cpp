//
// Created by vkdne on 2018-04-10.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[101002];
int visit[101002];
struct xx{
    int n,c;
};
queue<xx> q;
int N,M,K;
int sol = -1;
void bfs(){
    q.push({1,1});
    visit[1] = 1;
    xx front;
    while(!q.empty()){
        front  = q.front();
        q.pop();
        for(auto a : v[front.n]){
            if(a == N){
                sol = front.c + 1;
                return;
            }
            if(visit[a] == 0){
                visit[a] = 1;
                if(a>N)
                    q.push({a,front.c});
                else
                    q.push({a, front.c + 1});

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> K >> M;

    //int a,b,c;
    //그래프 생성
    int t = N+1;
    int a;
    while(M--){
        for(int i = 1; i <= K ; i++) {
            cin >> a;
            v[t].push_back(a);
            v[a].push_back(t);
        }
        t++;
    }
    //계산
    bfs();
    cout << sol << endl;
    return 0;
}