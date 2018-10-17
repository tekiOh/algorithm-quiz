#include <iostream>
using namespace std;

int map[20][20];
int visit[20];
int T, N, X, sol;

void simulation() {
    int H, c;
    //가로부터 검사!
    for (int i = 0; i < N; i++) {
        bool chk = true;
        H = map[i][0];
        c = 1;
        for (int j = 1; j < N; j++) {
            if (map[i][j] == H) {
                c++;
                continue;
            }
                //앞이 더 높은 경우 -> 뒤에 경사로를 설치해야함 -> 뒤를 검사
            else if (map[i][j] == H + 1) {
                //경사로를 놓을 수 있음
                if (c >= X) {
                    for (int k = j - 1; k > j - X - 1; k--) {
                        visit[k] = 1;
                    }
                    H = map[i][j];
                    c = 1;
                }
                    //경사로 놓을 수 없음
                else {
                    chk = false;
                    break;
                }
            }
            //앞이 더 낮은 경우 -> 앞에 경사로를 설치해야함 -> 앞을 검사
            else if (map[i][j] == H - 1) {
                bool front = true;
                int tmp = map[i][j];
                //앞에 경사로를 설치할 공간이 있을 때
                if (j + X - 1 < N) {
                    for (int k = j + 1; k < j + X; k++) {
                        if (tmp != map[i][k]) {
                            front = false;
                            break;
                        }
                    }
                    if (front) {
                        for (int k = j; k < j + X; k++) {
                            visit[k] = 1;
                        }
                        j += X - 1;
                        if (j + 1 < N) {
                            H = map[i][j];
                            c = 0;
                        }
                    } else {
                        chk = false;
                        break;
                    }
                }
                else{
                    chk = false;
                    break;
                }
            }
            else{
                chk = false;
                break;
            }
        }
        for (int j = 0; j < N; j++)
            visit[j] = 0;
        if (chk)
            sol++;
    }
    //세로 검사!
    for (int i = 0; i < N; i++) {
        bool chk = true;
        H = map[0][i];
        c = 1;
        for (int j = 1; j < N; j++) {
            if (map[j][i] == H) {
                c++;
                continue;
            }
                //앞이 더 높은 경우 -> 뒤에 경사로를 설치해야함 -> 뒤를 검사
            else if (map[j][i] == H + 1) {
                //경사로를 놓을 수 있음
                if (c >= X) {
                    for (int k = j - 1; k > j - X - 1; k--) {
                        visit[k] = 1;
                    }
                    H = map[j][i];
                    c = 1;
                }
                //경사로 놓을 수 없음
                else {
                    chk = false;
                    break;
                }
            }
            //앞이 더 낮은 경우 -> 앞에 경사로를 설치해야함 -> 앞을 검사
            else if(map[j][i] == H - 1){
                bool front = true;
                int tmp = map[j][i];
                //앞에 경사로를 설치할 남은 자리가 있고 높이가 같을 때
                if (j + X - 1 < N) {
                    for (int k = j + 1; k < j + X; k++) {
                        if (tmp != map[k][i]) {
                            front = false;
                            break;
                        }
                    }
                    if (front) {
                        for (int k = j; k < j + X; k++) {
                            visit[k] = 1;
                        }
                        j += X - 1;
                        H = map[j][i];
                        c = 0;
                    } else {
                        chk = false;
                        break;
                    }
                } else {
                    chk = false;
                    break;
                }
            }
            else{
                chk = false;
                break;
            }
        }
        for (int j = 0; j < N; j++)
            visit[j] = 0;
        if (chk)
            sol++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cin >> map[i][j];
        }
        simulation();
        cout << "#" << a++ << " " << sol << '\n';
        sol = 0;
    }
    return 0;
}
