//
// Created by vkdne on 2018-10-27.
//

#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int skillChk[26];
string skill = "CBD";
vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
int stck[26];
int main(){

    int answer = 0;
    bool chk;
    int top = -1;
    for(int i = skill.size()-1 ; i > -1 ; i--){
        skillChk[skill[i]-'A']++;
        stck[++top] = skill[i] -'A';
    }
    for(int i = 0 ; i < skill_trees.size() ; i++){
        int ntop = top;
        chk = true;
        for(int j = 0 ; j < skill_trees[i].size(); j++){
            //스택에 있으면
            if(skillChk[skill_trees[i][j] - 'A']){
                if(stck[ntop] == skill_trees[i][j] - 'A'){
                    ntop--;
                }
                else{
                    chk = false;
                    break;
                }
            }
        }
        if(chk)
            answer++;
    }
    cout << answer << endl;
    return answer;
}
