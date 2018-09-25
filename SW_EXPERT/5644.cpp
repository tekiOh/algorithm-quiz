//
// Created by vkdne on 2018-09-18.
//

#include <iostream>
#include <vector>

using namespace std;

struct info {
    int x, y, c, p; //(x,y), 범위, 파워
};
int M, N; //이동시간, BC개수
vector<pair<int, int>> A;    //A 이동경로
vector<pair<int, int>> B;    //B 이동경로
vector<info> BC;             //BC 정보

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};

int sol = 0;

void findBC(int ay, int ax, int by, int bx) {
    vector<int> resultA;
    vector<int> resultB;
    for (int i = 0; i < BC.size(); i++) {
        if (BC[i].c >= abs((BC[i].x - ax)) + abs((BC[i].y - ay)))
            resultA.push_back(i);
        if (BC[i].c >= abs((BC[i].x - bx)) + abs((BC[i].y - by)))
            resultB.push_back(i);
    }
    int a = resultA.size();
    int b = resultB.size();

    int max = 0;
    if (a == 0 && b == 0)
        return;
    else if (a == 0 && b != 0) {
        for (int i = 0; i < b; i++) {
            if (max < BC[resultB[i]].p)
                max = BC[resultB[i]].p;
        }
        sol += max;
    } else if (a != 0 && b == 0) {
        for (int i = 0; i < a; i++) {
            if (max < BC[resultA[i]].p)
                max = BC[resultA[i]].p;
        }
        sol += max;
    } else {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (resultA[i] == resultB[j]) {
                    if (max < BC[resultA[i]].p)
                        max = BC[resultA[i]].p;
                } else {
                    if (max < BC[resultA[i]].p + BC[resultB[j]].p)
                        max = BC[resultA[i]].p + BC[resultB[j]].p;
                }
            }
        }
        sol += max;
    }
    //cout << max << endl;
}

void calc() {
    int ax, ay, bx, by;
    for (int i = 0; i <= M; i++) {
        ay = A[i].first;
        ax = A[i].second;
        by = B[i].first;
        bx = B[i].second;
        findBC(ay, ax, by, bx);
    }
}

//void print() {
//    cout << "******************" << endl;
//    cout << "A" << endl;
//    for (int i = 0; i < A.size(); i++) {
//        cout << A[i].first << "," << A[i].second << endl;
//    }
//    cout << "B" << endl;
//    for (int i = 0; i < B.size(); i++) {
//        cout << B[i].first << "," << B[i].second << endl;
//    }
//    cout << "BC" << endl;
//    for (int i = 0; i < BC.size(); i++) {
//        cout << BC[i].y << "," << BC[i].x << "," << BC[i].c << "," << BC[i].p << endl;
//    }
//}

void input() {
    int move;
    cin >> M >> N;
    A.emplace_back(make_pair(1, 1));
    B.emplace_back(make_pair(10, 10));
    int ax = 1;
    int ay = 1;
    int bx = 10;
    int by = 10;
    for (int i = 0; i < M; i++) {
        cin >> move;
        ax += dx[move];
        ay += dy[move];
        A.emplace_back(make_pair(ay, ax));
    }
    for (int i = 0; i < M; i++) {
        cin >> move;
        bx += dx[move];
        by += dy[move];
        B.emplace_back(make_pair(by, bx));
    }

    int x, y, c, p;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> c >> p;
        BC.push_back({x, y, c, p});
    }
    //print();
}

void init() {
    sol = 0;
    vector<pair<int, int>> nA;    //A 이동경로
    vector<pair<int, int>> nB;    //B 이동경로
    vector<info> nBC;             //BC 정보
    A.swap(nA);
    B.swap(nB);
    BC.swap(nBC);
}

int main() {
    vector<int> answer;
    int T;
    cin >> T;
    int cnt = 1;
    while (T--) {
        input();
        calc();
        cout <<"#"<<cnt<<" "<< sol << endl;
        answer.push_back(sol);
        init();
        cnt++;
    }
    return 0;
}