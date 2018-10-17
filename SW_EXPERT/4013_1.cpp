//
// Created by vkdne on 2018-10-17.
//

#include <iostream>

using namespace std;

int magnet[5][8];
int visit[5];
int direction[5];
int T, K,sol;

void setDirection(int num, int d) {
    visit[num] = 1;
    direction[num] = d;
    //왼쪽
    if (num != 1) {
        //방문 가능할 때!
        if (!visit[num - 1]) {
            //자성이 다를때 반대방향으로
            if (magnet[num][6] != magnet[num - 1][2]) {
                setDirection(num-1,d*(-1));
            }
        }
    }
    //오른쪽
    if (num != 4) {
        //방문 가능할 때!
        if (!visit[num + 1]) {
            //자성이 다를때 반대방향으로
            if (magnet[num][2] != magnet[num + 1][6]) {
                setDirection(num+1,d*(-1));
            }
        }
    }
}
void rotate(){
    int tmp;
    for(int i = 1; i < 5 ; i++){
        if(direction[i] == 1){
            tmp = magnet[i][7];
            for(int j = 6 ; j > -1 ; j--){
                magnet[i][j+1] = magnet[i][j];
            }
            magnet[i][0] = tmp;
        }
        else if(direction[i] == -1){
            tmp = magnet[i][0];
            for(int j = 0 ; j < 7 ; j++){
                magnet[i][j] = magnet[i][j+1];
            }
            magnet[i][7] = tmp;
        }
    }
}
void init(){
    for(int i = 1 ; i < 5 ; i++) {
        visit[i] = 0;
        direction[i] = 0;
    }
}
void calc(){
    int a = 1;
    for(int i = 1; i < 5 ; i++){
        sol += magnet[i][0]*a;
        a *= 2;
    }
}
int main() {
    cin >> T;
    int a = 1;
    int magnetNum, d;
    while (T--) {
        cin >> K;
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++)
                cin >> magnet[i][j];
        }
        while (K--) {
            cin >> magnetNum >> d;
            setDirection(magnetNum, d);
            rotate();
            init();
        }
        calc();
        cout << "#"<<a++<<" "<<sol << endl;
        sol = 0;
    }

    return 0;
}