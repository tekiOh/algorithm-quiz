//
// Created by vkdne on 2018-09-24.
//
#include <iostream>

using namespace std;

int arr[16][2]; //[0] : t, [1] : p
int N;
int sol;

void dfs(int current, int to, int profit) {
    bool chk = false;
    for (int i = current + 1; i <= N; i++) {
        if (to < i && arr[i][0] + i - 1 <= N) {
            chk = true;
            dfs(i, i + arr[i][0] - 1, profit + arr[i][1]);
        }
    }
    if (!chk) {
        if (sol < profit)
            sol = profit;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i + 1][0] >> arr[i + 1][1];

    for (int i = 1; i <= N; i++) {
        if (arr[i][0] + i - 1 <= N) {
            dfs(i, i + arr[i][0] - 1, arr[i][1]);
        }
    }
    cout << sol << endl;
    return 0;
}