//
// Created by vkdne on 2018-04-14.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> pvArr[8];
int dx[5] = { 0,0,0,-1,1 };	//1~4 상하좌우
int dy[5] = { 0,-1,1,0,0 };
int map[51][51];
int visit[51][51];
int sol;
int N, M;	//맵의 크기
int R, C;	//맨홀의 위치(+1해줘야함)
int L;		//탈출후 소요된 시간
struct xy {
    int y, x;
};
queue<xy> q;
void setDirection() {
    pvArr[1].push_back(1);
    pvArr[1].push_back(2);
    pvArr[1].push_back(3);
    pvArr[1].push_back(4);
    pvArr[2].push_back(1);
    pvArr[2].push_back(2);
    pvArr[3].push_back(3);
    pvArr[3].push_back(4);
    pvArr[4].push_back(1);
    pvArr[4].push_back(4);
    pvArr[5].push_back(2);
    pvArr[5].push_back(4);
    pvArr[6].push_back(2);
    pvArr[6].push_back(3);
    pvArr[7].push_back(1);
    pvArr[7].push_back(3);
}

bool check(int direction,int end) {
    int d;
    if (direction == 1)
        d = 2;
    else if (direction == 2)
        d = 1;
    else if (direction == 3)
        d = 4;
    else
        d = 3;

    for (auto a : pvArr[end]) {
        if (a == d)
            return true;
    }
    return false;
}

void bfs() {
    int t = 1;
    xy front;
    int ny, nx;
    while (!q.empty()) {
        int c = q.size();
        while (c--) {
            front = q.front();
            q.pop();
            for (auto at : pvArr[map[front.y][front.x]]) {
                ny = front.y + dy[at];
                nx = front.x + dx[at];
                if (nx > 0 && nx <= M && ny > 0 && ny <= N && map[ny][nx] != 0 && visit[ny][nx] == 0) {
                    if (check(at, map[ny][nx])) {
                        visit[ny][nx] = 1;
                        sol++;
                        q.push({ ny,nx });
                    }
                }
            }
        }
        t++;
        if (t == L)
            break;
    }
    return;
}

void init() {
    sol = 0;
    fill_n(&visit[0][0], 51 * 51, 0);
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    //파이프 방향 설정
    setDirection();
    //입력
    int T;
    cin >> T;
    int c = 1;
    while (T--) {
        cin >> N >> M >> R >> C >> L;
        R++; C++;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> map[i][j];
            }
        }
        if (L == 1) {
            cout << "#" << c << " " << 1 << endl;
            init();
            c++;
            continue;
        }
        sol++;
        visit[R][C] = 1;
        q.push({R,C});
        bfs();
        cout << "#" << c << " " << sol << endl;
        init();
        c++;

    }
    return 0;
}
