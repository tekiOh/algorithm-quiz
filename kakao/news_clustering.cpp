//
// Created by vkdne on 2018-09-05.
//
#include <iostream>
#include <string>
using namespace std;

int arr1[26][26];
int arr2[26][26];

string toupper(string str){
    int size = str.size();
    string temp = str;
    for(int i = 0 ; i < size ; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            temp[i] = str[i] - 32;
        }
    }
    return temp;
}

int main(){
    string str1 = "FRANCE";
    string str2 = "french";

    str1 = toupper(str1);
    str2 = toupper(str2);

    int size1 = str1.size();
    int size2 = str2.size();

    for(int i = 0 ; i < size1 - 1 ; i++){
        //유효하면~
        if(str1[i] >= 'A' && str1[i] <= 'Z' && str1[i+1] >= 'A' && str1[i+1] <= 'Z'){
            arr1[(str1[i]-65)][(str1[i+1]-65)]++;
        }
    }

    for(int i = 0 ; i < size2 - 1 ; i++){
        //유효하면~
        if(str2[i] >= 'A' && str2[i] <= 'Z' && str2[i+1] >= 'A' && str2[i+1] <= 'Z'){
            arr2[(str2[i]-65)][(str2[i+1]-65)]++;
        }
    }
    int union_num = 0;
    int intersection_num =0;
    for(int i = 0 ; i < 26 ; i++){
        for(int j = 0 ; j < 26 ; j++){
           union_num += max(arr1[i][j],arr2[i][j]);
           intersection_num += min(arr1[i][j],arr2[i][j]);
        }
    }

    double solution = ((double)intersection_num/(double)union_num)*65536;
    cout << solution << endl;
    return 0;
}
