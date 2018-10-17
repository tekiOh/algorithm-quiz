//
// Created by vkdne on 2018-10-17.
//

#include <iostream>
#include <vector>

using namespace std;

int map[11][11][8]; //[y][x][BC] x,y에 BC가 영향을 끼치는지?
int BC[8][4];   //충전기 좌표(x,y), 충전범위(c), 충전용량(p)
int moveA[101];
int moveB[101];
int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};
int T, M, A, sol;


void simulation() {
    int aX = 1;
    int aY = 1;
    int bX = 10;
    int bY = 10;
    //시작점도 이동으로 간주하고 (안움직임) M+1번 시뮬레이션
    for (int i = 0; i <= M; i++) {
        vector<int> aBC, bBC;
        //이동
        aX += dx[moveA[i]];
        aY += dy[moveA[i]];
        bX += dx[moveB[i]];
        bY += dy[moveB[i]];
        //갈수있는 BC 목록 만들고
        for (int j = 0; j < 8; j++) {
            if (map[aY][aX][j])
                aBC.push_back(j);
            if (map[bY][bX][j])
                bBC.push_back(j);
        }
        //최적의 경우를 구하자
        int msol = 0;
        //둘다 없어
        if (aBC.empty()&& bBC.empty()) {
        }
            //B만 충전가능!
        else if (aBC.empty() && !bBC.empty()) {
            for (int j = 0; j < bBC.size(); j++) {
                if (msol < BC[bBC[j]][3])
                    msol = BC[bBC[j]][3];
            }
        }
            //A만 충전가능!
        else if (!aBC.empty() && bBC.empty()) {
            for (int j = 0; j < aBC.size(); j++) {
                if (msol < BC[aBC[j]][3])
                    msol = BC[aBC[j]][3];
            }
        }
            //둘다 충전가능!
        else {
            for (int j = 0; j < aBC.size(); j++) {
                for (int k = 0; k < bBC.size(); k++) {
                    //같으면 하나!
                    if (aBC[j] == bBC[k]) {
                        if (msol < BC[aBC[j]][3])
                            msol = BC[aBC[j]][3];
                    } else {
                        if (msol < BC[aBC[j]][3] + BC[bBC[k]][3])
                            msol = BC[aBC[j]][3] + BC[bBC[k]][3];
                    }
                }
            }
        }
        //cout <<i<<"seconds :"<<msol<<endl;
        sol += msol;
    }
}

void init() {
    //map[11][11][8]
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            for (int k = 0; k < A; k++)
                map[i][j][k] = 0;

    sol = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> M >> A;
        for (int i = 1; i <= M; i++)
            cin >> moveA[i];
        for (int i = 1; i <= M; i++)
            cin >> moveB[i];
        for (int i = 0; i < A; i++)
            cin >> BC[i][0] >> BC[i][1] >> BC[i][2] >> BC[i][3];
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                for (int k = 0; k < A; k++) {
                    //범위에 속하면 체크
                    if (abs(BC[k][0] - j) + abs(BC[k][1] - i) <= BC[k][2])
                        map[i][j][k]++;
                }
            }
        }
        simulation();
        cout << "#" << a++ << " " << sol << endl;
        init();
    }

    return 0;
}