//
// Created by vkdne on 2018-10-14.
//

#include <iostream>

using namespace std;

int T, D, W, K;
int com[13][2];
int film[13][20];
int nfilm[13][20];
bool pass = false;
int sol = 0;

bool chk() {
    bool c;
    for (int i = 0; i < W; i++) {
        int tmp = nfilm[0][i];
        int cnt = 1;
        c = false;
        for (int j = 1; j < D; j++) {
            if (nfilm[j][i] == tmp) {
                cnt++;
            } else {
                cnt = 1;
                tmp = nfilm[j][i];
            }
            if (cnt == K) {
                c = true;
                break;
            }
        }
        if (!c)
            return false;
    }
    return true;
}

void calc(int target) {
    for (int i = 0; i < D; i++)
        for (int j = 0; j < W; j++)
            nfilm[i][j] = film[i][j];

    for (int i = 0; i < target; i++) {
        for (int j = 0; j < W; j++)
            nfilm[com[i][0]][j] = com[i][1];
    }
//    cout<<"*********************************"<<endl;
//    for (int i = 0; i < D; i++){
//        for (int j = 0; j < W; j++) {
//            cout << nfilm[i][j]<< " ";
//        }
//        cout << endl;
//    }

    if (chk()) {
        pass = true;
        //cout <<"pass!!!!!!!!!"<<endl;
        sol = target;
        return;
    }
}
void makeZeroOneCom(int cur, int target){
    if(cur == target){
//        cout <<"***********************************"<<endl;
//        for(int i = 0 ; i < target ; i++){
//            cout << com[i][0] <<"->"<<com[i][1]<<endl;
//        }
        calc(target);
        return;
    }
    com[cur][1] = 0;
    makeZeroOneCom(cur+1,target);
    com[cur][1] = 1;
    makeZeroOneCom(cur+1,target);

}
void makeCom(int cur, int cnt, int target) {
    if (cnt == target) {
//        cout << "************************"<<endl;
//        for(int i = 0 ; i < target ; i++)
//            cout << com[i][0]<<" ";
//        cout << endl;
        makeZeroOneCom(0,target);
        return;
    }
    for (int i = cur + 1; i <= D - target + cnt && !pass; i++) {
        com[cnt][0] = i;
        makeCom(i, cnt + 1, target);
    }
}

void simulation() {
    for (int i = 0; i <= K && !pass; i++) {
        makeCom(-1, 0, i);
    }
}

void init(){
    pass = false;
    sol = 0;
}

int main() {
    cin >> T;
    int a = 1;
    while (T--) {
        cin >> D >> W >> K;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> film[i][j];
            }
        }
        simulation();
        cout << "#" << a++ << " " << sol << endl;
        init();
    }

    return 0;
}