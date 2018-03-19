//
// Created by vkdne on 2018-03-20.
//

#include <iostream>
#include <queue>
using namespace std;
int N;
int arr[101][101];
int visit[101];
int cnt = 0;
queue <int> q;

void BFS(){
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = 1; i <= N ; i++){
            if(arr[i][t] == 1 && visit[i] == 0){
                cnt++;
                visit[i] = 1;
                q.push(i);
            }
        }
    }
};

int main(){
    cin >> N;
    int M;
    cin >> M;
    int a,b;
    for(int i = 1 ; i <= M  ; i++){
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    visit[1] = 1;
    q.push(1);
    BFS();
    cout << cnt << endl;
    return 0;
}