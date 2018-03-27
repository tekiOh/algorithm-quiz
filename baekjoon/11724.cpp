//
// Created by vkdne on 2018-03-27.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;
vector<int> graph[1001];
queue<int> q;
int visit[1001];
int cnt;

void BFS(){
    while(q.size()){
        int tmp = q.front();
        q.pop();
        for(auto it = graph[tmp].begin(); it != graph[tmp].end(); it++){
            if(visit[*it] == 0){
                visit[*it] = 1;
                q.push(*it);
            }
        }
    }
}


int main(){
    cin >> N >> M;
    int a,b;
    while(M--){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N ; i++){
        if(visit[i] == 0){
            cnt++;
            visit[i] = 1;
            q.push(i);
            BFS();
        }
    }
    cout << cnt<< endl;
    return 0;
}
