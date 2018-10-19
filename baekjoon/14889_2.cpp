//
// Created by vkdne on 2018-10-19.
//

#include <iostream>
using namespace std;
int N;
int sol = 99999999;
int s[20][20];
int com[20];
int t1[10];
int t2[10];
void calc() {
    int cnt1 = 0;
    int cnt2 = 0;
    int t1_s = 0;
    for (int i = 0; i < N; i++) {
        if (!com[i]){
            t1[cnt1] = i;
            cnt1++;
        }
        else {
            t2[cnt2] = i;
            cnt2++;
        }
    }
    for (int i = 0; i < N / 2 - 1; i++) {
        for (int j = i + 1; j < N / 2; j++) {
            t1_s += s[t1[i]][t1[j]];
            t1_s += s[t1[j]][t1[i]];
            t1_s -= s[t2[i]][t2[j]];
            t1_s -= s[t2[j]][t2[i]];
        }
    }
    t1_s = abs(t1_s);
    if (sol > t1_s)
        sol = t1_s;
}

void dfs(int cur, int cnt) {
    if (cnt == N / 2) {
        /*cout << "**********************" << endl;
        for (int i = 0; i < N; i++) {
            cout << com[i] << " ";
        }
        cout << endl;*/
        calc();
        return;
    }
    for (int i = cur + 1; i < N / 2 + cnt + 1; i++) {
        com[i] = 1;
        dfs(i, cnt + 1);
        com[i] = 0;
    }
}
void makeTeam() {
    com[0] = 1;
    dfs(0, 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s[i][j];
        }
    }
    makeTeam();
    cout << sol << '\n';
    return 0;
}