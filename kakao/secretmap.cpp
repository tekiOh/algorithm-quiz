//
// Created by vkdne on 2018-09-03.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int a1[16][16];
int a2[16][16];
vector<string> ans;

int main() {
    int n = 5;
    int arr1[5] = {9, 20, 28, 18, 11};
    int arr2[5] = {30, 1, 21, 17, 28};
    int tmp1;
    int tmp2;
    int idx1;
    int idx2;
    for (int i = 0; i < n; i++) {
        tmp1 = arr1[i];
        idx1 = n - 1;
        tmp2 = arr2[i];
        idx2 = n - 1;
        while (tmp1) {
            a1[i][idx1] = (tmp1 % 2);
            tmp1 /= 2;
            idx1--;
        }
        while (tmp2) {
            a2[i][idx2] = (tmp2 % 2);
            tmp2 /= 2;
            idx2--;
        }
        string str = "";
        for (int j = 0; j < n; j++) {
            if(a1[i][j] == 1 || a2[i][j] == 1)
                str += "#";
            else
                str += " ";
        }
        ans.push_back(str);
    }

    for(int i = 0 ; i < n ; i++)
        cout<<ans[i]<<endl;
    return 0;
}