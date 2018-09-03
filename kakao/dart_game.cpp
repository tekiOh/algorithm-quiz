//
// Created by vkdne on 2018-09-03.
//

#include <string>
#include <iostream>

using namespace std;

int main() {
    string dartResult = "1S2D*3T";
    int score[3];
    string bonus[3];
    string option[3];
    int idx = 0;
    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            //cout <<"bonus in!  : "<< i << endl;
            bonus[idx] = dartResult[i];
            if (i + 1 < dartResult.length() && (dartResult[i + 1] == '#' || dartResult[i + 1] == '*')) {
                option[idx] = dartResult[i + 1];
                //cout<< "option in!!  : "<< i <<endl;
            }
            if (i - 1 > -1 && (int)dartResult[i - 1] >= 48 && (int)dartResult[i - 1] < 58) {
                //cout << "score in!!  : "<< i << " " << dartResult[i - 1] <<endl;
                if ((int) dartResult[i - 1] == 48) {
                    if (i - 2 > -1 && (int)dartResult[i - 2] == 49)
                        score[idx] = 10;
                    else
                        score[idx] = 0;
                } else
                    score[idx] = (int) dartResult[i - 1] - 48;
            }
            idx++;
        }

    }

//    for(int i = 0 ; i < 3 ; i++){
//        cout << score[i] << ' '<< bonus[i] << ' ' << option[i] << endl;
//    }

    for(int i = 0 ; i < 3; i++){
        if(bonus[i] == "S")
            ;
        else if(bonus[i] == "D")
            score[i] = (score[i]*score[i]);
        else
            score[i] = (score[i]*score[i]*score[i]);
        if(option[i] == "*"){
            score[i] *= 2;
            if(i)
                score[i-1] *= 2;
        }
        if(option[i] == "#"){
            score[i] *= -1;
        }
    }

    cout << score[0] + score[1] + score[2] << endl;
    return 0;
}