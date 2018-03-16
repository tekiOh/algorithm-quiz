//
// Created by vkdne on 2018-03-15.
//

#include <iostream>
using namespace std;

int main(){

    long long N,K;
    while(1) {
        cin >> N >> K;

        long long sol = 1;
        int s;
        if( N == 0 && K == 0 )
            break;

        if(K < N - K)
            s = K;
        else
            s = N - K;

        for(int i = 1; i <= s ; i++){
                sol *= N;
                sol /= i;
                N--;
        }
        cout <<sol <<endl;
    }
}