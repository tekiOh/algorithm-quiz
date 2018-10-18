//
// Created by vkdne on 2018-10-18.
//

#include <iostream>
#include <queue>
using namespace std;
int map[1000][1000][2]; //[y][x][0] : 수명, [y][x][1] : 태어난 시간
int T, N, M, K, sol;
struct cell {
    int y, x, life;
};
queue<cell> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void printMap() {
    for (int i = 485; i < 515; i++) {
        for (int j = 485; j < 515; j++) {
            cout << map[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << "***********************" << endl;
}

bool chkPoint(int y, int x, int life, int t) {
    //아무도 없으면
    if (map[y][x][0] == 0)
        return true;
    else {
        //누가 있지만 같은 시간에 생성되고 내가 더 쎌때
        if (map[y][x][1] == t && map[y][x][0] < life)
            return true;
        return false;
    }
}

void calc() {
    for (int i = 500 - K - 1; i < 500 + K + 1; i++) {
        for (int j = 500 - K - 1; j < 500 + K + 1; j++) {
            if (2 * map[i][j][0] + map[i][j][1] > K)
                sol++;
        }
    }
}

void simulation() {
    int t = 0;
    int size, ny, nx;
    cell tmp;
    while (t < K) {
        size = q.size();
        while (size--) {
            tmp = q.front();
            q.pop();
            //큐에는 들어갔지만 더 쎈애가 점유된 상태이면 유효한 세포가 아님
            if (map[tmp.y][tmp.x][0] == tmp.life) {
                //태어난 시간 + 수명 == 현재시간 >> 알까기
                if (map[tmp.y][tmp.x][0] + map[tmp.y][tmp.x][1] == t) {
                    for (int i = 0; i < 4; i++) {
                        ny = tmp.y + dy[i];
                        nx = tmp.x + dx[i];
                        //유효한 점인지 확인하고 알깔수있으면 깐다
                        if (chkPoint(ny, nx, tmp.life, t + 1)) {
                            map[ny][nx][0] = tmp.life;
                            map[ny][nx][1] = t + 1;
                            q.push({ny, nx, tmp.life});
                        }
                    }
                }
                    //비활성화
                else
                    q.push(tmp);
            }
        }
        //알까고 시간 증가
        t++;
//        cout << t << "second later!!!!!!!!" << endl;
//        printMap();
    }
    calc();
}
void init(){
    queue<cell> nq;
    swap(q,nq);
    sol = 0;
    for (int i = 500 - K - 1; i < 500 + K + 1; i++) {
        for (int j = 500 - K - 1; j < 500 + K + 1; j++) {
            map[i][j][0] = 0;
            map[i][j][1] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 500; i < 500 + N; i++) {
            for (int j = 500; j < 500 + M; j++) {
                cin >> map[i][j][0];
                if (map[i][j][0]) {
                    q.push({i, j, map[i][j][0]});
                }
            }
        }
        simulation();
        cout << "#" << a++ << " " << sol << endl;
        init();
    }
    return 0;
}