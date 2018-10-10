#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt;
int sol;
int visit[4001][4001];
int cvisit[4001][4001];

struct atom {
    int x, y, k, d;    //x,y좌표,에너지,방향
    bool crash;

    atom(int _x, int _y, int _k, int _d, bool _crash) {
        x = _x;
        y = _y;
        k = _k;
        d = _d;
        crash = _crash;
    }
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<atom> atoms;

bool chkPoint(int x, int y) {
    if (x >= 0 && x <= 4000 && y >= 0 && y <= 4000)
        return true;
    return false;
}

void move() {
    int nx, ny;
    //cout << "**********************" << endl;
    for (int i = 0; i < N; i++) {
        if (!atoms[i].crash) {
            nx = atoms[i].x + dx[atoms[i].d];
            ny = atoms[i].y + dy[atoms[i].d];
            //cout << nx << "," << ny << endl;
            if (chkPoint(nx, ny)) {
                visit[atoms[i].y][atoms[i].x]--;
                visit[ny][nx]++;

                if (visit[ny][nx] > 1) {
                    cvisit[ny][nx] = 1;
                    //cout << "crach at " << ny << "," << nx <<":"<<atoms[i].k<< endl;
                }
                atoms[i].y = ny;
                atoms[i].x = nx;
            } else {
                //cout << "out of bound at " << ny << "," << nx << endl;
                atoms[i].crash = true;
                visit[atoms[i].y][atoms[i].x]--;
                cnt++;
            }
        }
    }
}

void crashCheck() {
    for (int i = 0; i < N ; i++) {
        if(!atoms[i].crash) {
            if (cvisit[atoms[i].y][atoms[i].x] == 1) {
                sol += atoms[i].k;
                cnt++;
                atoms[i].crash = true;
                visit[atoms[i].y][atoms[i].x]--;
                if (visit[atoms[i].y][atoms[i].x] == 0)
                    cvisit[atoms[i].y][atoms[i].x] = 0;
            }
        }
    }
}

void simulation() {
    while (cnt != N) {
        move();
        crashCheck();
    }
}

void init() {
    cnt = 0;
    sol = 0;
    atoms.clear();
}

int main() {
    int T, x, y, k, d;  //테케수, x,y좌표,에너지,방향
    int a = 1;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> d >> k;
            atoms.emplace_back(atom(2 * (x + 1000), 2 * (y + 1000), k, d, false));
            visit[2 * (y + 1000)][2 * (x + 1000)]++;
        }
//        for (int i = 0; i < N; i++) {
//            cout << atoms[i].x << atoms[i].y << endl;
//        }
        simulation();
        cout << "#" << a << " " << sol << endl;
        init();
        a++;
    }

    return 0;
}