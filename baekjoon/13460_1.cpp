//
// Created by vkdne on 2018-09-20.
//

#include <iostream>
#include <queue>

using namespace std;
int N, M;    //세로,가로
char map[10][10];
int sol = -1;
int visit[10][10][10][10];
struct pos {
    int ry, rx, by, bx;
};
queue<pos> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool chkPoint(int y, int x) {
    if (x >= 0 && x < M && y >= 0 && y < N)
        return true;
    return false;
}

void bfs(int cnt) {
    int size = q.size();
    pos front;
    int nry, nrx, nby, nbx;
    bool chkr = false;
    bool chkb = false;
    int cntr = 0;
    int cntb = 0;

    while (size--) {
        front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nry = front.ry;
            nrx = front.rx;
            nby = front.by;
            nbx = front.bx;
            chkr = false;
            chkb = false;
            cntr = 0;
            cntb = 0;
            while (1) {
                //갈수있으면 계속 전진
                if (chkPoint(nry + dy[i], nrx + dx[i]) && map[nry + dy[i]][nrx + dx[i]] != '#') {
                    nry += dy[i];
                    nrx += dx[i];
                    cntr++;
                } else
                    break;
                //구멍이면 멈춰야지
                if (map[nry][nrx] == 'O') {
                    chkr = true;
                    break;
                }
            }

            while (1) {
                //갈수있으면 계속 전진
                if (chkPoint(nby + dy[i], nbx + dx[i]) && map[nby + dy[i]][nbx + dx[i]] != '#') {
                    nby += dy[i];
                    nbx += dx[i];
                    cntb++;
                } else
                    break;
                //구멍이면 멈춰야지
                if (map[nby][nbx] == 'O') {
                    chkb = true;
                    break;
                }
            }
            //방문했던 점이면 continue
            if (visit[nry][nrx][nby][nbx] == 1)
                continue;

            //정답 케이스이면
            if (chkr && !chkb) {
                sol = cnt + 1;
                return;
            }
            //파랑이 구멍에 들어가면 continue
            if (chkb)
                continue;

            //같은 점에 있으면
            //서열 정리
            if (nrx == nbx && nry == nby) {
                if (cntr > cntb) {
                    nry -= dy[i];
                    nrx -= dx[i];
                } else {
                    nby -= dy[i];
                    nbx -= dx[i];
                }
            }

            q.push({nry, nrx, nby, nbx});
            visit[nry][nrx][nby][nbx] = 1;
        }
    }
    if (cnt == 9 || q.empty())
        return;
    bfs(cnt + 1);
}

int main() {
    cin >> N >> M;
    pos s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                s.ry = i;
                s.rx = j;
            } else if (map[i][j] == 'B') {
                s.by = i;
                s.bx = j;
            }
        }
    }
    visit[s.ry][s.rx][s.by][s.bx] = 1;
    q.push(s);
    bfs(0);
    cout << sol << endl;
    return 0;
}