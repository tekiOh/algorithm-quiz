//
// Created by vkdne on 2018-03-27.
//
#include <iostream>
using namespace std;
int N;
int arr[13];
int sol[7];

void DFS(int depth, int lastldx){
    if(depth == 6){
        for(int i = 1 ; i <= 6 ; i++){
            cout<<sol[i]<<" ";
        }
        cout << endl;
        return;
    }
    for(int i = lastldx + 1; i <= N - 5 + depth ; i++){
        sol[depth+1] = arr[i];
        DFS(depth+1,i);
    }

}

int main(){
    while(1){
        cin >> N;
        if(N == 0){
            break;
        }
        for(int i = 1 ; i <= N ; i++)
            cin >> arr[i];

        for(int i = 1 ; i <= N - 5 ; i++){
            sol[1] = arr[i];
            DFS(1,i);
        }
        cout << endl;
    }
}
