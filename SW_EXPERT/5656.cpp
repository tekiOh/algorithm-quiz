#include <iostream>
#include <queue>

using namespace std;

int map[15][12];
int T, N, W, H;
int sol = 9999;
int com[4];
//상하좌우 y++,y--,x--,x++
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
struct bomb {
    int x, y, d;
};

void simulation() {
    int nmap[15][12];
    int ball_w;
    //맵 복사후 시뮬
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            nmap[i][j] = map[i][j];
    }
    //N번 시뮬
    for (int i = 0; i < N; i++) {
        queue<bomb> q;
        ball_w = com[i];
        for (int j = 0; j < H; j++) {
            //첫 블럭을 만나면
            if (nmap[j][ball_w]) {
                //cout <<"find block at : "<< ball_w <<","<<j<<" : value "<<nmap[j][ball_w]<<endl;
                if(nmap[j][ball_w] != 1)
                    q.push({ball_w, j, nmap[j][ball_w] - 1});
                nmap[j][ball_w] = 0;
                break;
            }
        }
        //폭탄을 다 터트리고
        bomb tmp;
        int nx, ny;
        while (!q.empty()) {
            //cout <<"in queue!!"<<endl;
            tmp = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                nx = tmp.x;
                ny = tmp.y;
                //cout <<" in queue!! :"<<nx<<","<<ny<<","<<tmp.d<<endl;
                for (int k = 0; k < tmp.d; k++) {
                    nx += dx[j];
                    ny += dy[j];
                    if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                        //cout <<"find"<< nmap[ny][nx]<<"th block at : "<< nx <<","<<ny<<endl;
                        //1보다 큰 폭탄이면 큐에 넣음
                        if (nmap[ny][nx] > 1) {
                            //cout << "qeueu push :"<<nx<<","<<ny<<","<<nmap[ny][nx]<<endl;
                            q.push({nx, ny, nmap[ny][nx]-1});
                        }
                        nmap[ny][nx] = 0;
                    }
                    else {
                        break;
                    }
                }
            }
        }
//        cout <<"*******************"<<endl;
//        for (int a = 0; a < H; a++) {
//            for (int b = 0; b < W; b++) {
//                cout << nmap[a][b];
//            }
//            cout << endl;
//        }
        //이제 끌어 내리자
        for (int j = 0; j < W; j++) {
            int cnt = 0;
            bool chk = false;
            for (int k = H - 1; k > -1; k--) {
                //첫 0을 만남
                if (!chk && nmap[k][j] == 0) {
                    chk = true;
                    cnt++;
                }
                    //연속된 0
                else if (chk && nmap[k][j] == 0) {
                    cnt++;
                }
                    //0이 연속되다가 처음으로 다른거
                else if (chk && nmap[k][j] != 0) {
                    for (int l = k; l > -1; l--) {
                        nmap[l + cnt][j] = nmap[l][j];
                    }
                    for(int l = 0 ;l < cnt ; l++)
                        nmap[l][j] = 0;
                    chk = false;
                    k += cnt;
                    cnt = 0;

                }
            }
        }
//        cout <<"*******************"<<endl;
//        for (int a = 0; a < H; a++) {
//            for (int b = 0; b < W; b++) {
//                cout << nmap[a][b];
//            }
//            cout << endl;
//        }
    }

    int msol = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (nmap[i][j] != 0) {
                msol++;
            }
        }
    }
    if (sol > msol)
        sol = msol;
}

void combination(int cnt) {
    if (cnt == N) {
        simulation();

        return;
    }
    for (int i = 0; i < W; i++) {
        com[cnt] = i;
        combination(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> W >> H;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++)
                cin >> map[i][j];
        }
        combination(0);
        cout <<"#"<<a++<<" "<< sol << endl;
        sol = 9999;
    }

    return 0;
}