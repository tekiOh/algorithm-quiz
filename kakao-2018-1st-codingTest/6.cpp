//
// Created by vkdne on 2018-09-15.
//

#include <iostream>
using namespace std;


int main(){
    int* a;
    int* b;
    int c = 3;
    a = b = &c;
    cout << *a <<'\t'<< *b << endl;
    return 0;
}