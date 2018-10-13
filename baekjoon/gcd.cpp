//
// Created by vkdne on 2018-09-18.
//

#include <iostream>
using namespace std;

int main(){
    int a,b;
    a = 180;
    b = 18*3;
    int tmp;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    while(a % b){
            cout <<"a : "<< a << "," << "b : " << b << endl;
            tmp = a%b;
            a = b;
            b = tmp;
    }
    cout <<"sol : "<< b << endl;
    return 0;
}