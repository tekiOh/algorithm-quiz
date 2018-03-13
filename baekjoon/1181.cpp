//
// Created by vkdne on 2018-03-13.
//

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

set<string> arr[51];
int main(){

    int N;
    cin >> N;
    string a;
    while(N--){
        cin >> a;
        arr[a.length()].insert(a);
    }

    for(int i = 1; i < 51 ; i++){
        for(auto it = arr[i].begin() ; it != arr[i].end() ; it++)
            cout << *(it) << '\n';
    }

    return 0;
}