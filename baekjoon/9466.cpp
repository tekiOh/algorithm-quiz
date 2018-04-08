//
// Created by vkdne on 2018-04-08.
//
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int visit[100001];
int sol = 0;
bool dfs(int current,int target,int cnt){
    visit[current] = 1;

    if(current == target){
        sol += (cnt+1);
        return true;
    }

    if(visit[arr[current]] == 0){
        if(dfs(arr[current],target,cnt+1)){
            return true;
        }
        else{
            visit[current] = 0;
            return false;
        }
    }
    else {
        visit[current] = 0;
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int N;
    while(T--){
        cin >> N;
        for(int i = 1; i <= N ; i++) {
            cin >> arr[i];
            if(arr[i] == i){
                sol++;
                visit[i] = 1;
            }
        }
        for(int i = 1 ; i <= N ; i++){
            if(!visit[i] &&!visit[arr[i]]) {
                if(!dfs(arr[i], i, 0)){
                    visit[i] = 1;
                }
            }
        }

        cout << N - sol << '\n';
        sol = 0 ;
        fill_n(visit,N+1,0);
    }
    return 0;
}
