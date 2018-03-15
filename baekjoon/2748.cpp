//
// Created by vkdne on 2018-03-15.
//

#include<iostream>
using namespace std;
long long arr[90];
int main(){
    int N;
    arr[1] = 1;
    cin >> N;
    for(int i = 2 ; i <= N; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout <<arr[N];


    return 0;
}