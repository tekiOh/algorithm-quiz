//
// Created by vkdne on 2018-10-14.
//

#include <iostream>

using namespace std;
int T, N;
int sol = -1;
int map[20][20];
int visitStore[20][20];
int visitDesert[101];
//int visitRoad[20][20][20][20];
//상우,상좌,하좌,하우 >> 순으로 순회할것!
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
int sx, sy;

bool chkPoint(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < N)
        return true;
    return false;

}

bool chkVisit(int sy, int sx, int y, int x) {
    if (!visitStore[y][x] && !visitDesert[map[y][x]])
        return true;
    return false;
}

void travel(int y, int x, int a, int b) {
//    cout << "start from " << x << "," << y << endl;
//    cout << a << "," << b << endl;
    int nx, ny;
    int k;
    bool ch = true;
    for (int i = 0; i < 4 && ch; i++) {
        if (i % 2 == 0) k = a;
        else k = b;
        for (int j = 1; j <= k && ch; j++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (chkPoint(ny, nx) && chkVisit(y, x, ny, nx)) {
                visitStore[ny][nx] = 1;
                visitDesert[map[ny][nx]] = 1;
                x = nx;
                y = ny;
                //cout << x << "," << y << endl;
            } else {
                //cout << "error!! break!!" << endl;
                ch = false;
                break;
            }
        }
    }
    x = sx;
    y = sy;
    //cout <<"clean start from" <<x<<","<<y<<endl;
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) k = a;
        else k = b;
        for (int j = 1; j <= k; j++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (chkPoint(ny, nx)) {
                visitStore[ny][nx] = 0;
                visitDesert[map[ny][nx]] = 0;
                //cout << nx << "," << ny << " cleaned!!" << endl;
                x = nx;
                y = ny;
            }
        }
    }
    if (ch) {
        if (sol < 2 * (a + b))
            sol = 2 * (a + b);
        //cout << "sol : " << sol << endl;
    }
}

void simulation() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            for (int a = 1; a < N - x; a++) {
                for (int b = 1; b < N - y - a; b++) {
                    if (x - b >= 0 && x + a - b >= 0 && x + a - b < N && y + a < N) {
                        //cout << c++ << "th start!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                        sy = y;
                        sx = x;
                        travel(y, x, a, b);
                    }
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            visitStore[i][j] = 0;
    }
    for (int i = 1; i < 101; i++)
        visitDesert[i] = 0;
    sol = -1;
}

int main() {
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];

        simulation();
        cout << "#" << a++ << " " << sol << endl;
        init();
    }
    return 0;
}