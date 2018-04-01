//
// Created by vkdne on 2018-04-01.
//
#include <iostream>
using namespace std;
int dp[301][301];
int main(){
    int N,M;
    cin >> N >> M;
    dp[1][1] = 0;
    for(int i = 1 ; i <= N ; i++)
        dp[i][1] = i-1;
    for(int i = 1 ; i <= M ; i++)
        dp[1][i] = i-1;
    for(int i = 2; i <= N ; i++){
        for(int j = 2 ; j <= M ; j++){
            dp[i][j] = i*dp[1][j] + i-1;
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}