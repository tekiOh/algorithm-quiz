//
// Created by vkdne on 2018-10-12.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> A;
vector<int> B;
int N;
int main(){
    cin >> N;
    int a;
    for(int i = 0 ; i < N ; i++){
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0 ; i < N ; i++){
        cin >> a;
        B.push_back(a);
    }
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end());
    int sol = 0;
    for(int i = 0 ; i < N ; i++) {
        sol += A[i]*B[i];
    }
    cout << sol << endl;
    return 0;
}