//
// Created by vkdne on 2018-10-19.
//
#include <iostream>
#include <queue>

using namespace std;

int N, K, L;
//뱀지도 : 1 -> 사과, 2 -> 뱀
int map[101][101];
//방향지도
int direction[101][101];
//4방향 : 상우하좌
int dx[5] = {0,0, 1, 0, -1};
int dy[5] = {0,-1, 0, 1, 0};
queue<pair<int, char>> q;

void printMap(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cout << map[i][j]<<" ";
        }
        cout << endl;
    }
    cout <<"********************************"<<endl;
}
int chkHead(int y, int x) {
    if (y >= 1 && y <= N && x >= 1 && x <= N) {
        //사과를 만남
        if (map[y][x] == 1) {
            return 1;
        }
            //몸을 만남
        else if (map[y][x] == 2) {
            return 2;
        }
            //빈 공간
        else {
            return 3;
        }
    }
    return 0;
}
int chgDirection(char d,int cd){
    if(d == 'L'){
        if(cd == 1)
            return 4;
        else
            return cd-1;
    }
    else{
        if(cd == 4)
            return 1;
        else
            return cd+1;
    }
}
void simulation() {
    int hy, hx, ty, tx;    //머리, 꼬리 위치
    int hd, td;          //머리, 꼬리 방향
    hx = 1;
    hy = 1;
    tx = 1;
    ty = 1;
    hd = 2;
    td = 2;
    map[1][1] = 2;
    int nhx, nhy;
    int t = 0;
    //게임이 끝날때까지 반복
    while (1) {
//        cout <<t+1<<"seconds later"<<endl;
        if (q.front().first == t){
//            cout <<"change head direction!!"<<endl;
//            cout << hy<<","<<hx<<endl;
            hd = chgDirection(q.front().second,hd);
            direction[hy][hx] = hd;
            q.pop();
        }
        if(direction[ty][tx]){
//            cout <<"change tail direction!!"<<endl;
            td = direction[ty][tx];
            direction[ty][tx] = 0;
        }
        t++;
        nhy = hy + dy[hd];
        nhx = hx + dx[hd];
        int headStatus = chkHead(nhy, nhx);
        //out of bound -> break;
        if (headStatus == 0) {
//            cout <<"out of bound!!!"<<endl;
            break;
        }
            //사과 -> 머리만 움직인다
        else if (headStatus == 1) {
//            cout <<"apple!!!"<<endl;
            hy = nhy;
            hx = nhx;
            map[hy][hx] = 2;
        }
            //몸
        else if (headStatus == 2) {
//            cout <<"crash body!!!"<<endl;
            break;
        }
            //그냥 빈공간 -> 머리 움직이고, 꼬리도 움직이고
        else {
//            cout << "simple move!!"<<endl;
            hy = nhy;
            hx = nhx;
            map[hy][hx] = 2;
            map[ty][tx] = 0;
            ty += dy[td];
            tx += dx[td];
            map[ty][tx] = 2;
        }
//        printMap();
    }
    cout << t<< endl;
}

int main() {
    cin >> N >> K;
    pair<int, int> tmp;
    int y, x;
    for (int i = 0; i < K; i++) {
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> L;
    int t;
    char d;
    for (int i = 0; i < L; i++) {
        cin >> t >> d;
        q.push({t, d});
    }
    simulation();
    return 0;
}
