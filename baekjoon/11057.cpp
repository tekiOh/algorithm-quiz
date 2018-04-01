//
// Created by vkdne on 2018-04-01.
//
#include <iostream>
using namespace std;
int dp[1001][10];
int main(){
    //while(1) {
        int N;
        cin >> N;
        for (int i = 0; i <= 9; i++)
            dp[1][i] = 1;
        for (int i = 0; i <= N; i++)
            dp[i][0] = 1;

        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= 9; j++) {
                int sum = 0;
                for (int k = 0; k <= j; k++) {
                    sum += dp[i - 1][k];
                }
                dp[i][j] = sum % 10007;
            }
        }

        cout << (dp[N][0] + dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4] + dp[N][5] + dp[N][6] + dp[N][7] + dp[N][8] +
                dp[N][9])%10007;

    return 0;
}
