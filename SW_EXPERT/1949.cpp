//
// Created by vkdne on 2018-10-14.
//

#include <iostream>

using namespace std;
int T, N, K,sol; // 3 <= N높이 <= 8, 1 <=K 깎 <= 5, 1<=높이<=20
int map[8][8];
int visit[8][8];
int valCount[21];
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int findMaxVal() {
    for (int i = 20; i > -1; i--) {
        if (valCount[i])
            return i;
    }
}

bool chk(int y, int x) {
    if (!visit[y][x] && y >= 0 && y < N && x >= 0 && x < N)
        return true;
    return false;
}

void dfs(int y, int x, int cnt) {
    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        //유효한 점이면 들어가
        if (chk(ny, nx) && map[ny][nx] < map[y][x]) {
            //내리막길이어야!
            visit[ny][nx] = 1;
            dfs(ny, nx, cnt + 1);
            visit[ny][nx] = 0;
        }
        else{
            if(sol < cnt)
                sol = cnt;
        }
    }
}

void simulation() {
    int tmp, maxVal;
    //일단 깎을 곳을 정하고
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //얼마나 깎을 지 정하고
            //0부터~K까지
            tmp = map[i][j];
            maxVal = findMaxVal();
            valCount[tmp]--;
            for (int k = 0; k <= K; k++) {
                if (tmp - k < 0)
                    break;
                //cout <<i<<","<<j<<"->"<<k<<"down"<<endl;
                //깎고 봉우리부터 내려온다
                map[i][j] = tmp - k;
                valCount[map[i][j]]++;

                //cout << "maxVal : "<<maxVal<<endl;
                for (int a = 0; a < N; a++) {
                    for (int b = 0; b < N; b++) {
                        //봉우리이면!
                        //등산로 만들자아!
                        if (map[a][b] == maxVal) {
                            visit[a][b] = 1;
                            dfs(a, b, 0);
                            visit[a][b] = 0;
                        }
                    }
                }
                valCount[map[i][j]]--;
            }
            map[i][j] = tmp;
            valCount[tmp]++;
        }
    }
}
void init(){
    sol = 0;

    for(int i = 0 ; i < 21 ; i++){
        valCount[i] = 0;
    }
}
int main() {
    cin >> T;
    int a = 1;
    int maxV = -1;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                valCount[map[i][j]]++;
            }
        }
        simulation();
        cout << "#"<<a++<<" "<<sol+1 << endl;
        init();
    }

    return 0;
}