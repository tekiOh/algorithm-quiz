//
// Created by vkdne on 2018-03-26.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 999999999

vector<pair<int,int>> graph[20001]; // to, weight
int sol[20001];
int V,E;
struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void FindD(int i){
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;
    q.push({i,0});
    cout <<i<<"into q"<<endl;
    while(q.size()){
        int v = q.top().first;
        q.pop();
        for(auto it = graph[v].begin() ; it != graph[v].end() ; it++){
            int nv = (*it).first;
            int nw = (*it).second;
            if(sol[nv] == INF){
                sol[nv] = sol[v] + nw;
                q.push({nv,sol[nv]});
                cout <<nv << "into q"<<endl;
            }
            else{
                if(sol[nv] > sol[v] + nw) {
                    sol[nv] = sol[v] + nw;
                    q.push({nv,sol[nv]});
                    cout <<nv << "into q"<<endl;
                }
            }
        }
    }
}

int main(){
    int s;
    cin >> V >> E >> s;
    int u,v,w;


    //그래프 생성
    for(int i = 1 ; i <= E ; i++) {
        cin >> u >> v >> w;
        int chk = true;
        for(auto it = graph[u].begin(); it != graph[u].end(); it++){
            if((*it).first == v){
                chk = false;
                if((*it).second > w) {
                    (*it).second = w;
                }
            }
        }
        if(chk)
            graph[u].emplace_back(make_pair(v,w));
    }


    for(int i = 1; i <= V ; i++)
        sol[i] = INF;
    sol[s] = 0;
    //다익스트라
    FindD(s);

    for(int i = 1 ; i <= V ; i++) {
        if (sol[i] == INF)
            cout << "INF" << '\n';
        else
            cout << sol[i] << '\n';
    }
    return 0;
}