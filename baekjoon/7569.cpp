//
// Created by vkdne on 2018-03-20.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
int arr[101][101][101];
int M,N,H;

struct xy{
    int x;
    int y;
    int z;
};

queue<xy> q;

void BFS(int cnt){
    int t = q.size();
    xy tmp;
    xy tmp1;
    while(t--){
        tmp = q.front();
        q.pop();
        for(int i = 0; i <= 5; i++){
            int x = tmp.x + dx[i];  //가로
            int y = tmp.y + dy[i];  //세로
            int z = tmp.z + dz[i];  //높이
            if(x >= 1 && x <= M && y >= 1 && y <= N && z >= 1 && z <= H){
                if(arr[z][y][x] == 0){
                    arr[z][y][x] = 1;
                    tmp1.x = x;
                    tmp1.y = y;
                    tmp1.z = z;
                    q.push(tmp1);
                }
            }
        }
    }

    if(q.empty()){
        for(int i = 1; i <= H ; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= M; k++) {
                    if (arr[i][j][k] == 0) {
                        cout << "-1" << endl;
                        return;
                    }
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
    cin >> M >> N >> H;
    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= N ; j++){
            for(int k =1 ; k <= M ; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    tmp.x = k;  //가로
                    tmp.y = j;  //세로
                    tmp.z = i;  //높이
                    q.push(tmp);
                }
            }
        }
    }
    BFS(0);
    return 0;
}
