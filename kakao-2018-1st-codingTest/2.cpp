//
// Created by vkdne on 2018-09-15.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solmap[502][2];
double failure[501];
vector<pair<pair<int,int>,int>> f;
int N = 5;
vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
vector<int> answer;

bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first*b.first.second == b.first.first*a.first.second)
        return a.second < b.second;
    return a.first.first*b.first.second > b.first.first*a.first.second;
}
int main() {
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j < stages[i]; j++) {
            solmap[j][0]++;
            solmap[j][1]++;
        }
        solmap[stages[i]][1]++;
    }

    for(int i = 1 ; i <= N ; i++){
        f.push_back(make_pair(make_pair(solmap[i][1]- solmap[i][0],solmap[i][1]),i));
    }

    stable_sort(f.begin(),f.end(),compare);
    for(int i = 0 ; i < f.size() ; i++){
        answer.push_back(f[i].second);
    }
    cout << "++++++++++++++++++++"<<endl;
    for(auto a : answer)
        cout << a << endl;




    return 0;
}