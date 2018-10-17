//
// Created by vkdne on 2018-10-17.
//
#include <iostream>
#include <vector>

using namespace std;

struct atom {
    int y, x, d, k, crash;
};
//vector<atom> atoms;
atom atoms[1000];
int map[4001][4001];
bool visit[4001][4001];
int T, N, sol;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void simulation() {
    int ny, nx;
    int cnt = 0;
    while (cnt != N) {
        for (int i = 0; i < N; i++) {
            if (!atoms[i].crash) {
                nx = atoms[i].x + dx[atoms[i].d];
                ny = atoms[i].y + dy[atoms[i].d];

                map[atoms[i].y][atoms[i].x]--;
                if (map[atoms[i].y][atoms[i].x] <= 1)
                    visit[atoms[i].y][atoms[i].x] = false;

                //out of bound
                if (nx < 0 || ny < 0 || nx > 4000 || ny > 4000) {
                    atoms[i].crash = 1;
                    cnt++;
                    continue;
                }
                    //in bound
                else {
                    atoms[i].x = nx;
                    atoms[i].y = ny;
                    map[ny][nx]++;
                    if (map[ny][nx] > 1)
                        visit[ny][nx] = true;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (!atoms[i].crash) {
                //충돌지역이면
                if (visit[atoms[i].y][atoms[i].x]) {
                    atoms[i].crash = 1;
                    map[atoms[i].y][atoms[i].x]--;
                    //마지막 원소이면
                    if (!map[atoms[i].y][atoms[i].x]) {
                        visit[atoms[i].y][atoms[i].x] = false;
                    }
                    sol += atoms[i].k;
                    cnt++;
                }
            }
        }
        //cout << cnt << endl;
    }
}

void init() {
    sol = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    int x, y, d, k;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> d >> k;
            atoms[i] = {2 * (y + 1000), 2 * (x + 1000), d, k, 0};
            map[2 * (y + 1000)][2 * (x + 1000)] = 1;
        }
        simulation();
        cout << "#" << a++ << " " << sol << '\n';
        init();
    }
}
