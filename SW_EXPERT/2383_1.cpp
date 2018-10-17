#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T,N;
int map[10][10];
int com[10];
int sol = 99999999;
vector<pair<int,int>> people;  //{y,x}
vector<pair<int,int>> stair;   //{y,x}
priority_queue<int,vector<int>,greater<int>> stairA;
priority_queue<int,vector<int>,greater<int>> stairB;
int table[10];
int chkTable(){
//    for(int i = 0 ; i < idx ; i++){
//        if(table[i] == idx)
//            return -1;
//    }
    for(int i = 0 ; i < 3 ; i++){
        if(table[i] <= 0)
            return i;
    }
    return -1;
}
void simulation(){
    int A = map[stair[0].first][stair[0].second];
    int B = map[stair[1].first][stair[1].second];
    int t = 0;  //시간
    while(!stairA.empty()){
        //현재 계단 도착해있는 상태!
        if(stairA.top() < t){
            int tableIdx = chkTable();
            //계단이 다 꽉참
            if(tableIdx == -1){
                //시간 흐르고, 계단--
                t++;
                for(int i = 0 ; i < 3 ; i++)
                    table[i]--;
            }
            //계단 내려갈수있음
            else{
//                cout<<t<<"seoncd~~"<<stairA.top()<<" in!!!!"<<endl;
                table[tableIdx] = A;
                stairA.pop();
            }
        }
        else{
            t++;
            for(int i = 0 ; i < 3 ; i++)
                table[i]--;
        }
//        cout<<t<<"seoncd later~~table status"<<endl;
//        for(int i = 0 ;i < 3 ; i++){
//            cout << table[i] << " ";
//        }
//        cout << endl;
    }
    int Asol = 0;
    int maxV = 0;
    for(int i = 0 ;i < 3 ; i++){
        if(maxV < table[i])
            maxV = table[i];
    }
    Asol = t + maxV;
//    cout << Asol << endl;
    //table 초기화
    for(int i = 0 ; i < 3 ; i++)
        table[i] = 0;
    t = 0;
    while(!stairB.empty()){
        //현재 계단 도착해있는 상태!
        if(stairB.top() < t){
            int tableIdx = chkTable();
            //계단이 다 꽉참
            if(tableIdx == -1){
                //시간 흐르고, 계단--
                t++;
                for(int i = 0 ; i < 3 ; i++)
                    table[i]--;
            }
                //계단 내려갈수있음
            else{
//                cout<<t<<"seoncd~~"<<stairB.top()<<" in!!!!"<<endl;
                table[tableIdx] = B;
                stairB.pop();
            }
        }
        else{
            t++;
            for(int i = 0 ; i < 3 ; i++)
                table[i]--;
        }
//        cout<<t<<"seoncd later~~table status"<<endl;
//        for(int i = 0 ;i < 3 ; i++){
//            cout << table[i] << " ";
//        }
//        cout << endl;
    }
//    cout << "A : "<<A <<", B : "<<B<<endl;
    int Bsol = 0;
    maxV = 0;
    for(int i = 0 ;i < 3 ; i++){
        if(maxV < table[i])
            maxV = table[i];
    }
    Bsol = t + maxV;
//    cout << Bsol << endl;
    if(Asol < Bsol)
        Asol = Bsol;
    if(sol > Asol)
        sol = Asol;

    //table 초기화
    for(int i = 0 ; i < 3 ; i++)
        table[i] = 0;

//    cout <<"sol : "<<sol << endl;
}
void calc(){
    //도착시간 계산!
    for(int i = 0 ; i < people.size(); i++){
        if(com[i] == 0 )
            stairA.push(abs(stair[0].first-people[i].first)+abs(stair[0].second-people[i].second));
        else
            stairB.push(abs(stair[1].first-people[i].first)+abs(stair[1].second-people[i].second));
    }
    simulation();
}
void dfs(int cur, int target){
        if(cur == target){
//            cout << "***************************"<<endl;
//            for(int i = 0 ; i < target ; i++){
//                cout <<com[i]<<" ";
//            }
//            cout << endl;
            calc();
            return;
        }
        com[cur] = 0;
        dfs(cur+1,target);
        com[cur] = 1;
        dfs(cur+1,target);
}
void init(){
    sol = 999999;
    people.clear();
    stair.clear();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int a = 1;
    while(T--){
        cin >> N;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                cin >> map[i][j];
                if(map[i][j] == 1){
                    people.emplace_back(make_pair(i,j));
                }
                else if(map[i][j] == 0){
                    continue;
                }
                else{
                    stair.emplace_back(make_pair(i,j));
                }
            }
        }
//        for(int i = 0 ; i < people.size(); i++){
//            cout <<abs(stair[0].first-people[i].first)+abs(stair[0].second-people[i].second)<<" ";
//        }
//        cout << endl;
//        for(int i = 0 ; i < people.size(); i++){
//            cout <<abs(stair[1].first-people[i].first)+abs(stair[1].second-people[i].second)<<" ";
//        }
//        cout << endl;
        dfs(0,people.size());

        cout <<"#"<<a++<<" "<<sol << '\n';
        init();
    }
    return 0;
}
