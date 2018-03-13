//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <algorithm>

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

    sort(arr+1,arr+1+N,comp);

    for(int i = 1 ; i <= N ; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}