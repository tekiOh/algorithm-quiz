//
// Created by vkdne on 2018-03-16.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int arr[1001][1001];
int M,N;

struct xy{
    int x;
    int y;
};

queue<xy> q;

void BFS(int cnt){
    int t = q.size();
    xy tmp;
    xy tmp1;
    while(t--){
        tmp = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++){
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            if(x >= 1 && x <= N && y >= 1 && y <= M){
                if(arr[x][y] == 0){
                    arr[x][y] = 1;
                    tmp1.x = x;
                    tmp1.y = y;
                    q.push(tmp1);
                }
            }
        }
    }

    if(q.empty()){
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= M ; j++){
                if(arr[i][j] == 0){
                    cout <<"-1"<<endl;
                    return;
                }
            }
        }
        cout << cnt << endl;
        return;
    }
    BFS(cnt+1);
};


int main(){
    xy tmp;
    cin >> M >> N;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                tmp.x = i;
                tmp.y = j;
                q.push(tmp);
            }
        }
    }
    BFS(0);
    return 0;
}
