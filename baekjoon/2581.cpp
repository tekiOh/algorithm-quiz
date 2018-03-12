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
    int min = 10001;
    int sum = 0;
    int cnt = 0;
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
            sum += i;
            cnt++;
            if(min > i)
                min = i;
        }
    }

    if(cnt == 0)
        cout<<"-1";
    else{
        cout<<sum<<endl;
        cout<<min<<endl;
    }

    return 0;
}