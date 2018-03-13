//
// Created by vkdne on 2018-03-12.
//
//
// Created by vkdne on 2018-03-12.
//

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    while(1) {
        int M;
        cin >> M;
        if(M == 0)
            break;
        bool chk;
        int sol = 0;
        for (int i = M + 1; i <= 2 * M; i++) {
            chk = true;
            if (i == 1)
                continue;
            for (int j = 2; j <= sqrt((double) i); j++) {
                if (i % j == 0) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                sol++;
            }
        }
        cout << sol << '\n';
    }
    return 0;
}