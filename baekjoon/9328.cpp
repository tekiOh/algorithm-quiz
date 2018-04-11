//
// Created by vkdne on 2018-04-11.
//
#include <iostream>
#include <queue>
using namespace std;

char map[101][101];
int visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct xy{
    int y,x;
};
queue<xy> q;
int h,w;
int keyA[123];
bool chk = true;
int sol;
void bfs(){
    xy front;
    int ny,nx;
    int ask;
    while(!q.empty()){
        front = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            ny = front.y+dy[i];
            nx = front.x+dx[i];
            if(nx >0 && nx < w+1 && ny >0 && ny < h+1 && map[ny][nx] != '*' && visit[ny][nx] ==0){
                ask = (int)map[ny][nx];
                //알파벳 대문자 -> 문
                if(ask > 64 && ask < 91){
                    //문을 열 수 있다
                    if(keyA[ask] == 1){
                        map[ny][nx] = '.';
                        visit[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
                //알파벳 소문자 -> 키
                if( ask > 96 && ask < 123){
                    map[ny][nx] = '.';
                    visit[ny][nx] = 1;
                    keyA[ask-32] = 1;
                    q.push({ny,nx});
                    chk = true;
                }
                // . -> 길
                if( ask == 46){
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                }
                // 문서 -> 답
                if(ask == 36){
                    sol++;
                    map[ny][nx] = '.';
                    visit[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
        }
    }
}

void openDoor(){
    //일단 열수있는 문을 다 염
    //open door
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            //문이면
            if((int)map[i][j] > 64 && (int)map[i][j] < 91){
                if(keyA[(int)map[i][j]] == 1)
                    map[i][j] = '.';
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string key;
    while(T--) {
        fill_n(keyA,123,0);
        sol = 0;
        cin >> h >> w;
        //map 입력
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }
        cin >> key;
        //가지고 있는 열쇠 추가, 소문자 -> 대문자와 비교하기위해 -32
        if (key != "0") {
            for (int i = 0; i < key.length(); i++)
                keyA[(int)key[i]-32] = 1;
        }
        //BFS
        while(1) {
            chk = false;
            openDoor();
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if ((((i > 0  && i < h+1) && (j == 1 || j == w))||((i == 1 || i ==h) && (j > 0 && j < w+1))) && (map[i][j] == '.'||map[i][j] == '$') && visit[i][j] == 0) {
                        if(map[i][j] == '$') {
                            map[i][j] = '.';
                            sol++;
                        }
                        visit[i][j] = 1;
                        q.push({i,j});
                        bfs();
                    }
                }
            }
            fill_n(&visit[0][0],101*101,0);
            if(!chk)
                break;
        }
        cout << sol << '\n';
    }
    return 0;
}