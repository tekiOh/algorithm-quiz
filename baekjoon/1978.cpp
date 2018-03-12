//
// Created by vkdne on 2018-03-12.
//

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a;
    int sol = 0;
    bool chk;
    while(N--){
        cin >> a;
        if(a == 1){
            continue;
        }
        chk = true;
        for(int i = 2 ; i <=sqrt((double)a) ; i++){
            if(a % i == 0){
                chk = false;
                break;
            }
        }
        if(chk)
            sol++;
    }
    cout << sol;

    return 0;
}