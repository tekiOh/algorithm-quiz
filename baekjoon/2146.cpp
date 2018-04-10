#include<iostream>
#include<vector>
#include <queue>
using namespace std;
int map[101][101][2];
int visit[101][101];
int N;
int cnt; //섬 라벨링에 필요
struct xy{
    int y,x;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<xy> q;
vector<xy> v[5001];
int sol = 99999999;
void label(){
    xy front;
    int ny,nx;
    bool chk;
    while(!q.empty()){
        front = q.front();
        q.pop();
        chk = false;
        for(int i = 0 ; i < 4; i++){
            ny = front.y + dy[i];
            nx = front.x + dx[i];
            //ny,nx가 유효한 좌표면
            if(nx > 0 && nx < N+1 && ny > 0 && ny < N+1){
                if(!chk){
                    //바다와 인접한 육지이면
                    if(map[ny][nx][0] == 0){
                        chk = true;
                        v[cnt].push_back({front.y,front.x});
                    }
                }
                //같은 섬의 육지를 찾으면
                if(map[ny][nx][0] == 1 && visit[ny][nx] == 0) {
                    map[ny][nx][0] = cnt;
                    visit[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }

        }
    }
}
int main(){
    cin >> N;
    //map 입력
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= N ; j++)
            cin >> map[i][j][0];
    //섬 라벨링
    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            //방문하지않았고, 바다가 아닌 육지이면 BFS
            if(visit[i][j] == 0 && map[i][j][0] == 1){
                cnt++;
                visit[i][j] = 1;
                map[i][j][0] = cnt;
                q.push({i,j});
                label();
            }
        }
    }

    //최단 다리 계산
    int ix,iy;
    int jx,jy;
    int difx,dify;
    for(int i = 1; i < cnt ; i++){
        for(int j = i+1; j < cnt+1 ; j++){
            for(auto ixy : v[i]){
                ix = ixy.x;
                iy = ixy.y;
                for(auto jxy : v[j]){
                    jx = jxy.x;
                    jy = jxy.y;
                    difx = ix - jx;
                    dify = iy - jy;
                    if(difx < 0)
                        difx = -(difx);
                    if(dify < 0)
                        dify = -(dify);
                    if(sol > difx + dify - 1)
                        sol = difx + dify - 1;
                }
            }
        }
    }

    cout << sol << endl;


    return 0;
}