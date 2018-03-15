//
// Created by vkdne on 2018-03-15.
//

#include<iostream>
using namespace std;

struct HL{
    long long H = 0;
    long long L = 0;
};

HL arr[101][101];
int main(){
    int N;
    int K;
    cin>> N >> K;

    long long temp = 10000000000000;
    for(int i = 0; i <= N ; i++){
        for(int j = 0; j <=i ; j++){
            if(j == 0 || j == i){
                arr[i][j].L = 1;
                continue;
            }
            arr[i][j].H = (arr[i-1][j-1].H + arr[i-1][j].H);
            arr[i][j].L = (arr[i-1][j-1].L + arr[i-1][j].L);

            if(arr[i][j].L >= temp){
                arr[i][j].H++;
                arr[i][j].L -= temp;
            }
        }
    }

    if(arr[N][K].H == 0)
        cout << arr[N][K].L;
    else
        cout << arr[N][K].H << arr[N][K].L;

    return 0;
}