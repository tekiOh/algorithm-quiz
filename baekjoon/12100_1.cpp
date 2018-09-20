//
// Created by vkdne on 2018-09-20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int map[20][20];
int N;
int sol = 0;
string command[4] = {"U", "D", "R", "L"};
vector<string> com;

void combination() {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    for (int e = 0; e < 4; e++) {
                        com.push_back(command[a] + command[b] + command[c] + command[d] + command[e]);
                    }
                }
            }
        }
    }
}

//y++
void up(int (&arr)[20][20]) {
    for (int j = 0; j < N; j++) {
        vector<int> v;
        bool chk = true;
        for (int i = N - 1; i > -1; i--) {
            if (arr[i][j] != 0) {
                if (v.empty()) {
                    v.push_back(arr[i][j]);
                    continue;
                }
                //끝이랑 같으면
                if (chk && v[v.size() - 1] == arr[i][j]) {
                    v[v.size() - 1] *= 2;
                    if(v[v.size() - 1] > sol)
                        sol = v[v.size() - 1];
                    chk = false;
                }
                    //다르면
                else {
                    v.push_back(arr[i][j]);
                    chk = true;
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            arr[N - i - 1][j] = v[i];
        }
        for (int i = v.size(); i < N; i++)
            arr[N - i - 1][j] = 0;
    }
}

//y--
void down(int (&arr)[20][20]) {
    for (int j = 0; j < N; j++) {
        vector<int> v;
        bool chk = true;
        for (int i = 0; i < N; i++) {
            if (arr[i][j] != 0) {
                if (v.empty()) {
                    v.push_back(arr[i][j]);
                    continue;
                }
                //끝이랑 같으면
                if (chk && v[v.size() - 1] == arr[i][j]) {
                    v[v.size() - 1] *= 2;
                    if(v[v.size() - 1] > sol)
                        sol = v[v.size() - 1];
                    chk = false;
                }
                    //다르면
                else {
                    v.push_back(arr[i][j]);
                    chk = true;
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            arr[i][j] = v[i];
        }
        for (int i = v.size(); i < N; i++)
            arr[i][j] = 0;
    }
}

//x++
void right(int (&arr)[20][20]) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool chk = true;
        for (int j = N - 1; j > -1; j--) {
            if (arr[i][j] != 0) {
                if (v.empty()) {
                    v.push_back(arr[i][j]);
                    continue;
                }
                //끝이랑 같으면
                if (chk && v[v.size() - 1] == arr[i][j]) {
                    v[v.size() - 1] *= 2;
                    if(v[v.size() - 1] > sol)
                        sol = v[v.size() - 1];
                    chk = false;
                }
                    //다르면
                else {
                    v.push_back(arr[i][j]);
                    chk = true;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            arr[i][N - j - 1] = v[j];
        }
        for (int j = v.size(); j < N; j++)
            arr[i][N - j - 1] = 0;
    }
}

//x--
void left(int (&arr)[20][20]) {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool chk = true;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != 0) {
                if (v.empty()) {
                    v.push_back(arr[i][j]);
                    continue;
                }
                //끝이랑 같으면
                if (chk && v[v.size() - 1] == arr[i][j]) {
                    v[v.size() - 1] *= 2;
                    if(v[v.size() - 1] > sol)
                        sol = v[v.size() - 1];
                    chk = false;
                }
                    //다르면
                else {
                    v.push_back(arr[i][j]);
                    chk = true;
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            arr[i][j] = v[j];
        }
        for (int j = v.size(); j < N; j++)
            arr[i][j] = 0;
    }
}

void calc(int (& arr)[20][20]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(sol < arr[i][j])
                sol = arr[i][j];
        }
    }
}

void move() {
    int nmap[20][20];

    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                nmap[j][k] = map[j][k];
            }
        }
        for (int j = 0; j < 5; j++) {
            if (com[i][j] == 'U') {
                up(nmap);
            } else if (com[i][j] == 'D') {
                down(nmap);
            } else if (com[i][j] == 'R') {
                right(nmap);
            } else {
                left(nmap);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(sol < map[i][j])
                sol = map[i][j];
        }
    }

    combination();
    move();
    cout << sol << endl;
    return 0;
}