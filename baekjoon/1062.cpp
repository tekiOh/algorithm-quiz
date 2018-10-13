//
// Created by vkdne on 2018-10-13.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, K;
int visit[50][26];
int chk[26];
vector<int> combination;
int c[26];
int sol = 0;
vector<int> v;

void calc() {
    combination.clear();
    combination = {0,2,8,13,19};
    for(int i = 0 ; i < K - 5 ; i++)
        combination.push_back(c[i]);
    sort(combination.begin(),combination.end());
//    cout << "*****************************"<<endl;
//    for(int i = 0 ; i < K ; i++){
//        cout << (char)(combination[i]+97)<<" ";
//    }
//    cout << endl;
    int msol = 0;
    for (int i = 0; i < N; i++) {
        int idx = 0;
        bool chk = true;
        for (int j = 0; j < 26; j++) {
            if (combination[idx] == j) {
                idx++;
                continue;
            }
            if (visit[i][j] != 0) {
                chk = false;
                break;
            }

        }
        if (chk)
            msol++;
    }

   // cout << "msol : " << msol << endl;



    if (sol < msol)
        sol = msol;
}

void comb(int cur, int cnt) {
    if (cnt == K - 5) {
        calc();
        return;
    }
    for (int i = cur + 1; i < v.size() - K + 5 + cnt + 1; i++) {
        c[cnt] = v[i];
        comb(i, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    string tmp = "acinrt";
    cin >> N >> K;
    //최소개수도 못가르치면 0개
    if (K < 5) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            visit[i][tmp[j] - 97] = 1;
            chk[tmp[j] - 97] = 1;
        }
    }
    //cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    for (int i = 0; i < 26; i++) {
        if (chk[i] &&i != 0 && i != 2 && i != 8 && i != 13 && i != 19) {
            v.push_back(i);
            //cout << (char)(i+97) << endl;
        }
    }

    //필요한거 이상으로 가르칠수있으면 N개
    if (v.size() + 5 <= K) {
        cout << N << endl;
        return 0;
    }

    comb(-1, 0);
    cout << sol << endl;
    return 0;
}