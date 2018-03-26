//
// Created by vkdne on 2018-03-26.
//
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[50][50];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int T,M,N,K;
int x,y;
int sol;
queue<pair<int,int>> q;
void BFS(){
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        arr[y][x] = 0;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < M && ny >= 0 && ny < N && arr[ny][nx] == 1){
                arr[ny][nx] = 0;
                q.push({ny,nx});
            }
        }
    }
};

int main(){
    cin >> T;
    while(T--){
        fill_n(&arr[0][0],50*50,0);
        sol = 0;
        cin >> M >> N >> K;

        while(K--){
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(arr[i][j] == 1){
                    sol++;
                    arr[i][j] = 0;
                    q.push({i,j});
                    BFS();
                }
            }
        }
        cout << sol << endl;
    }
    return 0;
}