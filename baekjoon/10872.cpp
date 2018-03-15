//
// Created by vkdne on 2018-03-15.
//

#include <iostream>
using namespace std;
int arr[13];
int main(){
    arr[0] = 1;
    arr[1] = 1;
    int N;
    cin >> N;
    for(int i = 2 ; i <= N ; i++)
        arr[i] = arr[i-1] * i;

    cout << arr[N];

}