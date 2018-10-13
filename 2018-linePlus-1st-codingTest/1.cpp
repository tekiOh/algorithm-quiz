#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
    int sol = 20000;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int cost;
    for (int distance; !(ss >> distance).fail(); ) {
        // @todo Write your code here.
        //cou << distance << endl;
        if(distance < 4 || distance > 178){
            cout << sol << endl;
            return 0;
        }
        if(distance >= 4 && distance <= 40){
            cost = 720;
        }
        else{
            cost = 720;
            cost += (((distance - 41)/8 + 1)*80);
        }
        if(sol - cost >= 0)
            sol -= cost;
        else
            break;
    }
    // @todo Write your code here.
    cout << sol << endl;
    return 0;
}