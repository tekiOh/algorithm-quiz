#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct strct{
    int cnt;
    int rx,ry,bx,by;
};

queue<strct> q;

int visit[11][11][11][11];
char map[12][12];

int main(){
    int N,M;
    cin >> N >> M;
    int rx,ry,bx,by;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R') {
                rx = i;
                ry = j;
            }

            if(map[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    visit[rx][ry][bx][by] = 1;
    q.push({0,rx,ry,bx,by});
    //BFS
    while(q.size()){
        strct temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nrx = temp.rx;
            int nry = temp.ry;
            int nbx = temp.bx;
            int nby = temp.by;
            int cr = 0;
            int cb = 0;
            //R 움직임
            while(map[nrx+dx[i]][nry+dy[i]] != '#' && map[nrx][nry] != 'O'){
                nrx += dx[i];
                nry += dy[i];
                cr++;
            }
            //B 움직임
            while(map[nbx+dx[i]][nby+dy[i]] != '#' && map[nbx][nby] != 'O'){
                nbx += dx[i];
                nby += dy[i];
                cb++;
            }
            //R,B가 같은 위치에 있을 때
            if(nrx == nbx && nry == nby){
                //실패
                if(map[nrx][nry] == 'O')
                    continue;
                //우선순위로 판단
                if(cb > cr){
                    nbx -= dx[i];
                    nby -= dy[i];
                }
                else{
                    nrx -= dx[i];
                    nry -= dy[i];
                }
            }
            //실패
            if(map[nbx][nby] == 'O') {
                continue;
            }
            //성공 답 출력
            if(map[nrx][nry] == 'O'){
                cout <<temp.cnt+1 << endl;
                return 0;
            }
            if(visit[nrx][nry][nbx][nby] == 1)
                continue;
            //큐에 추가
            if(temp.cnt < 9){
                visit[nrx][nry][nbx][nby] == 1;
                q.push({temp.cnt+1,nrx,nry,nbx,nby});
            }
        }
    }
    //다 안되면 -1 출력
    cout << "-1"<<endl;
    return 0;
}