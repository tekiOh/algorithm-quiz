//
// Created by vkdne on 2018-03-27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T,V,E;
int visit[20001];
vector<int> arr[20001];


void DFS(int a,bool check){
    for(auto it = arr[a].begin(); it != arr[a].end(); it++){
        if(visit[*it] == 0){
            if(check)
                visit[*it] = 1;
            else
                visit[*it] = 2;

            DFS(*it,!check);
        }
    }
}


int main(){
    cin >> T;
    int a,b;
    while(T--) {
        fill_n(visit, 20001, 0);
        for (int i = 1; i <= V; i++)
            arr[i].clear();
        cin >> V >> E;
        while (E--) {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        bool check = true;
        for (int i = 1; i <= V; i++) {
            if (visit[i] == 0) {
                visit[i] = 1;
                DFS(i,!check);
            }
        }
        bool sol = true;
        for (int i = 1; i <= V; i++){
            for(auto it = arr[i].begin(); it != arr[i].end(); it++){
                if(visit[i] == visit[*it]){
                    sol = false;
                }
            }
        }

        if(sol)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}