//
// Created by vkdne on 2018-10-18.
//

#include <iostream>

using namespace std;
int map[20][20];
int nmap[20][20];
int N,sol;
int com[5];

void printNMAP() {
    cout << "*******************************" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << nmap[i][j] << " ";
        }
        cout << endl;
    }
}

void up() {
    //cout <<"UUUUUUUUUUUUUUPPPPPPPPPPPPPPPPP"<<endl;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (!nmap[i][j]) {
                for (int k = i + 1; k < N; k++) {
                    if (nmap[k][j]) {
                        nmap[i][j] = nmap[k][j];
                        nmap[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    //printNMAP();
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            if(nmap[i][j]) {
                //같으면
                if (nmap[i][j] == nmap[i+1][j]) {
                    nmap[i][j] *= 2;
                    nmap[i+1][j] = 0;
                    i++;
                }
            }
        }
    }
//    printNMAP();
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (!nmap[i][j]) {
                for (int k = i + 1; k < N; k++) {
                    if (nmap[k][j]) {
                        nmap[i][j] = nmap[k][j];
                        nmap[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
}

void down() {
//    cout <<"DOOOOOOOOOOOOOOOOOOOOOOOWNNNNNNNNNNNNN"<<endl;
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i > 0; i--) {
            if (!nmap[i][j]) {
                for (int k = i - 1; k > -1; k--) {
                    if (nmap[k][j]) {
                        nmap[i][j] = nmap[k][j];
                        nmap[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
    for (int j = 0; j < N; j++) {
        for (int i = N-1; i > 0; i--) {
            if(nmap[i][j]) {
                //같으면
                if (nmap[i][j] == nmap[i-1][j]) {
                    nmap[i][j] *= 2;
                    nmap[i-1][j] = 0;
                    i++;
                }
            }
        }
    }
//    printNMAP();
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i > 0; i--) {
            if (!nmap[i][j]) {
                for (int k = i - 1; k > -1; k--) {
                    if (nmap[k][j]) {
                        nmap[i][j] = nmap[k][j];
                        nmap[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
}

void left() {

//    cout <<"LEEEEEEEEEEEFFFFFFFFFFFFFFFTTTTTTTTT"<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!nmap[i][j]) {
                for (int k = j + 1; k < N; k++) {
                    if (nmap[i][k]) {
                        nmap[i][j] = nmap[i][k];
                        nmap[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N -1 ; j++){
            if(nmap[i][j]) {
                //같으면
                if (nmap[i][j] == nmap[i][j+1]) {
                    nmap[i][j] *= 2;
                    nmap[i][j+1] = 0;
                    j++;
                }
            }
        }
    }
//    printNMAP();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!nmap[i][j]) {
                for (int k = j + 1; k < N; k++) {
                    if (nmap[i][k]) {
                        nmap[i][j] = nmap[i][k];
                        nmap[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
}

void right() {
//    cout <<"RRRRRRRRRIIIIIIIIIIIIIIIIIIGGGGHTTT"<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > -1; j--) {
            if (!nmap[i][j]) {
                for (int k = j - 1; k > -1; k--) {
                    if (nmap[i][k]) {
                        nmap[i][j] = nmap[i][k];
                        nmap[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
    for(int i = 0 ; i < N ; i++){
        for(int j = N-1 ; j > 0 ; j--){
            if(nmap[i][j]) {
                //같으면
                if (nmap[i][j] == nmap[i][j-1]) {
                    nmap[i][j] *= 2;
                    nmap[i][j-1] = 0;
                    j++;
                }
            }
        }
    }
//    printNMAP();
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > -1; j--) {
            if (!nmap[i][j]) {
                for (int k = j - 1; k > -1; k--) {
                    if (nmap[i][k]) {
                        nmap[i][j] = nmap[i][k];
                        nmap[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
//    printNMAP();
}
void calc(){
    for(int i = 0 ;i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(sol < nmap[i][j])
                sol = nmap[i][j];
        }
    }
}
void simulation() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nmap[i][j] = map[i][j];
        }
    }
    //5번 움직여주자!
    for (int i = 0; i < 5; i++) {
        switch (com[i]) {
            case 0 :
                //cout << 0 << " ";
                up();
                break;
            case 1 :
                //cout << 1 << " ";
                down();
                break;
            case 2 :
                //cout << 2 << " ";
                left();
                break;
            default:
                //cout << 3 << " ";
                right();
                break;
        }
    }
//    cout <<endl;
    calc();
}

void makeCom(int cnt) {
    if (cnt == 5) {
//        cout << "*******************"<<endl;
//        for(int i = 0 ; i < 5 ;i++){
//            cout <<com[i] << " ";
//        }
//        cout << endl;
        simulation();
        return;
    }
    for (int i = 0; i < 4; i++) {
        com[cnt] = i;
        makeCom(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    makeCom(0);
    cout << sol << endl;
    return 0;
}
