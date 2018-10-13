//
// Created by vkdne on 2018-10-13.
//

#include<iostream>
#include<string>

using namespace std;

int map[8][8];
int N;
string command[50];

//R(x++),L(x--),B(y--),T(y++),RT,LT,RB,LB
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};

bool chk(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
    return false;
}

int main() {
    //A = 65
    //1 = 49
    string king;
    string stone;
    cin >> king >> stone >> N;
    for (int i = 0; i < N; i++) {
        cin >> command[i];
    }
    //킹,스톤 표시
    int kx = king[0] - 65;
    int ky = king[1] - 49;
    int sx = stone[0] - 65;
    int sy = stone[1] - 49;
    map[king[1] - 49][king[0] - 65] = 1;
    map[stone[1] - 49][stone[0] - 65] = 2;
    int nx, ny;
    int d = 0;

    for (int i = 0; i < N; i++) {
        if (command[i] == "R") d = 0;
        else if (command[i] == "L") d = 1;
        else if (command[i] == "B") d = 2;
        else if (command[i] == "T") d = 3;
        else if (command[i] == "RT") d = 4;
        else if (command[i] == "LT") d = 5;
        else if (command[i] == "RB") d = 6;
        else d = 7;

        nx = kx + dx[d];
        ny = ky + dy[d];

        if (chk(nx, ny)) {
            //킹이 움직인 위치에 돌이 있으면
            if(map[ny][nx] == 2){
                int nsx,nsy;
                nsx = sx + dx[d];
                nsy = sy + dy[d];
                //돌도 유효한 위치로 움직이게 되면
                if(chk(nsx,nsy)){
                    map[ky][kx] = 0;
                    map[ny][nx] = 1;
                    map[nsy][nsx] = 2;
                    kx = nx;
                    ky = ny;
                    sx = nsx;
                    sy = nsy;
                }
            }
            else{
                map[ky][kx] = 0;
                map[ny][nx] = 1;
                kx = nx;
                ky = ny;
            }
        }
//        cout <<"**************************"<<endl;
//        for(int j = 0 ; j < 8 ; j++){
//            for(int k = 0 ; k < 8 ; k++){
//                cout << map[j][k];
//            }
//            cout << endl;
//        }
    }
    cout <<(char)(kx+65)<<ky+1<<endl;
    cout <<(char)(sx+65)<<sy+1<<endl;
    return 0;
}