//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
using namespace std;
int arr[10];
int main(){

    int N;
    cin >>N;
    while(N){
        arr[N%10]++;
        N /= 10;
    }

    for(int i = 9 ; i > -1 ; i--){
        while(arr[i]--){
            cout << i;
        }
    }

    return 0;
}