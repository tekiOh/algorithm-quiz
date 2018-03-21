//
// Created by vkdne on 2018-03-21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> arr[10001];
int N,M;
int sol[10001];
int visit[10001];
queue<int> q;
int maxv;
void count(int i){
    visit[i] = 1;
    for(auto it = arr[i].begin() ; it != arr[i].end() ; it++){
        q.push(*it);
        visit[*it] = 1;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        sol[i]++;
        for(auto it = arr[t].begin() ; it != arr[t].end() ; it++){
            if(visit[*it] == 0) {
                visit[*it] = 1;
                q.push(*it);
            }
        }
    }
    if(maxv < sol[i])
        maxv = sol[i];
    return;
};

int main(){
    cin >> N >> M;
    int A,B;
    while(M--){
        cin >> A >> B;
        arr[B].push_back(A);
    }
    for(int i = 1; i <= N ; i++ ){
        count(i);
        fill_n(visit+1,N,0);
    }

    for(int i = 1; i <= N ; i++){
        if(sol[i] == maxv)
            cout<<i<<" ";
    }

        return 0;
}