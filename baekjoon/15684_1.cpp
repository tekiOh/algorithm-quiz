#include <iostream>
#include <vector>
using namespace std;
int map[31][21];
int N, M, H;
int sol = -1;
vector<pair<int, int>> b;
int com[3];
bool chkMake = false;
void printMap() {
    cout << "************************************" << endl;
    cout << "1   2   3   4   5   6   7   8   9" << endl;
    for (int j = 1; j <= H; j++) {
        for (int i = 1; i < 2 * N; i++) {
            cout << map[j][i] << " ";
        }
        cout << endl;
    }
}
bool chk(pair<int, int> yx) {
    int y = yx.first;
    int x = yx.second;
    if (x + 2 < 2 * N) {
        if (map[y][x + 2] == 1 || map[y][x + 2] == 4)
            return false;
    }
    if (x - 2 > 1) {
        if (map[y][x - 2] == 1 || map[y][x - 2] == 4)
            return false;
    }
    return true;
}

void makeVisit(pair<int, int> yx) {
    int y = yx.first;
    int x = yx.second;
    map[y][x] = 4;
    if (x + 2 < 2 * N && map[y][x + 2] == 0)
        map[y][x + 2] = 2;
    if (x - 2 > 1 && map[y][x - 2] == 0)
        map[y][x - 2] = 2;
}

void initVisit(pair<int, int> yx) {
    int y = yx.first;
    int x = yx.second;
    map[y][x] = 0;
    if (x + 2 < 2 * N &&  map[y][x + 2] == 2)
        map[y][x + 2] = 0;
    if (x - 2 > 1 && map[y][x - 2] == 2)
        map[y][x - 2] = 0;
}
//내려오면서 검사
bool chkCol(int row,int col,int target_col) {
    //최종적으로 다 내려왔을때 시작점과 같은지 확인
    if (row == H + 1) {
        if (target_col == col)
            return true;
        return false;
    }
    //오른쪽
    if (col + 1 < 2 * N && map[row][col + 1] == 1 || map[row][col + 1] == 4)
        chkCol(row + 1, col + 2,target_col);

        //왼쪽
    else if (col - 1 > 1 && map[row][col - 1] == 1 || map[row][col - 1] == 4)
        chkCol(row + 1, col - 2, target_col);

    else
        chkCol(row + 1, col, target_col);

}
//시뮬레이션
//사다리 검사
bool chkLadder() {
    for (int i = 1; i < 2 * N; i += 2) {
        if (!chkCol(1,i,i)) {
            return false;
        }
    }
    return true;
}
void makeBridge(int cur, int cnt, int target) {
    //사다리 다 놓아졌으면 시뮬
    if (cnt == target) {
        //simulation
        //printMap();
        if (chkLadder()) {
            //printMap();
            sol = target;
            chkMake = true;
        }
        return;
    }
    for (int i = cur + 1; i < b.size() - target + cnt + 1 && !chkMake; i++) {
        //조건에 맞게 사다리를 놓고
        if (chk(b[i])) {
            com[cnt] = i;
            makeVisit(b[i]);
            makeBridge(i, cnt + 1, target);
            initVisit(b[i]);
        }
    }
}
void bridge() {
    //0개~3개까지
    for (int i = 0; i < 4 && !chkMake; i++) {
        makeBridge(-1, 0, i);
    }
}
int main() {
    cin >> N >> M >> H;
    int y, x;
    while (M--) {
        //입력
        cin >> y >> x;
        map[y][2 * x] = 1;
        if (2 * x + 2 < 2 * N )
            map[y][2 * x + 2] = 3;
        if (2 * x - 1 > 1)
            map[y][2 * x - 2] = 3;
    }
    //사다리 놓을수 있는곳 파악
    for (int j = 1; j <= H; j++) {
        for (int i = 2; i < 2 * N; i += 2) {
            if (map[j][i] == 0) {
                b.push_back({ j,i });
            }
        }
    }
    //사다리 놓을수 있는 곳이 없으면
    //그대로 시뮬
    if (b.empty()) {
        makeBridge(-1, 0, 0);
    }
        //printMap();
        //사다리를 놓을 수 있는 곳 있으면 0~3개 놓고 시뮬
    else
        bridge();
    cout << sol << endl;
    return 0;
}