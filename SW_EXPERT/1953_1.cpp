//
// Created by vkdne on 2018-10-14.
//

#include <iostream>
#include <queue>

using namespace std;

int T, N, M, L;
int R, C;    //세로,가로
int sol = 1;
int map[50][50];
int visit[50][50];
int p[8][4] = {{},
               {1, 1, 1, 1},
               {1, 1, 0, 0},
               {0, 0, 1, 1},
               {1, 0, 0, 1},
               {0, 1, 0, 1},
               {0, 1, 1, 0},
               {1, 0, 1, 0}};
//상,하,좌,우 (y--,y++,x--,x++)
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void simulation() {
    int t = 1;
    int size, type, nx, ny;
    int from;
    pair<int, int> tmp;
    while (t < L) {
        size = q.size();
        while (size--) {
            tmp = q.front();
            q.pop();
            type = map[tmp.first][tmp.second];
            for (int i = 0; i < 4; i++) {
                //움직일수있는 방향이면
                if (p[type][i]) {
                    ny = tmp.first + dy[i];
                    nx = tmp.second + dx[i];
                    //유효한 점이면
                    //범위 안벗어나고, 구조물있고
                    if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] && !visit[ny][nx]) {
                        if (i == 0) from = 1;
                        else if (i == 1) from = 0;
                        else if (i == 2) from = 3;
                        else from = 2;
                        //이동할 방향의 구조물이 갈수있는 구조물이면!
                        if (p[map[ny][nx]][from]) {
                            visit[ny][nx] = 1;
                            q.push({ny, nx});
                            sol++;
                        }
                    }
                }
            }
        }
        t++;
//        cout<<t<<"seconds later!!"<<endl;
//        for(int i = 0 ;i < N; i++){
//            for(int j = 0 ; j < M ; j++){
//                cout << visit[i][j]<<" ";
//            }
//            cout << endl;
//        }
    }
}
void init(){
    sol = 1;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            visit[i][j] = 0;

    queue<pair<int,int>> nq;
    swap(q,nq);
}
int main() {
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> M >> R>>C>>L;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> map[i][j];


        q.push({R, C});
        visit[R][C] = 1;
        simulation();
        cout <<"#"<<a++<<" "<<sol<<endl;
        init();
    }


    return 0;
}