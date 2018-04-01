//
// Created by vkdne on 2018-03-31.
//
#include <iostream>
#include <math.h>
using namespace std;
int price[1001];
int dp[1001];
int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N ; i++)
        cin >> price[i];

    for(int i = 1; i <= N ; i++){
        int a = 0;
        for(int j = 0 ; j < i ; j++){
            if(a < dp[j] + price[i-j])
                a = dp[j] + price[i-j];
        }
        dp[i] = a;
    }

    cout << dp[N] << endl;
    return 0;
}