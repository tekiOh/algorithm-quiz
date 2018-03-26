    //
    // Created by vkdne on 2018-03-26.
    //

    #include <iostream>
    #include <queue>
    #include <vector>
    using namespace std;

    vector<int> arr[101];
    queue<int> q;
    int N;
    int visit[101][101];
    int main(){
        cin >> N;

        int a;
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                cin >> a;
                if(a){
                    arr[i].push_back(j);
                }
            }
        }

        for(int i = 1; i <= N ; i++) {
            q.push(i);
            while(q.size()){
                int tmp = q.front();
                q.pop();
                for(auto it = arr[tmp].begin() ; it != arr[tmp].end(); it++){
                    if(visit[i][*it] == 0){
                        visit[i][*it] = 1;
                        q.push(*it);
                    }
                }
            }
        }

        for(int i = 1; i <= N ; i++) {
            for (int j = 1; j <= N; j++) {
                cout << visit[i][j] << " ";
            }
            cout <<endl;
        }
        return 0;
    }