//
// Created by vkdne on 2018-09-24.
//

#include <iostream>
#include <queue>

using namespace std;

struct xy {
    int y, x;
};
vector<xy> vv;
vector<xy> wv;
int wvsize;
int vvsize;
queue<xy> q;
int N, M;    //세로, 가로
int nmap[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int sol;

void makeQueue() {
    for (int i = 0; i < vvsize; i++)
        q.push(vv[i]);
}

void bfs() {
    xy tmp;
    int nx, ny;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if (nmap[ny][nx] == 0 && nx >= 0 && nx < M && ny >= 0 && ny < N) {
                nmap[ny][nx] = 3;
                q.push({ny, nx});
            }
        }
    }
    int mmax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (nmap[i][j] == 0)
                mmax++;
            else if (nmap[i][j] == 3)
                nmap[i][j] = 0;
        }
    }

    if (sol < mmax)
        sol = mmax;
}

int main() {
    vv.reserve(64);
    wv.reserve(64);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> nmap[i][j];
            if (nmap[i][j] == 2) {
                vv.push_back({i, j});
            } else if (nmap[i][j] == 0) {
                wv.push_back({i, j});
            }
        }
    }
    wvsize = wv.size();
    vvsize = vv.size();
    for (int i = 0; i <wvsize - 2; i++) {
        for (int j = i + 1; j < wvsize - 1; j++) {
            for (int k = j + 1; k < wvsize; k++) {
                nmap[wv[i].y][wv[i].x] = 1;
                nmap[wv[j].y][wv[j].x] = 1;
                nmap[wv[k].y][wv[k].x] = 1;
                makeQueue();
                bfs();
                nmap[wv[i].y][wv[i].x] = 0;
                nmap[wv[j].y][wv[j].x] = 0;
                nmap[wv[k].y][wv[k].x] = 0;
            }
        }
    }

    cout << sol << endl;
    return 0;
}

