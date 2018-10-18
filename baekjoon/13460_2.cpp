//
// Created by vkdne on 2018-10-18.
//
#include <iostream>
#include <queue>
using namespace std;
int N,M,r_x,r_y,b_x,b_y;
char map[10][10];
int visit[10][10][10][10];
struct ball{
    int rx,ry,bx,by;
};
queue<ball>q;
//상하좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void simulation(){
    int t = 0;
    int size,nrx,nry,nbx,nby;
    int cntr,cntb;
    bool chkR,chkB;
    ball tmp;
    while(t < 10){
        size = q.size();
        while(size--){
            tmp = q.front();
            q.pop();
//            cout <<"start from"<<endl;
//            cout << "rx,ry,bx,by"<<endl;
//            cout << nrx<<", "<<nry<<", "<<nbx<<", "<<nby<<endl;
            //4방향 이동
            for(int i = 0 ; i < 4 ; i++){
                nrx = tmp.rx;
                nry = tmp.ry;
                nbx = tmp.bx;
                nby = tmp.by;
                cntr = 0;
                cntb = 0;
                chkR = false;
                chkB = false;
                //R부터 이동
                //벽, 구멍이 아닐 때까지 움직임
                while(map[nry+dy[i]][nrx+dx[i]] != '#' && map[nry+dy[i]][nrx+dx[i]] != 'O'){
                    nry += dy[i];
                    nrx += dx[i];
                    cntr++;
                }
                if(map[nry+dy[i]][nrx+dx[i]] == 'O')
                    chkR = true;

                while(map[nby+dy[i]][nbx+dx[i]] != '#' && map[nby+dy[i]][nbx+dx[i]] != 'O'){
                    nby += dy[i];
                    nbx += dx[i];
                    cntb++;
                }

                if(map[nby+dy[i]][nbx+dx[i]] == 'O')
                    chkB = true;


                //R만 구멍에 빠져야!
                if(chkR && !chkB){
                    cout << t + 1 << endl;
                    return;
                }
                //B가 구멍에 빠지면 안됨
                else if(chkB){
                    continue;
                }

                //같은 곳이면 우선순위 파악
                if(nby == nry && nbx == nrx){
                    //R이 우선
                    if(cntb > cntr){
                        nby -= dy[i];
                        nbx -= dx[i];
                    }
                    //B가 우선
                    else{
                        nry -= dy[i];
                        nrx -= dx[i];
                    }
                }
                if(!visit[nry][nrx][nby][nbx]){
//                    cout << "direction : "<<i<<", end position"<<endl;
//                    cout << nrx<<", "<<nry<<", "<<nbx<<", "<<nby<<endl;
                    visit[nry][nrx][nby][nbx] = 1;
                    q.push({nrx,nry,nbx,nby});
                }
            }
        }
        t++;
    }
    cout << -1 << endl;
    return;
}
int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                r_y = i;
                r_x = j;
            }
            else if(map[i][j] == 'B'){
                b_y = i;
                b_x = j;
            }
        }
    }
    q.push({r_x,r_y,b_x,b_y});
    visit[r_y][r_x][b_y][b_x] = 1;
    simulation();
    return 0;
}