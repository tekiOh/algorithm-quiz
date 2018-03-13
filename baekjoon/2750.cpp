//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001];
int main(){

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    sort(&arr[1], &arr[N+1]);

    for(int i = 1; i <= N; i++){
        cout << arr[i] << '\n';
    }



    return 0;
}