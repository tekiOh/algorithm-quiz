#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M,sol;	//세로 가로
int map[8][8];
int visit[8][8];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<int, int>> w;
vector<pair<int, int>> v;

void printMap() {
    cout << "*****************************" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

}
void bfs() {
    queue<pair<int, int>> q;
    pair<int, int> tmp;
    int nx, ny;
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
        visit[v[i].first][v[i].second] = 1;
    }
    //printMap();
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            nx = tmp.second + dx[i];
            ny = tmp.first + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visit[ny][nx] && map[ny][nx] == 0) {
                map[ny][nx] = 3;
                visit[ny][nx] = 1;
                q.push({ ny,nx });
            }
        }
    }
    //printMap();
}

void countVirus() {
    int msol = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0)
                msol++;
            else if (map[i][j] == 3)
                map[i][j] = 0;
        }
    }
    if (sol < msol)
        sol = msol;
}

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visit[i][j] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                w.push_back({ i,j });
            else if (map[i][j] == 2)
                v.push_back({ i,j });
        }
    }
    for (int i = 0; i < w.size() - 2; i++) {
        for (int j = i + 1; j < w.size() - 1; j++) {
            for (int k = j + 1; k < w.size(); k++) {
                map[w[i].first][w[i].second] = 1;
                map[w[j].first][w[j].second] = 1;
                map[w[k].first][w[k].second] = 1;
                bfs();
                countVirus();
                init();
                map[w[i].first][w[i].second] = 0;
                map[w[j].first][w[j].second] = 0;
                map[w[k].first][w[k].second] = 0;
            }
        }
    }
    cout << sol << endl;
    return 0;

}