//
// Created by vkdne on 2018-10-12.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<char> v;
set<int> s;
int T,N,K;
int sol;
int getDec(char a){
    if(a >= 48 && a <58){
        return a-48;
    }
    else{
        return a-55;
    }
}
void calc(int start){
//    cout << start+1<<"th calc start!!"<<endl;
    for(int i = start ; i < v.size(); i += N/4){
        int a = 1;
        int dec =0;
        for(int j = i+N/4-1 ; j > i-1 ; j--){
//            cout << v[j] <<" -> "<< getDec(v[j])<<endl;
//            cout << getDec(v[j])*a << endl;
            dec += (getDec(v[j])*a);
            a *= 16;
        }
        s.insert(dec);
        //cout << dec <<" insert!!!!"<<endl;
    }
}
void simulation(){
    //auto it = v.begin();
    // 0~N/4 -1 번 회전하면 됨 N/4번부터 중복
    for(int i = 0 ; i < N/4 ; i++){
        calc(i);
        v.push_back(v[i]);
        //it++;
    }
}
void makeSol(){
    int a = 1;
    for(auto it = s.begin(); it != s.end(); it++){
        if(a == s.size() - K + 1) {
            sol = *it;
            return;
        }
        a++;
    }
}
void init(){
    v.clear();
    s.clear();
}
int main(){
    cin >> T;
    int a = 1;
    char c;
    while(T--){
        cin >> N >> K;
        for(int i = 0 ; i < N ; i++){
            cin >> c;
            v.push_back(c);
        }
//        for(int i = 0 ;i <v.size(); i++)
//            cout << v[i];
        //cout << endl;
        simulation();
        makeSol();
//        for(auto it = s.begin(); it != s.end(); it++)
//            cout << *it << endl;
        cout <<"#"<<a<<" "<<sol<<endl;
        a++;
        init();
    }
    return 0;
}