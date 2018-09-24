//
// Created by vkdne on 2018-09-24.
//

#include <iostream>

using namespace std;
int N;
int number[100];
int operand[4];     //+-*/
int maxsol = -1000000000;
int minsol = 1000000000;
void dfs(int cnt, int val){
    if(cnt == N - 1){
        if(maxsol < val)
            maxsol = val;
        if(minsol > val)
            minsol = val;
        return;
    }
    if(operand[0]){
        operand[0]--;
        dfs(cnt+1,val+number[cnt+1]);
        operand[0]++;
    }
    if(operand[1]){
        operand[1]--;
        dfs(cnt+1,val-number[cnt+1]);
        operand[1]++;
    }
    if(operand[2]){
        operand[2]--;
        dfs(cnt+1,val*number[cnt+1]);
        operand[2]++;
    }
    if(operand[3]){
        operand[3]--;
        if(val < 0 && number[cnt+1] > 0){
            dfs(cnt+1,((-1*val)/number[cnt+1])*-1);
        }
        else
            dfs(cnt+1,val/number[cnt+1]);
        operand[3]++;
    }
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> number[i];
    for(int i = 0 ; i < 4 ; i++)
        cin >> operand[i];

    dfs(0,number[0]);
    cout << maxsol << endl;
    cout << minsol << endl;
    return 0;
}