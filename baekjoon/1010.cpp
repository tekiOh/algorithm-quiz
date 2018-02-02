//
// Created by vkdne on 2018-02-02.
//

#include <iostream>
using namespace std;

int dp[31][31];

int main(){
    for(int i = 0 ; i <31 ; i++) {
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    for(int i = 2; i < 31 ; i++){
        for(int j = 1 ; j != i ; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    int T;
    cin >> T;
    int a,b;
    while(T--){
            cin >> a >> b;
            if(a >= b){
                cout << dp[a][b] << endl;
            }
            else{
                cout << dp[b][a] << endl;
            }
    }
    return 0;
}