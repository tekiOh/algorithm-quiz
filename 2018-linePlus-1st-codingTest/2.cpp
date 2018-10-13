#include <iostream>
#include <algorithm>

using namespace std;
int **arr;

int main() {
    int N;
    cin >> N;
    arr = new int *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[N];

    //fill_n(&arr[0][0],N*N,1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = i + j;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}