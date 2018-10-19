//
// Created by vkdne on 2018-10-19.
//
#include <iostream>
#include <vector>
using namespace std;

long long N,B,C,sol;
vector<long long> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    v.reserve(N);
    int a;
    for(int i = 0 ; i < N ; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> B >> C;
    for(int i = 0 ; i < N ; i++){
        a = v[i] - B;
        sol++;
        if( a> 0){
            if(a % C == 0){
                sol += a/C;
            }
            else{
                sol += a/C+1;
            }
        }
    }
    cout << sol << endl;
    return 0;
}
