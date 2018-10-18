//
// Created by vkdne on 2018-10-18.
//
#include <iostream>
#include <queue>

using namespace std;

int T, N, W, H;
int sol = 500;
//int map[13][13][13][13][15][12];
int map[15][12];
int nmap[15][12];
int com[4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void printMap() {
    cout << "**********************************" << endl;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

bool chkPoint(int y, int x) {
    if (y >= 0 && y < H && x >= 0 && x < W)
        return true;
    return false;
}

void findBomb(int y, int x) {
    int len = map[y][x] - 1;
    int nx, ny;
    map[y][x] = 0;
    //1~len까지
    for (int i = 1; i <= len; i++) {
        //4방향 체크
        for (int j = 0; j < 4; j++) {
            nx = x + dx[j] * i;
            ny = y + dy[j] * i;
            if (chkPoint(ny, nx)) {
                //폭탄이면!
                if (map[ny][nx] > 0)
                    findBomb(ny, nx);
                map[ny][nx] = 0;
            }
        }
    }
}

void simulation() {
    for(int i = 0 ; i < H ; i++)
        for(int j = 0 ; j < W ; j++)
            map[i][j] = nmap[i][j];

    for (int i = 0; i < N; i++) {
        //폭탄 던지고
        for (int j = 0; j < H; j++) {
            //2이상
            if (map[j][com[i]] > 0) {
                findBomb(j, com[i]);
                break;
            }
        }
        //땡기고
        for(int j = 0 ; j < W ; j++) {
            for (int k = H - 1; k > -1; k--) {
                if (map[k][j] == 0) {
                    for (int m = k - 1; m > -1; m--) {
                        if (map[m][j] > 0) {
                            map[k][j] = map[m][j];
                            map[m][j] = 0;
                            break;
                        }
                    }
                }
            }
        }
//        printMap();
    }
}

void printCom() {
    cout << "*****************" << endl;
    for (int i = 0; i < N; i++) {
        cout << com[i] << " ";
    }
    cout << endl;
}

void calc(){
    int msol = 0;
    for(int i = 0 ;i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            if(map[i][j])
                msol++;
        }
    }
//    cout << "msol : "<<msol << endl;
    if(sol > msol)
        sol = msol;
}
void makeCom(int cnt) {
    if (cnt == N) {
//        printCom();
        simulation();
        calc();
        return;
    }
    for (int i = 0; i < W; i++) {
        com[cnt] = i;
        makeCom(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> W >> H;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> nmap[i][j];
        makeCom(0);
        cout <<"#"<<a++<<" "<< sol << endl;
        sol = 500;
    }
    return 0;
}