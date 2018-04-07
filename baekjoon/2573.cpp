//
// Created by vkdne on 2018-04-07.
//
#include <iostream>
#include <queue>
using namespace std;

int map[301][301];
int cv[301][301];
int visit[301][301];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N,M;
struct xy{
    int x,y;
};
queue<xy> q;
void countV(){
    int nx,ny;
    int cnt;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ; j++) {
            cnt = 0;
            if (map[i][j] != 0) {
                for (int k = 0; k < 4; k++) {
                    ny = i + dy[k];
                    nx = j + dx[k];
                    if (nx > 0 && nx <= M && ny > 0 && ny <= N && map[ny][nx] == 0)
                        cnt++;
                }
                cv[i][j] = cnt;
            }
        }
    }

    /*cout << "ice breaking speed"<<endl;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ; j++) {
            cout << cv[i][j] << " ";
        }
        cout << endl;
    }*/

}
void bfs(){
    int nx,ny;
    while(!q.empty()){
        xy tmp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
                if(nx > 0 && nx <= M && ny > 0 && ny <= N && map[ny][nx] != 0 && visit[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    q.push({nx,ny});
                }
        }
    }
}

int countCluster() {
    fill_n(&visit[0][0],301*301,0);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if(map[i][j] != 0 &&visit[i][j] == 0){
                visit[i][j] = 1;
                q.push({j,i});
                cnt++;
                bfs();
            }
        }
    }
    //cout << "current cluster num :"<<cnt<<endl;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ; j++)
            cin >> map[i][j];
    }

    countV();
    int sol = 0;
    while(1){
        int cntC = countCluster();
        //빙산이 2개이상으로 분리되면 시간 출력 후 종료
        if(cntC >= 2){
            cout << sol << endl;
            return 0;
        }
        //빙산이 다 없어졌으면 0 출력 후 종료
        if(cntC == 0 ){
            cout << 0 << endl;
            return 0;
        }
        //시간 경과 >> 빙산 붕괴
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1; j <= M ; j++){
                map[i][j] -= cv[i][j];
                if(map[i][j] <= 0) {
                    map[i][j] = 0;
                }
            }
        }
        sol++;
        //다시 빙산 붕괴 속도 계산
        countV();
    }
}