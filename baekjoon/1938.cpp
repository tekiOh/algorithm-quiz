//
// Created by vkdne on 2018-09-13.
//
#include<iostream>
#include <queue>
#include <string>
using namespace std;
int N;
char map[50][50];
int visit[50][50][50][50];
int bsx, bsy, bex, bey;
int sol = 0;
struct bxy {
    int ey, ex, sy, sx;
    int cnt;

};
queue<bxy> q;

bool chk(int ay, int ax, int by, int bx) {
    if (ay >= 0 && ay < N && ax >= 0 && ax < N && by >= 0 && by < N &&
        bx >= 0 && bx < N && visit[ay][ax][by][bx] != 1 && visit[by][bx][ay][ax] != 1 && map[ay][ax] != '1' &&
        map[by][bx] != '1' && map[(ay+by)/2][(ax+bx)/2] != '1')
        return true;
    return false;
}

bool treechk(int ay, int ax, int by, int bx) {
    if (ay >= 0 && ay < N && ax >= 0 && ax < N && by >= 0 && by < N &&
        bx >= 0 && bx < N && map[ay][ax] != '1' &&
        map[by][bx] != '1'&& map[(ay+by)/2][(ax+bx)/2] != '1')
        return true;
    return false;
}
bool turnchk(int ay, int ax, int by, int bx){
    if(ax == bx){
        //left,right가능?
        if(treechk(ay, ax - 1, by, bx - 1) && treechk(ay, ax + 1, by, bx + 1))
            return true;
        return false;
    }
    //up,down가능?
    else{
        if(treechk(ay - 1, ax, by - 1, bx) && treechk(ay + 1, ax, by + 1, bx))
            return true;
        return false;
    }
}

bool isSol(int ay, int ax, int by, int bx) {
    if (map[ay][ax] == 'E' && map[by][bx] == 'E')
        return true;
    return false;
}

void bfs() {
    int size = q.size();
    bxy tmp;
    while (size--) {
        tmp = q.front();
        q.pop();

        //up
        if (chk(tmp.ey - 1, tmp.ex, tmp.sy - 1, tmp.sx)) {
            if (isSol(tmp.ey - 1, tmp.ex, tmp.sy - 1, tmp.sx)) {
                sol = tmp.cnt + 1;
                break;
            } else {
                q.push({tmp.ey - 1, tmp.ex, tmp.sy - 1, tmp.sx, tmp.cnt + 1});
                visit[tmp.ey-1][tmp.ex][tmp.sy-1][tmp.sx] = 1;
                visit[tmp.sy-1][tmp.sx][tmp.ey-1][tmp.ex] = 1;
            }
        }
        //down
        if (chk(tmp.ey + 1, tmp.ex, tmp.sy + 1, tmp.sx)) {
            if (isSol(tmp.ey + 1, tmp.ex, tmp.sy + 1, tmp.sx)) {
                sol = tmp.cnt + 1;
                break;
            } else {
                q.push({tmp.ey + 1, tmp.ex, tmp.sy + 1, tmp.sx, tmp.cnt + 1});
                visit[tmp.ey+1][tmp.ex][tmp.sy+1][tmp.sx] = 1;
                visit[tmp.sy+1][tmp.sx][tmp.ey+1][tmp.ex] = 1;
            }
        }
        //right
        if (chk(tmp.ey, tmp.ex + 1, tmp.sy, tmp.sx + 1)) {
            if (isSol(tmp.ey, tmp.ex + 1, tmp.sy, tmp.sx + 1)) {
                sol = tmp.cnt + 1;
                break;
            } else {
                q.push({tmp.ey, tmp.ex + 1, tmp.sy, tmp.sx + 1, tmp.cnt + 1});
                visit[tmp.ey][tmp.ex+1][tmp.sy][tmp.sx+1] = 1;
                visit[tmp.sy][tmp.sx+1][tmp.ey][tmp.ex+1] = 1;
            }
        }
        //left
        if (chk(tmp.ey, tmp.ex - 1, tmp.sy, tmp.sx - 1)) {
            if (isSol(tmp.ey, tmp.ex - 1, tmp.sy, tmp.sx - 1)) {
                sol = tmp.cnt + 1;
                break;
            } else {
                q.push({tmp.ey, tmp.ex - 1, tmp.sy, tmp.sx - 1, tmp.cnt + 1});
                visit[tmp.ey][tmp.ex-1][tmp.sy][tmp.sx-1] = 1;
                visit[tmp.sy][tmp.sx-1][tmp.ey][tmp.ex-1] = 1;
            }
        }
        //turn
        if (turnchk(tmp.ey, tmp.ex, tmp.sy, tmp.sx)) {
            if (tmp.sy == tmp.ey) {
                if (chk(tmp.ey + 1, (tmp.ex + tmp.sx) / 2, tmp.sy - 1, (tmp.ex + tmp.sx) / 2)) {
                    if (isSol(tmp.ey + 1, (tmp.ex + tmp.sx) / 2, tmp.sy - 1, (tmp.ex + tmp.sx) / 2)) {
                        sol = tmp.cnt + 1;
                        break;
                    } else {
                        q.push({tmp.ey + 1, (tmp.ex + tmp.sx) / 2, tmp.sy - 1, (tmp.ex + tmp.sx) / 2, tmp.cnt + 1});
                        visit[tmp.ey+1][(tmp.ex + tmp.sx) / 2][tmp.sy-1][(tmp.ex + tmp.sx) / 2] = 1;
                        visit[tmp.sy-1][(tmp.ex + tmp.sx) / 2][tmp.ey+1][(tmp.ex + tmp.sx) / 2] = 1;
                    }
                }
            } else {
                if (chk((tmp.ey + tmp.sy) / 2, tmp.ex + 1, (tmp.ey + tmp.sy) / 2, tmp.sx - 1)) {
                    if (isSol((tmp.ey + tmp.sy) / 2, tmp.ex + 1, (tmp.ey + tmp.sy) / 2, tmp.sx - 1)) {
                        sol = tmp.cnt + 1;
                        break;
                    } else {
                        q.push({(tmp.ey + tmp.sy) / 2, tmp.ex + 1, (tmp.ey + tmp.sy) / 2, tmp.sx - 1, tmp.cnt + 1});
                        visit[(tmp.ey + tmp.sy) / 2][tmp.ex + 1][(tmp.ey + tmp.sy) / 2][tmp.sx - 1] = 1;
                        visit[(tmp.ey + tmp.sy) / 2][tmp.ex - 1][(tmp.ey + tmp.sy) / 2][tmp.sx + 1] = 1;
                    }
                }
            }
        }
    }
    //cout << q.size() << endl;
    if (sol == 0 && q.size() != 0)
        bfs();
    return;
}

int main() {
    cin >> N;
    int bcnt = 0;
    int ecnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'B') {
                if (bcnt == 0) {
                    bsx = j;
                    bsy = i;
                }
                if (bcnt == 2) {
                    bex = j;
                    bey = i;
                }
                bcnt++;
                continue;
            }
        }
    }

    visit[bey][bex][bsy][bsx] = 1;
    visit[bsy][bsx][bey][bex] = 1;
    q.push({bey, bex, bsy, bsx, 0});
    bfs();
    cout << sol << endl;


    return 0;
}