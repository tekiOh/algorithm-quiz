//
// Created by vkdne on 2018-09-17.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int T, w, h;
int cx, cy;  //(w,h에 매칭)
char map[1001][1001];
int visit[1001][1001];
int visitfire[1001][1001];
int sol;
struct xy {
    int y, x;
};
queue<xy> qh;    //철수(x,y)
queue<xy> qf;    //불(x,y)
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


void printMap() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

bool chkPoint(int y, int x) {
    if (x > 0 && x <= w && y > 0 && y <= h)
        return true;
    return false;
}

bool chkSol(int y, int x) {
    if (x == 1 || x == w || y == 1 || y == h)
        return true;
    return false;
}

void bfs(int cnt) {
    //일단 불을 하나 전진시킴!
    int qf_size = qf.size();
    xy tmpfire;
    int nx, ny;
    while (qf_size--) {
        tmpfire = qf.front();
        qf.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmpfire.x + dx[i];
            ny = tmpfire.y + dy[i];
//            cout << "fire : " << ny << "," << nx << endl;
//            cout << "visitfire : " << visitfire[ny][nx] << endl;
//            cout << "chkPoint : " << chkPoint(ny, nx) << endl;
//            cout << "map : " << map[ny][nx] << endl;
            if (!visitfire[ny][nx] && chkPoint(ny, nx) && map[ny][nx] != '#') {
                map[ny][nx] = '*';
                visitfire[ny][nx] = 1;
                qf.push({ny, nx});

            }
        }
    }
//    cout << cnt+1 <<"seconds later"<<endl;
//    printMap();
    //철수를 이동시킨다
    int qh_size = qh.size();
    xy tmph;
    while (qh_size--) {
        tmph = qh.front();
        qh.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmph.x + dx[i];
            ny = tmph.y + dy[i];
            if (!visit[ny][nx] && chkPoint(ny, nx) && map[ny][nx] == '.') {
                if (chkSol(ny, nx)) {
                    sol = cnt + 1;
                    return;
                }
                visit[ny][nx] = 1;
                qh.push({ny, nx});
            }
        }
    }

    if (!qh.empty())
        bfs(cnt + 1);
}

void init() {
    queue<xy> a,b;
    qf.swap(a);
    qh.swap(b);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            visit[i][j] = 0;
            visitfire[i][j] = 0;
        }
    }

    sol = -1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        sol = -1;
        cin >> w >> h;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '*') {
                    qf.push({i, j});
                    visitfire[i][j] = 1;
                    //cout << "fire : " << j <<","<<i<<endl;
                } else if (map[i][j] == '@') {
                    qh.push({i, j});
                    visit[i][j] = 1;
                    //cout << "human : " << j <<","<<i<<endl;
                }
            }
        }
        if (chkSol(qh.front().y, qh.front().x)) {
            cout << "1" << endl;
            init();
            continue;
        }
        bfs(0);
        if (sol == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << sol + 1 << endl;
        }
        init();
    }
    return 0;
}