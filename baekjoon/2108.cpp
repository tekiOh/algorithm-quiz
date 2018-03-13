//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <cmath>
using namespace std;
int arr[8001];
int main(){
    int N;
    cin >> N;
    int a;
    int sum = 0;
    int max = -4001;
    int min = 4001;
    //평균, 범위
    for(int i = 0 ; i < N ; i++){
        cin >> a;
        arr[a+4000]++;
        sum += a;
        if(max < a)
            max = a;
        if(min > a)
            min = a;
    }
    //최빈값
    int most = 0;
    bool second = false;
    for(int i = 1 ; i <= 8000 ; i++){
        if(arr[most] == arr[i]){
            if(!second){
                most = i;
                second = true;
            }
        }
        if(arr[most] < arr[i]){
            most = i;
            second = false;
        }
    }

    //중앙값
    int mid;
    if(arr[0] >=((N/2)+1))
        mid = 0;
    else {
        for (int i = 1; i <= 8000; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] >= ((N / 2) + 1)) {
                mid = i;
                break;
            }
        }
    }

    cout <<floor(((double)sum / (double)N) + (double)0.5) << endl;
    cout <<mid - 4000 << endl;
    cout <<most - 4000 << endl;
    cout <<max - min << endl;

    return 0;
}