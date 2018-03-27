//
// Created by vkdne on 2018-03-27.
//

#include <iostream>
using namespace std;

char arr[21][21];
int visit[21][21];
int alph[26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int R,C;
int sol = -1;
void DFS(int a, int b,int c){
    int nx,ny;
    for(int i = 0 ; i < 4 ; i++){
        nx = a + dx[i];
        ny = b + dy[i];
        if(nx >= 1 && nx <= C && ny >= 1 && ny <= R && visit[ny][nx] == 0 && alph[(int)arr[ny][nx]-65] == 0){
            visit[ny][nx] = 1;
            alph[(int)arr[ny][nx]-65] = 1;
            DFS(nx,ny,c+1);
            visit[ny][nx] = 0;
            alph[(int)arr[ny][nx]-65] = 0;
        }
    }
    if(sol < c)
        sol = c;
    return;
}

int main(){
    cin >> R >> C;

    for(int i = 1 ; i <= R ; i++){
        for(int j = 1 ; j <= C ; j++){
            cin >>arr[i][j];
        }
    }
    visit[1][1] = 1;
    alph[(int)arr[1][1]-65] = 1;
    DFS(1,1,1);

    cout << sol << endl;


    return 0;
}