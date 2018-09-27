//
// Created by vkdne on 2018-09-27.
//

#include <iostream>
#include <vector>

using namespace std;
int N,M;
vector<pair<int,int>> h;
vector<pair<int,int>> c;
int combination[13];
int sol = 99999999;
int d[100][13];
void calc(){
    int msol = 0;
    for(int i = 0 ; i < h.size(); i++){
        int m = 99999999;
        for(int j = 0 ; j < c.size(); j++){
            if(combination[j]){
                if(m > d[i][j]){
                    m = d[i][j];
                }
            }
        }
        msol += m;
    }
    if(sol > msol)
        sol = msol;
}
void makeCombination(int current, int size, int target){
    if(size == target){
        calc();
        return;
    }
    for(int i = current + 1; i <= c.size() + size - target ; i++){
        combination[i] = 1;
        makeCombination(i,size+1,M);
        combination[i] = 0;
    }
}
void comb(){
    for(int i = 0 ; i <= c.size() - M; i++){
        combination[i] = 1;
        makeCombination(i,1,M);
        combination[i] = 0;
    }
}
void dcalc(){
    for(int i = 0 ; i < h.size(); i++){
        for(int j= 0 ; j < c.size(); j++){
            d[i][j] = abs(h[i].first - c[j].first)+ abs(h[i].second - c[j].second);
        }
    }
}
int main(){
    cin >> N >> M;
    int a;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            cin >> a;
            //집
            if(a == 1){
                h.emplace_back(make_pair(i,j));
            }
            //치킨
            else if(a == 2){
                c.emplace_back(make_pair(i,j));
            }
        }
    }
    dcalc();
    comb();
    cout << sol << endl;
}