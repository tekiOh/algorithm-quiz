//
// Created by vkdne on 2018-03-13.
//
#include <iostream>

using namespace std;
int arr[10001];
int main(){
    int N;
    cin >> N;
    int a;

    for(int i = 1 ; i <= N ; i++){
        cin >> a;
        arr[a]++;
    }

    for(int i = 1 ; i <= 10000 ; i++){
        for(int j = 1 ; j <= arr[i] ; j++)
            cout << i << '\n';
    }
    return 0;
}