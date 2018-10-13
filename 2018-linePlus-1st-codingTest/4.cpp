#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);  // drop a newline traling n
    while (n-- > 0) {
        getline(cin, line);
        stringstream ss(line);
        string method, url, body;
        string type,username,data;
        getline(ss, method, ' ');
        getline(ss, url, ' ');
        getline(ss, body);

        type = url.substr(0,6);

        cout <<"*******************************************"<<endl;

        cout << "line : " << line << endl;
        cout << "method : " << method << endl;
        cout << "url : " << url << endl;
        cout << "type : " << type << endl;
        cout << "body : " << body << endl;
        // @todo Write your code here.
    }
    return 0;
}
