//
// Created by vkdne on 2018-03-20.
//
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[26][26];
int visit[26][26];
int sol[626];
int cnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
void DFS(int x, int y){
    int nx,ny;
    for(int i = 0 ; i <= 3 ; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx > 0 && nx <= N && ny > 0 && ny <= N && visit[nx][ny] == 0 && arr[nx][ny] == 1){
            sol[cnt]++;
            visit[nx][ny] = 1;
            DFS(nx,ny);
        }
    }
};

int main(){
    cin >> N;
    char a;
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++) {
            cin >> a;
            if(a == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
    for(int i = 1; i <= N ; i++) {
        for (int j = 1; j <= N; j++) {
            if(visit[i][j] == 0 && arr[i][j] == 1){
                cnt++;
                visit[i][j] = 1;
                sol[cnt]++;
                DFS(i,j);
            }
        }
    }
    if(cnt)
        sort(&sol[1],&sol[cnt+1]);

    cout << cnt <<endl;
    for(int i = 1; i <= cnt ; i++)
        cout << sol[i] << endl;

    return 0;
}
