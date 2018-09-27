//
// Created by vkdne on 2018-09-27.
//

#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int x, y, d, g;

void calc() {
    vector<pair<int, int>> v; //y,x
    //1세대
    v.emplace_back(make_pair(y, x));
    v.emplace_back(make_pair(y + dy[d], x + dx[d]));
    map[y][x] = 1;
    map[y + dy[d]][x + dx[d]] = 1;
//    cout <<0<<"th generation"<<endl;
//    for(int k = 0 ; k < 10  ; k++){
//        for(int h = 0 ; h < 10 ; h++){
//            cout << map[k][h];
//        }
//        cout << endl;
//    }
    //다음 세대를 그림
    int sx, sy, dx1, dy1, nx, ny, size;
    for (int i = 1; i <= g; i++) {
        int size = v.size();
        sx = v[size - 1].second;
        sy = v[size - 1].first;
        for (int j = size - 2; j > -1; j--) {
            dx1 = sx - v[j].second;
            dy1 = sy - v[j].first;
            nx = sx + dy1;
            ny = sy - dx1;
            map[ny][nx] = 1;
            v.emplace_back(make_pair(ny,nx));
        }
//        cout <<i<<"th generation"<<endl;
//        for(int k = 0 ; k < 10  ; k++){
//            for(int h = 0 ; h < 10 ; h++){
//                cout << map[k][h];
//            }
//            cout << endl;
//        }
    }
}

int findSol(){
    int sol = 0;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1)
                sol++;
        }
    }
    return sol;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        calc();
    }
    cout << findSol() << endl;
    return 0;
}