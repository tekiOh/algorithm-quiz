//
// Created by vkdne on 2018-09-26.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int map[31][20];
int sol = -1;
struct yx {
    int y, x;
};
vector<yx> v;

bool move(int row, int col, int target) {
    while (row != H + 1) {
        if (col - 1 > 0 && (map[row][col - 1] == 1 || map[row][col - 1] == 3)) {
            row++;
            col -= 2;
        } else if (col + 1 < 2 * N - 1 && (map[row][col + 1] == 1 || map[row][col + 1] == 3)) {
            row++;
            col += 2;
        } else {
            row++;
        }
    }

    if (col == target)
        return true;
    return false;
}

bool simulation() {
    for (int i = 1; i <= 2 * N - 1; i += 2) {
        if (!move(1, i, i))
            return false;
    }
    return true;
}

bool chk(yx a) {
    if (a.x > 2) {
        if (map[a.y][a.x - 2] == 1 || map[a.y][a.x - 2] == 3)
            return false;
    }
    if (a.x < 2 * N - 2) {
        if (map[a.y][a.x + 2] == 1 || map[a.y][a.x + 2] == 3)
            return false;
    }
    return true;
}

void calc() {
    int size = v.size();
    //0개
    if (simulation()) {
        sol = 0;
        return;
    }
    //1개
    if (size >= 1) {
        for (int i = 0; i < size; i++) {
            if (chk(v[i])) {
                map[v[i].y][v[i].x] = 3;
                if (simulation()) {
                    sol = 1;
                    return;
                }
                map[v[i].y][v[i].x] = 0;
            }
        }
    }
    if (size >= 2) {
        //2개
        for (int i = 0; i < size - 1; i++) {
            if (chk(v[i])) {
                map[v[i].y][v[i].x] = 3;
                for (int j = i + 1; j < size; j++) {
                    if (chk(v[j])) {
                        map[v[j].y][v[j].x] = 3;
                        if (simulation()) {
                            sol = 2;
                            return;
                        }
                        map[v[j].y][v[j].x] = 0;
                    }
                }
                map[v[i].y][v[i].x] = 0;
            }
        }
    }
    if (size >= 3) {
        //3개
        for (int k = 0; k < size - 2; k++) {
            if (chk(v[k])) {
                map[v[k].y][v[k].x] = 3;
                for (int i = k + 1; i < size - 1; i++) {
                    if (chk(v[i])) {
                        map[v[i].y][v[i].x] = 3;
                        for (int j = i + 1; j < size; j++) {
                            if (chk(v[j])) {
                                map[v[j].y][v[j].x] = 3;
                                if (simulation()) {
                                    sol = 3;
                                    return;
                                }
                                map[v[j].y][v[j].x] = 0;
                            }
                        }
                        map[v[i].y][v[i].x] = 0;
                    }
                }
                map[v[k].y][v[k].x] = 0;
            }
        }
    }
}


int main() {
    v.reserve(300);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a][2 * b] = 1;
        if (2 * b - 2 > 0)
            map[a][2 * b - 2] = 2;
        if (2 * b + 2 < 2 * N)
            map[a][2 * b + 2] = 2;
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 2; j < 2 * N; j += 2) {
            if (map[i][j] == 0)
                v.push_back({i, j});
        }
    }

    calc();
    cout << sol << '\n';
    return 0;
}