//
// Created by vkdne on 2018-03-15.
//

#include <iostream>
using namespace std;

int arr[11][11];    //(N,K)
int main(){
    for(int i = 0; i <= 10 ; i++){
        arr[i][i] = 1;
        arr[i][0] = 1;
    }

    int N,K;
    cin >> N >> K;
    for(int i = 2 ; i <= N ; i++){
        for(int j = 1 ; j < i ; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    cout << arr[N][K];
}