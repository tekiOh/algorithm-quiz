//
// Created by vkdne on 2018-03-31.
//
#include <iostream>
using namespace std;
int arr[301][301];
int dp[301][301];
int main(){
    int N,M;
    int sum = 0;
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + sum;
            sum += arr[i][j];
        }
    }
    int K;
    cin >> K;
    while(K--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int sol = 0;
        for(int i = a ; i <= c ; i++){
            sol += (dp[i][d] - dp[i][b] + arr[i][b]);
        }
        cout << sol << endl;
    }

    return 0;
}
