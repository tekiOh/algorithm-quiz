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
    int M,N;
    cin >> M >> N;
    bool chk;
    for(int i = M ; i <= N ; i++){
        chk = true;
        if(i == 1)
            continue;
        for(int j = 2 ; j <= sqrt((double)i) ; j++){
            if(i%j == 0){
                chk = false;
                break;
            }
        }
        if(chk){
            cout << i << '\n';
        }
    }

    return 0;
}