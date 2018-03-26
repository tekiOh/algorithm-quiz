//
// Created by vkdne on 2018-03-26.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100][100];
int visit[100][100];
int Dx[4] = {0,0,1,-1};
int Dy[4] = {1,-1,0,0};
int M,N,K;
int sx,sy,dx,dy;
vector<int> sol;
queue<pair<int,int>> q;
int cnt;
pair<int,int> tmp;

void BFS(){
    cnt = 0;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + Dx[i];
            int ny = y + Dy[i];
            if(nx >=0 && nx < N && ny >=0 && ny < M && arr[ny][nx] == 0 && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                cnt++;
                q.push({ny,nx});
            }
        }
    }
    sol.push_back(cnt+1);
};

int main(){
    cin >> M >> N >> K;
    while(K--){
        cin >> sx >> sy >> dx >> dy;
        for(int i = sy ; i < dy ; i++ ){
            for(int j = sx ; j < dx ; j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout << endl;
    }


    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(arr[i][j] == 0 && visit[i][j] == 0){
                visit[i][j] = 1;
                q.push({i,j});
                BFS();
            }
        }
    }

    sort(sol.begin(),sol.end());
    cout << sol.size() << endl;
    for(auto it = sol.begin() ; it != sol.end(); it++)
        cout << *it << " ";

    return 0;
}