//
// Created by vkdne on 2018-10-10.
//

#include <iostream>
#include <queue>

using namespace std;

//[x][y][0] : 세포 시간, [x][y][1] : 생성된 시간, [0]과[1]을 이용해 죽었는지 살았는지 활성화인지 비활성화인지
struct cell {
    int x, y, t, bt;  //x,y좌표, 활성화시간, 생성시간
};
queue<cell> q;
int map[700][700][2];
int T, N, M, K,sol,time_cnt;
//방향 상하좌우 y++,y--,x--,x++
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void move() {
    int size = q.size();
    int nx, ny;
    cell tmp;
    while (size--) {
        tmp = q.front();
        q.pop();
        //현재 세포가 자리를 못잡고 뺏겼을 때
        if (map[tmp.y][tmp.x][0] != tmp.t) {
            continue;
        }
        //활성화상태일때
        if (time_cnt - tmp.bt >= tmp.t){
            if( time_cnt < tmp.bt + 2*tmp.t) {
                //4방향으로 전파
                for (int i = 0; i < 4; i++) {
                    nx = tmp.x + dx[i];
                    ny = tmp.y + dy[i];
                    //빈자리이면 전파
                    if (!map[ny][nx][0] || (map[ny][nx][0] < tmp.t && map[ny][nx][1] == time_cnt+1)) {
                        map[ny][nx][0] = tmp.t;
                        map[ny][nx][1] = time_cnt + 1;
                        q.push({nx, ny, tmp.t, time_cnt + 1});
                    }
                }
            }
        }
            //비활성화상태이면 다시 큐로
        else {
            q.push(tmp);
        }
    }
//    cout << "*******************" << endl;
//    cout <<"time : "<<time+1<<endl;
//    for (int i = 390; i <= 410; i++) {
//        for (int j = 390; j <= 410; j++) {
//            cout << map[i][j][0]<<" ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    calcMsol(time+1);

}

void calc() {
    for (int i = 0; i < 700; i++) {
        for (int j = 0; j < 700; j++) {
            if (map[i][j][0] != 0 && K < 2*map[i][j][0] + map[i][j][1])
                sol++;
        }
    }
}
void init(){
    queue<cell> nq;
    swap(q,nq);
    time_cnt = 0;
    sol = 0;
    for(int i = 0 ;i < 700 ; i++){
        for(int j = 0 ; j < 700 ; j++) {
            map[i][j][0] = 0;
            map[i][j][1] = 0;
        }
    }
}
void simulation() {
    while (time_cnt < K) {
        move();
        time_cnt++;
    }
    calc();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 350; i < 350 + N; i++) {
            for (int j = 350; j < 350 + M; j++) {
                cin >> map[i][j][0];
                map[i][j][1] = 0;
                //세포이면
                if (map[i][j][0]) {
                    q.push({j, i, map[i][j][0], 0});
                }
            }
        }
        simulation();
        cout << "#" << a << " " << sol << '\n';
        a++;
        init();
    }

    return 0;
}