//
// Created by vkdne on 2018-09-15.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> food_times = {3, 1, 2};
long long k = 5;
long long total = 0;

int main(){
    int min = 999999999;
    int size = food_times.size();
    for(int i = 0 ; i < size; i++) {
        total += food_times[i];
        if(min > food_times[i])
            min = food_times[i];
    }
    if(total <= k)
        return -1;

    int chknum = min;
    k -= min*size;


    int idx = 0;
    while(k--){
        if(food_times[idx] != chknum)
            food_times[idx]--;
        else
            k++;
        if(idx == size -1)
            idx = 0;
        else
            idx++;
    }
    while(1){
        if(food_times[idx] == chknum){
            if(idx == size -1)
                idx = 0;
            else
                idx++;
        }
        else {
            cout << idx +1 << endl;
            return idx + 1;
        }
    }
}