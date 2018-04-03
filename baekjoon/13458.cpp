//
// Created by vkdne on 2018-04-03.
//

#include <iostream>
#include <vector>
using namespace std;

vector<long long> room;
int N,B,C;
long long sol;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    int tmp;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        room.push_back(tmp);
    }

    cin >> B >> C;

    for(int i = 0 ; i < N ; i++){
        if(room[i] > B){
            if((room[i] - B) % C == 0)
                sol += (room[i] - B) / C;
            else
                sol += ((room[i] - B) / C)+1;
        }
    }
    cout << sol + N << endl;
    return 0;
}