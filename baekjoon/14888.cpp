//
// Created by vkdne on 2018-02-04.
//

#include<iostream>
using namespace std;
int Max_sol = -1000000001;
int Min_sol =  1000000001;
int N;
int operand[12]; //1~11
int operat[4]; //+,-,*,/

void dfs(int d, int v){
    if(d == N){
        if(Max_sol < v)
            Max_sol = v;
        if(Min_sol > v)
            Min_sol = v;
        return;
    }

    if(operat[0]){
        operat[0]--;
        dfs(d+1,v+operand[d+1]);
        operat[0]++;
    }

    if(operat[1]){
        operat[1]--;
        dfs(d+1,v-operand[d+1]);
        operat[1]++;
    }

    if(operat[2]){
        operat[2]--;
        dfs(d+1,v*operand[d+1]);
        operat[2]++;
    }

    if(operat[3]){
        operat[3]--;
        dfs(d+1,v/operand[d+1]);
        operat[3]++;
    }
}

int main(){
    cin >> N;

    for(int i = 1 ; i <= N ; i++)
        cin >> operand[i];
    for(int i = 0 ; i < 4 ; i++)
        cin >> operat[i];

    dfs(1,operand[1]);

    cout<<Max_sol<<endl;
    cout<<Min_sol<<endl;

    return 0;
}