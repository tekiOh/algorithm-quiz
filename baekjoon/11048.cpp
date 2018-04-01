//
// Created by vkdne on 2018-04-01.
//

#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][1001][2];
int dx[3] = {1,1,0};
int dy[3] = {0,1,1};
int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j][0];
        }
    }

    dp[1][1] = arr[1][1][0];
    arr[1][1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k < 3; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (y <= N && x <= M) {
                    dp[y][x] = max(dp[y][x], (dp[i][j] + arr[y][x][0]));
                    arr[y][x][1] = 1;
                }
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}