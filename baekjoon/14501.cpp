//
// Created by vkdne on 2018-04-03.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[16][2]; // 0 : 시간 1 : 이득
int sol;
int N;
struct counsil{
    int profit;
    int possible;
};
queue<counsil> q;

void bfs(){
    while(q.size()){
        counsil tmp = q.front();
        if(sol < tmp.profit)
            sol = tmp.profit;
        q.pop();
        for(int i = tmp.possible ; i <= N ; i++){
            counsil next;
            next.profit = tmp.profit + arr[i][1];
            next.possible = i + arr[i][0];
            if(next.possible <= N+1)
                q.push(next);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 1 ; i <= N ; i++) {
        if(i+arr[i][0] <= N+1) {
            q.push({arr[i][1], i + arr[i][0]});
            bfs();
        }
    }
    cout << sol << endl;
    return 0;
}