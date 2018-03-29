//
// Created by vkdne on 2018-03-29.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 99999999

struct edge{
    int toV;
    int w;
};

struct comp{
    bool operator()(edge a,edge b){
        return a.w > b.w;
    };
};

int N,E;
vector<edge> graph[801];
int sol[801];
void findD(int a){
    fill_n(sol,801,INF);
    sol[a] = 0;
    priority_queue<edge,vector<edge>,comp> q;
    q.push({a,0});
    while(q.size()){
        int v = q.top().toV;
        q.pop();
        for(auto it = graph[v].begin() ; it != graph[v].end() ; it++){
            int nv = (*it).toV;
            int nw = (*it).w;
            if(sol[nv] == INF || sol[nv] > sol[v] + nw){
                sol[nv] = sol[v] + nw;
                q.push({nv,sol[nv]});
            }
        }
    }
}
int main(){
    cin >> N >> E;
    int a,b,c;
    while(E--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int v1,v2;
    cin >> v1 >> v2;
    findD(1);
    int one_v1 = sol[v1];
    int one_v2 = sol[v2];
    findD(N);
    int v1_N = sol[v1];
    int v2_N = sol[v2];
    findD(v1);
    int v1_v2 = sol[v2];

    if(one_v1 == INF || one_v2 == INF || v1_N == INF || v2_N == INF || v1_v2 == INF){
        cout << "-1" << endl;
        return 0;
    }

    int sol1 = one_v1 + v1_v2 + v2_N;
    int sol2 = one_v2 + v1_v2 + v1_N;
    if(sol1 < sol2)
        cout << sol1;
    else
        cout << sol2;
    return 0;
}