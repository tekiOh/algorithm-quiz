//
// Created by vkdne on 2018-02-02.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main(){
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            dp[i] = 1;
            cin >> arr[i];
        }
        int sol = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            sol = max(sol, dp[i]);
        }
        cout << sol << endl;

    return 0;
}