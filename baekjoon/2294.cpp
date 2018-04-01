//
// Created by vkdne on 2018-04-01.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int c[101];

int main(){
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> c[i];

    for(int i = 1; i <= n; i++) {
        if(c[i] <= 10000)
            dp[c[i]] = 1;
    }

    for(int i = 1; i <= k ; i++){
        if(dp[i] != 0) {
            for (int j = 1; j <= n; j++) {
                for (int pos = i + c[j]; pos <= k; pos += c[j]) {
                    if (dp[pos] > dp[pos - c[j]] + 1 || dp[pos] == 0) {
                        dp[pos] = dp[pos - c[j]] + 1;
                    }
                }
            }
        }
    }
    if(dp[k] == 0)
        cout <<"-1"<<endl;
    else
        cout << dp[k] << endl;

    return 0;
}