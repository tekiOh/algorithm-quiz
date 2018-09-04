//
// Created by vkdne on 2018-09-03.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(){

    int cacheSize = 2;
    string cities[4] = {"Jeju", "Jeju","s","S"};
    int citiesSize = 4;
    vector<string> cache;
    int curCacheSize;
    bool chk = false;
    int answer = 0;
    for(int i = 0 ; i < citiesSize; i++){
        curCacheSize = cache.size();
        chk = false;
        for(int k = 0 ; k < cities[i].size(); k++){
            if(cities[i][k] >= 97 && (int)cities[i][k] <= 122){
                cities[i][k] = (char)(int)cities[i][k] - 32;
            }
        }
        for(int j = 0 ; j <curCacheSize; j++){
            if(cities[i] == cache[j]){
                cache.erase(cache.begin()+j);
                cache.push_back(cities[i]);
                chk = true;
                answer += 1;
                break;
            }
        }

        if(!chk){
            answer += 5;
            if(cacheSize == 0 )
                continue;
            if(curCacheSize == cacheSize)
                cache.erase(cache.begin());
            cache.push_back(cities[i]);
        }
    }
    cout << answer << endl;
    return 0;
}
