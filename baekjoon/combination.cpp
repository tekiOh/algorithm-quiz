//
// Created by vkdne on 2018-09-18.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int d[11];
int N;
void print(){
    for(int i = 1 ; i <= N ; i++){
        if(d[i] == 1)
            cout << v[i-1];
    }
    cout << endl;
}
//현재 인덱스, 현재 크기, 목표 크기
void combination(int idx, int size, int target){
    if(size == target){
        print();
        return;
    }
    for(int i = idx+1 ; i <= N - target + size + 1 ; i++){
        d[i] = 1;
        combination(i,size+1,target);
        d[i] = 0;
    }
}
void makeCombination(int N){
    //몇개로 조합을 만들지? 1~N개
    for(int i = 1; i <= N ; i++){
        //뭐부터 넣을까? >> 뭐로 시작할까?
        //i개라면 N - i + 1까지는 시작해도되는데 N - i + 2부터는 안됨
        for(int j = 1; j <= N - i + 1 ; j++){
            d[j] = 1;
            combination(j,1,i);
            d[j] = 0;
        }
    }
}
int main(){
    N = 4; //1~N까지 배열
    //배열 생성
    for(int i = 1 ; i <= N ; i++)
        v.push_back(i);

    makeCombination(N);
    return 0;
}