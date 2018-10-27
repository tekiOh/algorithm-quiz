//
// Created by vkdne on 2018-10-27.
//
#include <vector>
#include <iostream>
using namespace std;
int cookieSum[2000][2000];
vector<int> cookie = {1,2};
int answer = 0;
void calc(int l,int m, int r){
    int first = cookieSum[l][m];
    int second = cookieSum[m+1][r];
}
int main() {
    int answer = 0;
    int size = cookie.size();
    if(cookie.size() == 1) {
        cout <<"answer:"<<0<<endl;
        return 0;
    }
    for (int i = 0; i < size; i++) {
        cookieSum[i][i] = cookie[i];
    }
    for (int i = 0; i < size-1; i++) {
        for (int j = i + 1; j < size; j++) {
            cookieSum[i][j] = cookieSum[i][j - 1] + cookieSum[j][j];
        }
    }

    for (int i = 0; i < size-1; i++) {
        for (int j = i + 1; j < size; j++) {
            cookieSum[i][j] = cookieSum[i][j - 1] + cookieSum[j][j];
        }
    }

    for(int l = 0 ; l < size - 1 ; l++){
        for(int m = l ; m < size - 1 ; m++){
            if(cookieSum[l][m] <= cookieSum[m+1][size-1]){
                for(int r = m+1 ; r < size ; r++){
                    if(cookieSum[l][m] == cookieSum[m+1][r]){
                        if(answer < cookieSum[l][m])
                            answer = cookieSum[l][m];
                        break;
                    }
                    if(cookieSum[l][m] < cookieSum[m+1][r])
                        break;
                }
            }
            else
                break;
        }
    }

    return answer;
}