//
// Created by vkdne on 2018-04-03.
//

#include <iostream>
using namespace std;
int map[21][21];
int order[1001]; // 1 : 동, 2 : 서, 3 : 북, 4 : 남
int dice[5][4];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};

int N,M; //세로,가로
int dicex,dicey; //주사위 위치(y부터 받자)
int K;  //명령 개수

void east(){
    //주사위 모양 변경
    int tmp = dice[4][2];
    dice[4][2] = dice[2][3];
    for(int i = 3 ; i > 1 ; i--)
        dice[2][i] = dice[2][i-1];
    dice[2][1] = tmp;
}

void west(){
    //주사위 모양 변경
    int tmp = dice[4][2];
    dice[4][2] = dice[2][1];
    for(int i = 1 ; i < 3 ; i++)
        dice[2][i] = dice[2][i+1];
    dice[2][3] = tmp;
}

void north(){
    //주사위 모양 변경
    int tmp = dice[1][2];
    for(int i = 1 ; i <= 3 ; i++)
        dice[i][2] = dice[i+1][2];
    dice[4][2] = tmp;
}

void south(){
    //주사위 모양 변경
    int tmp = dice[4][2];
    for(int i = 4 ; i > 1 ; i--)
        dice[i][2] = dice[i-1][2];
    dice[1][2] = tmp;
}
int main(){
    cin >> N >> M >> dicey >> dicex >> K;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            cin >> map[i][j];
    for(int i = 1 ; i <= K ; i++)
        cin >> order[i];

    dicex++;
    dicey++;

    //주사위 위치
    int ndx;
    int ndy;
    for(int i = 1 ; i <= K ; i++){
        ndx = dicex + dx[order[i]];
        ndy = dicey + dy[order[i]];
        //맵 벗어나면 명령 수행X
        if(ndx <= 0 || ndx > M || ndy <= 0 || ndy > N)
            continue;

        dicex += dx[order[i]];
        dicey += dy[order[i]];
        switch(order[i]){
            //동
            case 1 :
                east();
                break;
            //서
            case 2 :
                west();
                break;
            //북
            case 3 :
                north();
                break;
            //남
            default:
                south();
                break;
        }
        //주사위 <-> 맵 복사
        //칸이 0이면 주사위 바닥 숫자를 칸으로
        if(map[dicey][dicex] == 0 ) {
            map[dicey][dicex] = dice[4][2];
        }
            //칸이 0이 아니면 주사위에 칸을 복사하고 칸을 0으로
        else{
            dice[4][2] = map[dicey][dicex];
            map[dicey][dicex] = 0;
        }
        cout << dice[2][2] << endl;
    }

        return 0;
}