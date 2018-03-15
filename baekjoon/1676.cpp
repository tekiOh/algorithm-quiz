//
// Created by vkdne on 2018-03-15.
//

#include <iostream>
using namespace std;
long long arr[501][2];
int main(){
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 0;

    int N;
    cin  >> N;

    for(int i = 2 ; i <= N ; i++){
        int a = 0;  //2의 개수
        int b = 0;  //5의 개수
        int k = i;
        while(1){
            if(k % 2 == 0){
                a++;
                k /= 2;
            }
            else
                break;
        }

        while(1){
            if(k % 5 == 0){
                b++;
                k /= 5;
            }
            else
                break;
        }
        arr[i][0] = arr[i-1][0] + a;
        arr[i][1] = arr[i-1][1] +b;
    }

    if(arr[N][0] > arr[N][1])
        cout << arr[N][1];
    else
        cout << arr[N][0];

    return 0;
}