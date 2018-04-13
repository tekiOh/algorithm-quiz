//
// Created by vkdne on 2018-04-13.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct people {
    int y;
    int x;					//초기 좌표
    int t_A = -1;			//첫번째 계단까지 걸리는 시간
    int t_B = -1;			//두번째 계단까지 걸리는 시간
    int st = 0;				//계단 내려가기 시작하는 시간
    int et = 0;				//계단을 다 내려갔을때 종료시간
};
struct stair {
    int y, x;				//계단 좌표
    int k;					//계단 길이
    int t1, t2, t3;			//계단 내려갈때까지 남은 시간
};
int map[11][11];			//맵
vector<people> pv;			//사람 벡터
vector<stair> sv;			//계단 벡터
int stairAB[10];			//어느 계단을 갈지 정하는 조합

int N;						//맵 크기
int sol;					//정답

//모든 사람들이 다 계단을 내려갔는지 체크
bool isComplete() {
    for (int i = 0; i < pv.size(); i++) {
        if (pv[i].et == -1)
            return false;
    }
    return true;
}

//첫번째 계단
void run() {
    int max = -1;
    int t = 1;
    sv[0].t1 = 0;
    sv[0].t2 = 0;
    sv[0].t3 = 0;
    while (1) {
        //완료되었으면 t반환
        if (isComplete()) {
            if (max < sol)
                sol = max;
            return;
        }
        //완료되지않았으면 계속 진행
        for (int i = 0; i < pv.size(); i++) {
            //첫번째 계단
            //도착했는데 아직 내려가지 못한 경우
            if (stairAB[i] == 1 && pv[i].st == -1 && pv[i].t_A <= t) {
                //최대 3명까지 되니까 빈 자리있으면 시작
                //없으면 시작못함
                if (sv[0].t1 == 0) {
                    sv[0].t1 = sv[0].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[0].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
                else if (sv[0].t2 == 0) {
                    sv[0].t2 = sv[0].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[0].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
                else if (sv[0].t3 == 0) {
                    sv[0].t3 = sv[0].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[0].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
            }
            //두번째 계단 도착했는데 못내려간 경우
            if (stairAB[i] == 0 && pv[i].st == -1 && pv[i].t_B <= t) {
                //최대 3명까지 되니까 빈 자리있으면 시작
                //없으면 시작못함
                if (sv[1].t1 == 0) {
                    sv[1].t1 = sv[1].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[1].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
                else if (sv[1].t2 == 0) {
                    sv[1].t2 = sv[1].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[1].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
                else if (sv[1].t3 == 0) {
                    sv[1].t3 = sv[1].k;
                    pv[i].st = t;
                    pv[i].et = t + sv[1].k;
                    if (max < pv[i].et)
                        max = pv[i].et;
                }
            }
        }
        //시간 증가, 계단 --해줌
        t++;
        if (sv[0].t1 > 0)
            sv[0].t1--;
        if (sv[0].t2 > 0)
            sv[0].t2--;
        if (sv[0].t3 > 0)
            sv[0].t3--;
        if (sv[1].t1 > 0)
            sv[1].t1--;
        if (sv[1].t2 > 0)
            sv[1].t2--;
        if (sv[1].t3 > 0)
            sv[1].t3--;
    }
}


void init() {
    for (int i = 0; i < pv.size(); i++) {
        pv[i].et = -1;
        pv[i].st = -1;
    }
}
void dfs(int max, int cnt, int target) {
    //조합을 완성하였으면
    if (cnt == target) {
        init();
        run();
        //그리고 반환
        return;
    }
    //조합이 완성되지않았으면 dfs재귀
    for (int i = max + 1; i < pv.size() - target + cnt + 1; i++) {
        stairAB[i] = 1;
        dfs(i, cnt + 1, target);
        stairAB[i] = 0;
    }
}
void makeCombination(int num) {
    fill_n(stairAB, 11, 0);
    //첫번째 계단으로 아무도 안가는 경우 바로 시뮬레이션 시작
    if (num == 0) {
        run();
    }
        //그 외의 경우 조합을 만들어줌
        //stairAB배열값이 1이면 첫번째 계단으로~ 0이면 두번째 계단으로
    else {
        for (int i = 0; i < pv.size() - num + 1; i++) {
            stairAB[i] = 1;
            dfs(i, 1, num);
            stairAB[i] = 0;
        }
    }
}
void simulation() {
    //i : 첫번째 계단으로 갈 사람 수로 조합을 만듬
    for (int i = 0; i <= pv.size(); i++) {
        makeCombination(i);
    }
}


int main() {
    int T;
    int c = 1;
    cin >> T;
    while (T--) {
        sol = 999999999;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> map[i][j];
                //사람이면 pv에 추가
                if (map[i][j] == 1) {
                    people tmp;
                    tmp.x = j;
                    tmp.y = i;
                    tmp.t_A = 0;
                    tmp.t_B = 0;
                    tmp.st = -1;
                    tmp.et = -1;
                    pv.push_back(tmp);
                }
                //계단이면 sv에 추가
                if (map[i][j] > 1) {
                    stair tmp;
                    tmp.x = j;
                    tmp.y = i;
                    tmp.k = map[i][j];
                    tmp.t1 = 0;
                    tmp.t2 = 0;
                    tmp.t3 = 0;
                    sv.push_back(tmp);
                }
            }
        }
        //사람과 계단사이의 거리를 갱신
        int dx1, dy1, dx2, dy2;
        for (int i = 0; i < pv.size(); i++) {
            dx1 = pv[i].x - sv[0].x;
            dy1 = pv[i].y - sv[0].y;
            dx2 = pv[i].x - sv[1].x;
            dy2 = pv[i].y - sv[1].y;
            if (dx1 < 0)
                dx1 = -1 * dx1;
            if (dx2 < 0)
                dx2 = -1 * dx2;
            if (dy1 < 0)
                dy1 = -1 * dy1;
            if (dy2 < 0)
                dy2 = -1 * dy2;
            pv[i].t_A = dx1 + dy1;
            pv[i].t_B = dx2 + dy2;
        }
        simulation();
        cout <<"#"<<c<<" "<< sol+1 << endl;
        c++;
        //벡터 초기화
        sv.clear();
        pv.clear();
    }
    return 0;
}

