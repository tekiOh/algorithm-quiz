#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int sol = 0;
struct mapcnt{
    int arr[21][21];
    int cnt;
    void cpy(int c) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = 0;
            }
        }
        cnt = c;
    }
};

queue<mapcnt> q;

void bfs() {
    while (!q.empty()) {
        mapcnt tmp = q.front();
        q.pop();
        if (tmp.cnt == 5) {
            for(int i = 1 ; i <= N ; i++){
                for(int j = 1; j <= N ; j++){
                    if(sol < tmp.arr[i][j]) {
                        sol = tmp.arr[i][j];
                    }
                }
            }
            continue;
        }

        mapcnt left, right, up, down;
        left.cpy(tmp.cnt + 1);
        right.cpy(tmp.cnt + 1);
        up.cpy(tmp.cnt + 1);
        down.cpy(tmp.cnt + 1);
        //left
        for (int i = 1; i <= N; i++) {
            vector<int> tv;
            bool chk = true;
            for (int j = 1; j <= N; j++) {
                if (tmp.arr[i][j] != 0) {
                    if (!tv.empty()) {
                        if (tv.back() == tmp.arr[i][j]) {
                            //합칠수있을 때
                            if (chk) {
                                tv[tv.size() - 1] = (2 * tmp.arr[i][j]);
                                chk = false;
                            }
                                //합칠수없을 때
                            else {
                                tv.push_back(tmp.arr[i][j]);
                                chk = true;
                            }
                        }
                            //다를때
                        else {
                            tv.push_back(tmp.arr[i][j]);
                            chk = true;
                        }
                    } else {
                        tv.push_back(tmp.arr[i][j]);
                        chk = true;
                    }
                }
            }

            for (int k = 1; k <= tv.size(); k++) {
                left.arr[i][k] = tv[k-1];
            }
        }

        //right
        for (int i = 1; i <= N; i++) {
            vector<int> tv;
            bool chk = true;
            for (int j = N; j > 0; j--) {
                if (tmp.arr[i][j] != 0) {
                    if (!tv.empty()) {
                        if (tv.back() == tmp.arr[i][j]) {
                            //합칠수있을 때
                            if (chk) {
                                tv[tv.size() - 1] = (2 * tmp.arr[i][j]);
                                chk = false;
                            }
                                //합칠수없을 때
                            else {
                                tv.push_back(tmp.arr[i][j]);
                                chk = true;
                            }
                        }
                            //다를때
                        else {
                            tv.push_back(tmp.arr[i][j]);
                            chk = true;
                        }
                    } else {
                        tv.push_back(tmp.arr[i][j]);
                        chk = true;
                    }
                }
            }

            int a = N;
            for (int k = 0; k < tv.size() ; k++) {
                right.arr[i][a] = tv[k];
                a--;
            }
        }

        //up
        for (int i = 1; i <= N; i++) {
            vector<int> tv;
            bool chk = true;
            for (int j = 1; j <= N; j++) {
                if (tmp.arr[j][i] != 0) {
                    if (!tv.empty()) {
                        if (tv.back() == tmp.arr[j][i]) {
                            //합칠수있을 때
                            if (chk) {
                                tv[tv.size() - 1] = (2 * tmp.arr[j][i]);
                                chk = false;
                            }
                                //합칠수없을 때
                            else {
                                tv.push_back(tmp.arr[j][i]);
                                chk = true;
                            }
                        }
                            //다를때
                        else {
                            tv.push_back(tmp.arr[j][i]);
                            chk = true;
                        }
                    }
                    else {
                        tv.push_back(tmp.arr[j][i]);
                        chk = true;
                    }
                }
            }

            for (int k = 1; k <= tv.size(); k++) {
                up.arr[k][i] = tv[k-1];
            }
        }

        //down
        for (int i = 1; i <= N; i++) {
            vector<int> tv;
            bool chk = true;
            for (int j = N; j > 0; j--) {
                if (tmp.arr[j][i] != 0) {
                    if (!tv.empty()) {
                        if (tv.back() == tmp.arr[j][i]) {
                            //합칠수있을 때
                            if (chk) {
                                tv[tv.size() - 1] = (2 * tmp.arr[j][i]);
                                chk = false;
                            }
                                //합칠수없을 때
                            else {
                                tv.push_back(tmp.arr[j][i]);
                                chk = true;
                            }
                        }
                            //다를때
                        else {
                            tv.push_back(tmp.arr[j][i]);
                            chk = true;
                        }
                    } else {
                        tv.push_back(tmp.arr[j][i]);
                        chk = true;
                    }
                }
            }

            int a = N;
            for (int k = 0; k < tv.size() ; k++) {
                down.arr[i][a] = tv[k];
                a--;
            }
        }
        q.push(left);
        q.push(right);
        q.push(up);
        q.push(down);
    }
}

int main(){
    cin >> N;
    mapcnt t;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> t.arr[i][j];
        }
    }
    t.cnt = 0;
    q.push(t);
    bfs();
    cout << sol << endl;
    return 0;
}