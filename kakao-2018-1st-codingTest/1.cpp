//
// Created by vkdne on 2018-09-15.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
vector<string> solution;
map<string,string> m;
vector<pair<string,string>> s;

int main(){
    string tmpstr;
    string command;
    string id;
    string nickname;

    for(int i = 0 ; i < record.size() ; i++){
        tmpstr = record[i];
        command = tmpstr.substr(0,tmpstr.find(" "));
        tmpstr = tmpstr.substr(tmpstr.find(" ")+1);
        id = tmpstr.substr(0,tmpstr.find(" "));
        if(command != "Change"){
            s.push_back({command,id});
            if(command == "Leave"){
                cout << command << " " << id << endl;
                continue;
            }
        }
        nickname = tmpstr.substr(tmpstr.find(" ")+1);
        cout << command << " " << id << " "<< nickname << endl;

        //없으면 넣고, 있으면 변경하고
        auto iter = m.find(id);
        if(iter == m.end())
            m.insert({id,nickname});
        else
            iter->second = nickname;
    }
    cout << "**********" << endl;
    for(int i = 0 ; i < s.size(); i++){
        cout << s[i].first <<"," << s[i].second << endl;
    }

    cout << "**********" << endl;
    for(auto it = m.begin() ; it != m.end() ; it++){
        cout << it->first << "," << it->second << endl;
    }

    for(int i = 0 ; i < s.size() ; i++){
        if(s[i].first == "Enter"){
            solution.push_back(m.find(s[i].second)->second+"님이 들어왔습니다.");
        }
        else{
            solution.push_back(m.find(s[i].second)->second+"님이 나갔습니다.");
        }
    }
    for(int i = 0 ; i < s.size() ; i++) {
        cout << solution[i] << endl;
    }

        return 0;
}