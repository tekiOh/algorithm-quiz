//
// Created by vkdne on 2018-09-17.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int A,B,C;
struct ABC{
    int a,b,c;
};
queue<ABC> q;
vector<int> answer;

int visit[201][201][201];
bool chkVisit(int a,int b, int c){
    if(visit[a][b][c])
        return false;
    return true;
}
void chkSol(int a, int b){
    if(a == 0)
        answer.push_back(b);
}
void chk(int a,int b,int c){
    if(chkVisit(a,b,c)){
        chkSol(a,c);
        visit[a][b][c] = 1;
        q.push({a,b,c});
    }
}
////a -> b
//ABC move(int tc,int tb, int c, int b,int a){
//    ABC tmp;
//    tmp.a = 0;
//    tmp.b = 0;
//    tmp.c = 0;
//    int maxc = maxVal[tc];
//    int maxb = maxVal[tb];
//    if(maxb - b >= c){
//        tmp.b = b+c;
//        tmp.c = 0;
//    }
//    else{
//        tmp.b = maxb;
//        tmp.c = c - (maxb - b);
//    }
//    t
//    return tmp;
//};
void BFS(){
    int size = q.size();
    ABC tmp;
    ABC rABC;
    int na,nb,nc;
    int a,b,c;
    while(q.size()){
        tmp = q.front();
        q.pop();
        a = tmp.a;
        b = tmp.b;
        c = tmp.c;

        //C -> B
        na = a;
        if(B-b >= c){
            nb = b + c;
            nc = 0;
        }
        else {
            nb = B;
            nc = c - (B-b);
        }
        chk(na,nb,nc);
        //C -> A
        nb = b;
        if(A-a >= c){
            na = a + c;
            nc = 0;
        }
        else{
            na = A;
            nc = c - (A-a);
        }
        chk(na,nb,nc);
        //B->C
        na = a;
        if(C - c >= b){
            nc = c+b;
            nb = 0;
        }
        else{
            nc = C;
            nb = b - (C - c);
        }
        chk(na,nb,nc);
        //B->A
        nc = c;
        if(A - a >= b){
            na = a+b;
            nb = 0;
        }
        else{
            na = A;
            nb = b - (A - a);
        }
        chk(na,nb,nc);
        //A->C
        nb = b;
        if(C - c >= a){
            nc = c + a;
            na = 0;
        }
        else{
            nc = C;
            na = a - (C - c);
        }
        chk(na,nb,nc);
        //A->B
        nc = c;
        if(B -b >= a){
            nb = b+a;
            na = 0;
        }
        else{
            nb = B;
            na = a-(B - b);
        }
        chk(na,nb,nc);
    }
}


int main(){
    cin >> A >> B >> C;
//    for(int i = 0 ; i < 3 ; i++)
//        cin >> maxVal[i];

    visit[0][0][C] = 1;
    answer.push_back(C);
    q.push({0,0,C});
    BFS();
    sort(answer.begin(),answer.end());
    for(auto i : answer)
        cout << i << " ";
    return 0;
}
