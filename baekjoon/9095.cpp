#include <iostream>
using namespace std;
int dp[11];

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4 ; i <11 ; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    int N;
    int c;
    cin >> N;
    while(N--){
        cin >> c;
        cout<<dp[c] << endl;
    }
    return 0;
}