//
// Created by vkdne on 2018-09-24.
//

#include <iostream>
#include <vector>

using namespace std;
int N;
int s[21][21];
int visit[21];
int sol = 99999999;

void calc() {
    vector<int> t1;
    vector<int> t2;
    for (int i = 1; i <= N; i++) {
        if (visit[i])
            t1.push_back(i);
        else
            t2.push_back(i);
    }
    int s1 = 0;
    for (int i = 0; i < N / 2 - 1; i++) {
        for (int j = i + 1; j <= N / 2 - 1; j++) {
            s1 += s[t1[i]][t1[j]];
            s1 += s[t1[j]][t1[i]];
            s1 -= s[t2[i]][t2[j]];
            s1 -= s[t2[j]][t2[i]];
        }
    }
    if (sol > abs(s1))
        sol = abs(s1);
}

void dfs(int current, int cnt) {
    if (cnt == N / 2) {
        //계산!
        calc();
       // cout << "calc" << endl;
        return;
    }
    for (int i = current + 1; i <= N / 2 + cnt + 1; i++) {
        visit[i] = 1;
        dfs(i, cnt + 1);
        visit[i] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> s[i][j];
    }
    for (int i = 1; i <= N / 2 + 1; i++) {
        visit[i] = 1;
        dfs(i, 1);
        visit[i] = 0;
    }
    cout << sol << endl;
    return 0;
}