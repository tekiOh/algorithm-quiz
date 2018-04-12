//
// Created by vkdne on 2018-04-12.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int reception[10];	//접수 창구 당 걸리는 시간
int v_reception[10];//접수 창구 가능한지 확인하는 배열
int repair[10];		//수리 창구 당 걸리는 시간
int v_repair[10];	//수리 창구 가능한지 확인하는 배열
int sol;			//정답
struct customer {
    int c_n = -1;	//고객번호
    int a_t = -1;	//도착시간
    int reception_n = -1;	//접수 창구 번호
    int reception_st = -1;	//접수 창구 시작 시간
    int reception_et = -1;	//접수 창구 종료 시간
    int repair_n = -1;		//수리 창구 번호
    int repair_st = -1;		//수리 창구 시작 시간
};
customer customer_Array[1001];
int N, M, K, A, B;			//N : 접수창구, M : 수리창구, K : 손님수, A : 찾아야할 접수창구번호, B : 찾아야할 수리창구번호

bool checkReception() {
    for (int i = 1; i <= K; i++) {
        if (customer_Array[i].reception_st == -1)
            return false;
    }
    return true;
}
void reception_s() {
    int t = 0;
    while (1) {
        //reception 다 접수했으면
        if (checkReception()) {
            break;
        }
        //아직 reception에 접수를 다 못했으면
        for (int i = 1; i <= K; i++) {
            if (customer_Array[i].reception_st == -1 && customer_Array[i].a_t <= t) {
                for (int j = 1; j <= N; j++) {
                    //v_reception[j]를 이용할수있다면
                    if (v_reception[j] == 0) {
                        //i번째 고객, 접수창구번호, 접수 시작시간, 끝나는 시간 계산해서 넣고
                        //해당 reception은 접수 창구 시간 후에 0으로
                        customer_Array[i].reception_n = j;
                        customer_Array[i].reception_st = t;
                        customer_Array[i].reception_et = t + reception[j];
                        v_reception[j] = reception[j];
                        break;
                    }
                }
            }
        }
        //시간 증가
        t++;
        //v_reception--
        for (int j = 1; j <= N; j++) {
            if (v_reception[j] != 0) {
                v_reception[j]--;
            }
        }
    }
}

bool checkRepair() {
    for (int i = 1; i <= K; i++) {
        if (customer_Array[i].repair_st == -1)
            return false;
    }
    return true;
}
void repair_s() {
    //가장 빨리 접수를 마친 사람의 종료 시간부터 시작
    int t = customer_Array[1].reception_et;
    while (1) {
        //repair 다 접수했으면
        if (checkRepair()) {
            break;
        }
        //아직 repair에 접수를 다 못했으면
        for (int i = 1; i <= K; i++) {
            //repair 접수 못했고, 접수 끝나는 시간이 현재시간보다 빠를 때
            if (customer_Array[i].repair_st == -1 && customer_Array[i].reception_et <= t) {
                for (int j = 1; j <= M; j++) {
                    //v_repair[j]를 이용할수있다면
                    if (v_repair[j] == 0) {
                        //i번째 고객, 수리 창구 번호, 수리 시작 시간 계산해서 넣고
                        //해당 repair은 수리 창구 시간 후에 0으로
                        customer_Array[i].repair_n= j;
                        customer_Array[i].repair_st = t;
                        v_repair[j] = repair[j];
                        break;
                    }
                }
            }
        }
        //시간 증가
        t++;
        //v_repair--
        for (int j = 1; j <= M; j++) {
            if (v_repair[j] != 0) {
                v_repair[j]--;
            }
        }
    }
}
bool operator <(customer a, customer b) {
    if (a.reception_et < b.reception_et)
        return true;
    else if (a.reception_et > b.reception_et)
        return false;
    else {
        if (a.reception_n < b.reception_n)
            return true;
        else
            return false;
    }
}

void calc() {
    for (int i = 1; i <= K; i++) {
        if (customer_Array[i].reception_n == A && customer_Array[i].repair_n == B) {
            sol += customer_Array[i].c_n;
        }
    }
}

void init() {
    sol = 0;
    fill_n(v_reception, 10, 0);
    fill_n(v_repair, 10, 0);
    for (int i = 1; i <= K; i++) {
        customer_Array[i].c_n = -1;
        customer_Array[i].a_t = -1;
        customer_Array[i].reception_et = -1;
        customer_Array[i].reception_n = -1;
        customer_Array[i].reception_st = -1;
        customer_Array[i].repair_n = -1;
        customer_Array[i].repair_st = -1;
    }
}
int main() {
    int T;
    cin >> T;
    int c = 1;
    while (T--) {
        cin >> N >> M >> K >> A >> B;
        for (int i = 1; i <= N; i++)
            cin >> reception[i];
        for (int i = 1; i <= M; i++)
            cin >> repair[i];
        for (int i = 1; i <= K; i++) {
            cin >> customer_Array[i].a_t;
            customer_Array[i].c_n = i;
        }
        reception_s();
        sort(customer_Array + 1, customer_Array + K + 1);
        repair_s();
        calc();
        if (sol == 0)
            cout << "#" << c << " " << -1 << endl;

        else
            cout <<"#"<<c<<" "<<sol << endl;
        c++;
        init();
    }
    return 0;
}
