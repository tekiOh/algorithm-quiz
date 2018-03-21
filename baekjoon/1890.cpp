//
// Created by vkdne on 2018-03-21.
//
#include <iostream>
using namespace std;
int arr[101][101];
long long dp[101][101];
int main(){
    int N;
    cin >> N;

    for(int i = 1; i <= N ; i++){
        for(int j = 1; j <= N ; j++)
            cin >> arr[i][j];
    }
    dp[1][1] = 1;
    int ni;
    int nj;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N; j++){
            if(i == N && j == N)
                break;
            if(dp[i][j] != 0) {
                ni = i + arr[i][j];
                nj = j;
                if (ni <= N)
                    dp[ni][nj]+=dp[i][j];
                ni = i;
                nj = j + arr[i][j];
                if (nj <= N)
                    dp[ni][nj]+=dp[i][j];
            }
        }
    }
    cout <<dp[N][N];
    return 0;
}