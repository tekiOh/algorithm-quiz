//
// Created by vkdne on 2018-09-25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int N, M;
int map[8][8];
string darr[6][4] = {{},
                     {"R",   "L" ,"U", "D"},
                     {"RL",  "UD"},
                     {"UR",  "UL",  "DR",  "DL"},
                     {"URL", "UDR", "UDL", "DRL"},
                     {"UDRL"}};

struct pos {
    int y, x, t;
};
vector<pos> camera;
string d[8];
int cnt;
int sol = 999999;

int getSize(int i) {
    if (i == 2)
        return 2;
    else if (i == 3 || i == 4 || i == 1)
        return 4;
    else
        return 1;
}

void Up(int x, int y) {
    while (1) {
        y++;
        if (y >= 0 && y < N && map[y][x] != 6) {
            if (map[y][x] == 0)
                map[y][x] = 7;
        } else
            break;
    }
}

void Down(int x, int y) {
    while (1) {
        y--;
        if (y >= 0 && y < N && map[y][x] != 6) {
            if (map[y][x] == 0)
                map[y][x] = 7;
        } else
            break;
    }
}

void Left(int x, int y) {
    while (1) {
        x--;
        if (x >= 0 && x < M && map[y][x] != 6) {
            if (map[y][x] == 0)
                map[y][x] = 7;
        } else
            break;
    }
}

void Right(int x, int y) {
    while (1) {
        x++;
        if (x >= 0 && x < M && map[y][x] != 6) {
            if (map[y][x] == 0)
                map[y][x] = 7;
        } else
            break;
    }
}

void calc() {
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < d[i].size(); j++) {
            switch (d[i][j]) {
                case 'U':
                    Up(camera[i].x, camera[i].y);
                    break;
                case 'D':
                    Down(camera[i].x, camera[i].y);
                    break;
                case 'L':
                    Left(camera[i].x, camera[i].y);
                    break;
                case 'R':
                    Right(camera[i].x, camera[i].y);
                    break;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                count++;
            } else if (map[i][j] == 7)
                map[i][j] = 0;
        }
    }
    if (sol > count) {
        sol = count;
//        cout << "****sol****"<<endl;
//        cout << sol << endl;
    }
}

void dfs(int cur) {
    if (cur == cnt - 1) {
        //계산
        calc();
        return;
    }
    for (int i = 0; i < getSize(camera[cur + 1].t); i++) {
//        cout << "**************************"<<endl;
//        cout <<"["<<cur+2<<"]"<<camera[cur + 1].t << endl;
//        cout << darr[camera[cur + 1].t][i] << endl;
        d[cur + 1] = darr[camera[cur + 1].t][i];
        dfs(cur + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6) {
                camera.push_back({i, j, map[i][j]});
                cnt++;
            }
        }
    }
    if(camera.empty()){
        int t = 0;
        for(int i = 0 ;i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(map[i][j] == 0)
                    t++;
            }
        }
        cout << t << endl;
        return 0;
    }
    for (int i = 0; i < getSize(camera[0].t); i++) {
//        cout << "**************************"<<endl;
//        cout << "[1]"<<camera[0].t<<endl;
//        cout << darr[camera[0].t][i] << endl;
        d[0] = darr[camera[0].t][i];
        dfs(0);
    }
    cout << sol << endl;
    return 0;
}