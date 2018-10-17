//
// Created by vkdne on 2018-10-17.
//
#include <iostream>
#include <vector>

using namespace std;

int T, N, sol;
int map[100][100];//1~5 블록, 6~10 웜홀, -1 블랙홀
vector<pair<int, int>> warmhole[5];
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
//[block][현재방향] = 다음방향
int direction[6][4] = {{},
                       {3, 0, 1, 2},
                       {1, 3, 0, 2},
                       {1, 2, 3, 0},
                       {2, 0, 3, 1},
                       {1, 0, 3, 2}};

bool chkPoint(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < N)
        return true;
    return false;
}

void move(int y, int x, int d) {
    int sx, sy, nx, ny, nd, cnt;
    sx = x;
    sy = y;
    cnt = 0;
    nd = d;
    while (1) {
        nx = x + dx[d];
        ny = y + dy[d];
        x = nx;
        y = ny;
        //in bound
        if (chkPoint(ny, nx)) {
            //빈공간이면 다음 이동
            if (map[ny][nx] == 0) {
                //제자리 복귀
                if (ny == sy && nx == sx) break;
            }
            //블럭
            else if (map[ny][nx] > 0 && map[ny][nx] < 6) {
                d = direction[map[ny][nx]][d];
                cnt++;
            }
            //웜홀
            else if (map[ny][nx] > 5 && map[ny][nx] < 11) {
                if(ny == warmhole[map[ny][nx]-6][0].first && nx == warmhole[map[ny][nx]-6][0].second){
                    x = warmhole[map[ny][nx]-6][1].second;
                    y = warmhole[map[ny][nx]-6][1].first;
                }
                else{
                    x = warmhole[map[ny][nx]-6][0].second;
                    y = warmhole[map[ny][nx]-6][0].first;
                }
            }
            //블랙홀
            else break;
        }
        //out of bound
        else {
            if (d == 0) d = 1;
            else if (d == 1) d = 0;
            else if (d == 2) d = 3;
            else d = 2;
            cnt++;
        }
    }
    if(sol < cnt)
        sol = cnt;
}

void simulation() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                if(map[i][j] == 0)
                    move(i, j, k);
            }
        }
    }
}
void init(){
    sol = 0 ;
    for(int i = 0 ;i <5 ; i++)
        warmhole[i].clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                //웜홀이면 좌표 추가
                if (map[i][j] > 5 && map[i][j] < 11) {
                    warmhole[map[i][j] - 6].emplace_back(make_pair(i, j));
                }
            }
        }
        simulation();
        cout << "#"<<a++<<" "<<sol << endl;
        init();
    }
    return 0;
}

