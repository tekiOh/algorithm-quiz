//
// Created by vkdne on 2018-02-01.
//
#include <iostream>
using namespace std;



int main(){
    long long dp[91][2];
    dp[1][0] = 0;
    dp[1][1] = 1;
    int N;
    cin >> N;

    for(int i = 2 ; i <= N ; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1];

    return 0;
}
