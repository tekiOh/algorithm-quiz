//
// Created by vkdne on 2018-09-21.
//

#include <iostream>
#include <queue>
using namespace std;

int N,M,sx,sy,K;
int dice[4][3]; //동 : [1][2] , 서 : [1][0] , 남 : [2][1] , 북 : [0][1] , 위 : [1][1] , 아래 [3][1]
int map[20][20];//(y,x)
queue<int> q;
//동(x++),서(x--),북(y--),남(y++)
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};
void east(){
    int tmp = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = tmp;
}

void west(){
    int tmp = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = dice[3][1];
    dice[3][1] = dice[1][0];
    dice[1][0] = tmp;
}

void north(){
    int tmp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp;
}

void south(){
    int tmp = dice[0][1];
    dice[0][1] = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = tmp;
}
void move(){
    int command;
    int ny,nx;
    while(!q.empty()){
        command = q.front();
        q.pop();
        ny = sy+dy[command];
        nx = sx+dx[command];
        if(ny >= 0 && ny < N && nx >= 0 && nx < M){
            switch(command){
                case 1:
                    east();
                    break;
                case 2:
                    west();
                    break;
                case 3:
                    north();
                    break;
                case 4:
                    south();
                    break;
            }
            sx = nx;
            sy = ny;
            if(map[ny][nx]){
                dice[3][1] = map[ny][nx];
                map[ny][nx] = 0;
            }
            else
                map[ny][nx] = dice[3][1];
            cout << dice[1][1] << '\n';
        }
        //cout << ny <<","<<nx << endl;
    }
}
int main(){
    cin >> N >> M >> sy >> sx >> K;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin >> map[i][j];
    int c;
    for(int i = 0 ; i < K ; i++){
        cin >> c;
        q.push(c);
    }
    move();
    return 0;
}