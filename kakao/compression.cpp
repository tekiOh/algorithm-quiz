//
// Created by vkdne on 2018-09-11.
//
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string msg = "ABABABABABABABAB";

int main(){
    map<string,int> m;
    m["A"] = 1;m["B"] = 2;m["C"] = 3;m["D"] = 4;m["E"] = 5;m["F"] = 6;m["G"] = 7;m["H"] = 8;m["I"] = 9;m["J"] = 10;m["K"] = 11;m["L"] = 12;m["M"] = 13;m["N"] = 14;m["O"] = 15;m["P"] = 16;
    m["Q"] = 17;m["R"] = 18;m["S"] = 19;m["T"] = 20;m["U"] = 21;m["V"] = 22;m["W"] = 23;m["X"] = 24;m["Y"] = 25;m["Z"] = 26;
    vector<int> answer;
    int size = m.size();
    int ss = msg.size();
    string cur = "";
    for(int i = 0 ; i < ss ; i++){
        if(i == ss -1){
            //cout << "p :" <<msg.substr(i,1) <<","<<m[msg.substr(i,1)]<< endl;
            answer.push_back(m[msg.substr(i,1)]);
        }
        for(int j = i+1 ; j < ss ; j++){
            if(m.end() == m.find(msg.substr(i,j-i+1))){
                size++;
                m[msg.substr(i,j-i+1)] = size;
                //cout <<"i : "<< i << ", j : "<< j << endl;
                //cout << "p :" <<msg.substr(i,j-i) <<","<<m[msg.substr(i,j-i)]<<"\t"<< "w+c : " <<msg.substr(i,j-i+1)<<" "<<size << endl;
                answer.push_back(m[msg.substr(i,j-i)]);
                i = j-1;
                break;
            }
            if(j == ss -1){
                //cout << "p :" <<msg.substr(i,j-i+1) <<","<<m[msg.substr(i,j-i+1)]<<endl;
                answer.push_back(m[msg.substr(i,j-i+1)]);
                i = ss -1;
            }
        }
    }
    for(auto a : answer){
        cout << a << endl;
    }
    return 0;
}
