//
// Created by vkdne on 2018-03-12.
//

#include <iostream>
#include <cmath>
using namespace std;


int main(){

    int N;
    int a;

    int A,B;
    int solA,solB;
    bool chkA,chkB;
    cin >> N;
    while(N--){
        cin >> a;
        for(int i = 2 ; i <= a/2 ; i++){
            A = i;
            B = a - i;
            chkA = true;
            chkB = true;
            for(int j = 2 ; j <=sqrt((double)A);j++){
                if(A % j == 0){
                    chkA = false;
                    break;
                }
            }
            if(!chkA)
                continue;

            for(int j = 2 ; j <=sqrt((double)B);j++){
                if(B % j == 0){
                    chkB = false;
                    break;
                }
            }
            if(chkA && chkB){
                solA = A;
                solB = B;
            }
        }
        cout << solA << ' ' << solB << '\n';
    }

    return 0;
}