//
// Created by vkdne on 2018-10-10.
//

#include <iostream>
#include <vector>

using namespace std;

int map[100][100];  //지도
//상하좌우
//[현재방향][블록넘버] = 다음방향
int direction[4][6] = {{-1, 3, 1, 1, 2, 1},
                       {-1, 0, 3, 2, 0, 0},
                       {-1, 1, 0, 3, 3, 3},
                       {-1, 2, 2, 0, 1, 2}};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> warmhole[5];
int N;
int sol;

bool chkPoint(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N)
        return true;
    return false;
}

void move(int y, int x, int d) {
    int tx = x;
    int ty = y;
    int td = d;
    int nx, ny;
    int cnt = 0;
//    cout << "**************************************" << endl;
//    cout << "start from " << x << "," << y << "," << d << endl;
    //게임끝날때까지 이동
    while (1) {
        //방향안바뀌고 이동할수있을때까지 이동
        nx = x + dx[d];
        ny = y + dy[d];
        //out of bound chk
        if (!chkPoint(nx, ny)) {
            if (d == 0)
                d = 1;
            else if (d == 1)
                d = 0;
            else if (d == 2)
                d = 3;
            else
                d = 2;
            cnt++;
            nx = x;
            ny = y;
        }
        x = nx;
        y = ny;

        if (x == tx && y == ty)
            break;

        if (map[ny][nx] == 0) {
            continue;
        }
        //블록일때
        else if (map[ny][nx] > 0 && map[ny][nx] < 6) {
            //새로운방향
            d = direction[d][map[ny][nx]];
            cnt++;
//                cout << "block crash" << endl;
//                cout << nx << "," << ny << "," << d << endl;
        }
        //웜홀일 때
        else if (map[ny][nx] > 5 && map[ny][nx] < 11) {
            if (nx == warmhole[map[ny][nx] - 6][0].second && ny == warmhole[map[ny][nx] - 6][0].first) {
                x = warmhole[map[ny][nx] - 6][1].second;
                y = warmhole[map[ny][nx] - 6][1].first;
            } else {
                x = warmhole[map[ny][nx] - 6][0].second;
                y = warmhole[map[ny][nx] - 6][0].first;
            }
//                cout << "warmhole crash" << endl;
//                cout << nx << "," << ny << "," << d << endl;
        }
        //블랙홀일때
        else {
            break;
        }
    }
//    cout << "cnt : " << cnt << endl;
    if (sol < cnt)
        sol = cnt;
}

void simulation() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    move(i, j, k);
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (map[i][j] > 5 && map[i][j] < 11) {
                    warmhole[map[i][j] - 6].emplace_back(make_pair(i, j));
                    continue;
                }
            }
        }
        simulation();
        cout << "#" << a << " " << sol << endl;
        sol = 0;
        a++;
        for (int i = 0; i < 5; i++) {
            warmhole[i].clear();
        }

    }
}