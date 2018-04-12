//
// Created by vkdne on 2018-04-12.
//

#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int N;	//셀의 크기
int M;	//격리 시간
int K;	//미생물 군집의 개수
int dx[5] = { 0,0,0,-1,1 };	//1~4 : 상하좌우
int dy[5] = { 0,-1,1,0,0 };
int sol;
struct micro {
    int y, x, c, d;	//세로,가로,개수,방향
};
queue<micro> q;
void makeOne(int y, int x) {
    int maxc = 0;
    int nc = 0;
    int nd = 0;
    int t = q.size();
    micro front;
    while(t--){
        front = q.front();
        q.pop();
        //찾는 위치의 미생물이면 계산시작
        if (front.x == x && front.y == y) {
            //미생물 수가 가장 많으면 방향 바꾸고 max값 바꿈
            if (maxc < front.c) {
                maxc = front.c;
                nd = front.d;
            }
            //미생물 수 더함
            nc += front.c;
        }
            //찾는 미생물이 아니면 다시 push
        else {
            q.push(front);
        }
    }
    //큐를 다 봤으면
    //하나로 합친 걸 push
    //맵 1로 체크
    q.push({ y,x,nc,nd });
    map[y][x] = 1;
    return;
}
void mapcheck(){
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //한곳에 군집이 2개이상 있는 경우 합치자!
            if (map[i][j] > 1) {
                makeOne(i, j);
            }
        }
    }
    return;
}

void bfs(int d) {
    //M시간 경과하면 결과 리턴
    if (d == M) {
        return;
    }
    int t = q.size();
    micro front;
    int ny, nx, nc, nd;
    while (t--) {
        front = q.front();
        q.pop();
        if (front.x == -1)
            continue;
        nx = front.x + dx[front.d];
        ny = front.y + dy[front.d];
        nc = front.c;
        nd = front.d;
        //약품이 칠해진 곳으로 가면~
        //방향 바뀌고, 수 반으로 줄고~
        if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
            //방향 반대로~
            if (nd == 1)
                nd = 2;
            else if (nd == 2)
                nd = 1;
            else if (nd == 3)
                nd = 4;
            else
                nd = 3;
            //수 반으로~
            nc /= 2;
        }
        //새로운 위치 체크
        map[front.y][front.x]--;
        map[ny][nx]++;
        //새로운 위치 큐에 넣는다
        q.push({ ny,nx,nc,nd });
    }
    //한시간 끝나고
    //맵을 체크해서 여러명이 있는 곳을 처리
    mapcheck();
    bfs(d + 1);
}
void calc() {
    while (!q.empty()) {
        sol += q.front().c;
        q.pop();
    }
}
int main() {
    int T;
    cin >> T;
    int y, x, c, d;
    int shp = 1;
    while (T--) {
        //입력
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            cin >> y >> x >> c >> d;
            q.push({ y,x,c,d });
            map[y][x]++;
        }

        bfs(0);
        calc();
        cout <<"#"<<shp<<" "<< sol << endl;
        while (!q.empty())
            q.pop();
        //초기화
        sol = 0;
        fill_n(&map[0][0], 101 * 101, 0);
        //case num ++
        shp++;
    }

    return 0;
}