//
// Created by vkdne on 2018-10-27.
//

#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;
int map[11][11];         //맵
int road[11][11][11][11]; //from_y,from_x, to_y, to_x
int answer = 0;
string dirs = "LULLLLLLU";
//U(y++),D(y--),R(x++),L(x--)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void markRoad(int sy, int sx, int ny, int nx) {
    road[sy][sx][ny][nx] = 1;
    road[ny][nx][sy][sx] = 1;
}

bool chkRoad(int sy, int sx, int ny, int nx) {
    if (!road[sy][sx][ny][nx] && !road[ny][nx][sy][sx]) {
        return true;
    }
    return false;
}

bool chkBound(int y, int x) {
    if (x >= 0 && x < 11 && y >= 0 && y < 11)
        return true;
    return false;
}

int main() {
    //시작점
    int sx = 5;
    int sy = 5;
    int nx, ny;
    int d;
    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U') d = 0;
        else if (dirs[i] == 'D') d = 1;
        else if (dirs[i] == 'R') d = 2;
        else d = 3;
        nx = sx + dx[d];
        ny = sy + dy[d];
        if (chkBound(ny, nx)) {
            if (chkRoad(sy, sx, ny, nx)) {
                answer++;
                markRoad(sy, sx, ny, nx);
            }
            sx = nx;
            sy = ny;
        }
    }
    cout << answer << endl;
}