//
// Created by vkdne on 2018-09-21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;  //보드의 크기
int K;  //사과의 개수
int L;  //방향 변환 횟수
int map[101][101];  // 1 : 사과, 2 : 뱀
char dmap[101][101];//꼬리 방향 변경 지점 체크
int t = 0;  //시간
//하(y--)우(x++)상(y++)좌(x--)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int curhdir = 1;
int curtdir = 1;
queue<pair<int, char>> change;

bool chkPoint(int x, int y) {
    if (x > 0 && x <= N && y > 0 && y <= N && map[y][x] != 2)
        return true;
    return false;
}


void move() {
    int hx, hy, tx, ty;
    hx = hy = tx = ty = 1;
    int ntx, nty, nhx, nhy;
    map[1][1] = 2;
    while (1) {
        //머리 방향 변경
        if (change.front().first == t) {
            if (change.front().second == 'D') {
                if (curhdir != 3) curhdir++;
                else curhdir = 0;
            } else {
                if (curhdir != 0) curhdir--;
                else curhdir = 3;
            }
            dmap[hy][hx] = change.front().second;
            change.pop();
        }
        //꼬리 방향 변경
        if(dmap[ty][tx] == 'L'){
            if (curtdir != 0) curtdir--;
            else curtdir = 3;
            dmap[ty][tx] = 'X';
        }
        if(dmap[ty][tx] == 'D'){
            if (curtdir != 3) curtdir++;
            else curtdir = 0;
            dmap[ty][tx] = 'X';
        }
        //바꾸고 이동시작
        nhx = hx + dx[curhdir];
        nhy = hy + dy[curhdir];
        ntx = tx + dx[curtdir];
        nty = ty + dy[curtdir];

        //유효한 범위면 이동
        if (chkPoint(nhx, nhy)) {
            //사과가 있으면 head만 증가
            if(map[nhy][nhx] == 1){
                map[nhy][nhx] = 2;
                hx = nhx;
                hy = nhy;
            }
            //없으면 tail도 증가
            else{
                map[nhy][nhx] = 2;
                map[ty][tx] = 0;
                hx = nhx;
                hy = nhy;
                tx = ntx;
                ty = nty;
            }
        } else {
            t++;
            break;
        }
        t++;
    }
}


int main() {
    cin >> N >> K;
    int y, x;
    for (int i = 0; i < K; i++) {
        cin >> y >> x;
        map[y][x] = 1;
    }
    char a;
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> y >> a;
        change.push(make_pair(y, a));
    }

    move();
    cout << t << endl;
    return 0;
}
