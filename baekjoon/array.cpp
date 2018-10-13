//
// Created by vkdne on 2018-09-21.
//

#include<iostream>
#include<queue>
using namespace std;
struct xy{
    int x,y;
//    bool operator <(const xy& a)const{
//            return this->y > a.y;
//    };
};
struct compare{
    bool operator()(const xy a, const xy b){
        return a.y < b.y;
    }
};
priority_queue<xy,vector<xy>,compare> pq;
int main(){
    pq.push({1,5});
    pq.push({2,4});
    pq.push({3,3});
    pq.push({4,2});
    pq.push({5,1});
    while(!pq.empty()){
        cout << pq.top().x <<","<<pq.top().y<<endl;
        pq.pop();
    }
    return 0;
}