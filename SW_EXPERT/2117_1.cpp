//
// Created by vkdne on 2018-10-14.
//

#include <iostream>
#include <queue>

using namespace std;
int T, N, M;
int sol = 1;
int home;
int map[20][20];
int visit[20][20];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs(int t) {
    int nx, ny;
    pair<int, int> tmp;
    int size = q.size();
    while (size--) {
        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmp.second + dx[i];
            ny = tmp.first + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx]) {
                visit[ny][nx] = 1;
                q.push({ny, nx});
                if (map[ny][nx] == 1)
                    home++;
            }
        }
    }
    t++;
    //손해안봤으면
    if (t * t + (t - 1) * (t - 1) <= home * M) {
        if (sol < home)
            sol = home;
    }
//    cout <<"****************************"<<endl;
//    cout <<t<<"seconds later"<<endl;
//    cout <<"benefit : "<<home*M - (t*t + (t-1)*(t-1)) <<endl;
//    for(int i = 0 ; i < N ; i++){
//        for(int j = 0 ; j < N ; j++) {
//            cout << visit[i][j] << " ";
//        }
//        cout << endl;
//    }

    if (!q.empty())
        bfs(t);
}

void sinit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            visit[i][j] = 0;
    }
    home = 0;
}

void simulation() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = 1;
            q.push({i, j});
            if (map[i][j] == 1) {
                home = 1;
            }
            bfs(1);
            sinit();
        }
    }
}

int main() {
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];
        simulation();
        cout << "#" << a++ << " " << sol << endl;
        sol = 1;
        home = 0;
    }
    return 0;
}