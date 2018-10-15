//
// Created by vkdne on 2018-10-15.
//

#include <iostream>
#include <queue>
using namespace std;

int T, N, M, K, sol;    //test case, 지도 크기, 시간, 미생물수
int visit[100][100][2];
//int microV[100][100][3]; //[y][x][0] : 해당좌표 미생물 합, [y][x][1] : 해당좌표 max미생물 수 , [y][x][2] : 해당좌표 max 미생물의 방향
int dx[5] = {-1, 0, 0, -1, 1};
int dy[5] = {-1, -1, 1, 0, 0};
struct micro {
    int y, x, c, d;
};
queue<micro> q;

// -1 : 범위 벗어남
// 0  : 범위 안
// 1  : 항생제
int chkPoint(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < N) {
        if (y == 0 || y == N - 1 || x == 0 || x == N - 1)
            return 1;
        return 0;
    }
    return -1;
}
//void printMap(){
//    cout<<"*********************************"<<endl;
//    for(int i = 0 ; i < N ; i++){
//        for(int j = 0 ; j < N ; j++){
//            cout << visit[i][j][1] <<"   ";
//        }
//        cout << endl;
//    }
//}
void makeOneMicro(int y, int x) {
    int size = q.size();
    int maxV = 0;
    int maxD = -1;
    int totalV = 0;
    micro tmp;
    while (size--) {
        tmp = q.front();
        q.pop();
        if (tmp.x == x && tmp.y == y) {
            if (tmp.c > maxV) {
                maxV = tmp.c;
                maxD = tmp.d;
            }
            totalV += tmp.c;
        } else {
            q.push(tmp);
        }
    }
    //합쳐서 다시 큐에
    q.push({y, x, totalV, maxD});
}

void makeSol() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol += visit[i][j][1];
        }
    }
}

void simulation() {
    int size, ny, nx, nd, type;
    int t = 0;
    micro tmp;
    //M초동안 반복
    while (t != M) {
        size = q.size();
        while (size--) {
            tmp = q.front();
            q.pop();
            ny = tmp.y + dy[tmp.d];
            nx = tmp.x + dx[tmp.d];
            type = chkPoint(ny, nx);
            //범위 안벗어남
            if (type == 0) {
                visit[tmp.y][tmp.x][0]--;
                visit[ny][nx][0]++;
                visit[tmp.y][tmp.x][1] -= tmp.c;
                visit[ny][nx][1] += tmp.c;
                q.push({ny, nx, tmp.c, tmp.d});
            }
                //항생제
            else {
                if (tmp.c / 2) {
                    visit[tmp.y][tmp.x][0]--;
                    visit[tmp.y][tmp.x][1]-= tmp.c;
                    visit[ny][nx][0]++;
                    visit[ny][nx][1] += tmp.c / 2;
                    if (tmp.d == 1) nd = 2;
                    else if (tmp.d == 2) nd = 1;
                    else if (tmp.d == 3) nd = 4;
                    else nd = 3;
                    q.push({ny, nx, tmp.c / 2, nd});
                } else {
                    visit[tmp.y][tmp.x][1] -= tmp.c;
                    visit[tmp.y][tmp.x][0]--;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //여러마리가 있으면!
                //하나로 합치자!
                if (visit[i][j][0] > 1) {
                    makeOneMicro(i, j);
                    visit[i][j][0] = 1;
                }
            }
        }
        t++;
    }
    makeSol();
}
void init(){
    queue<micro> nq;
    swap(q,nq);
    sol = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j= 0 ; j < N ; j++){
            visit[i][j][0] = 0;
            visit[i][j][1] = 0;
        }
    }
}
int main() {
    cin >> T;
    int a = 1;
    int x, y, c, d;    //x,y,미생물수,방향(1,2,3,4 상하좌우)
    while (T--) {
        cin >> N >> M >> K;
        while (K--) {
            cin >> y >> x >> c >> d;
            visit[y][x][0]++;
            visit[y][x][1] += c;
            q.push({y, x, c, d});
        }
        simulation();
        cout << "#" << a++ << " " << sol << endl;
        init();
    }
    return 0;
}