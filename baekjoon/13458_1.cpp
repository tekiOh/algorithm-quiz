//
// Created by vkdne on 2018-09-21.
//

#include <iostream>
#include <vector>
using namespace std;

int N,B,C;
vector<int> v;
long long sol = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    int A;
    for(int i = 0 ;i < N ; i++){
       cin >> A;
       v.push_back(A);
    }
    cin >> B >> C;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] - B > 0){
            if((v[i] - B) % C == 0){
                sol += (v[i] - B) / C;
            }
            else{
                sol += (v[i] - B) / C;
                sol++;
            }
        }
    }
    cout << N + sol << '\n';
    return 0;
}
