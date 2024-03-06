#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {1, 1, -1, -1, 0, 0, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, index = 1;
    while(cin>>n>>m && n+m != 0){
        vector<vector<char>>arr(n, vector<char>(m)), result(n, vector<char>(m, '0'));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>arr[i][j];
                if(arr[i][j] == '*'){
                    result[i][j] = '*';
                    for(int k = 0; k<8; k++){
                        if(i+dx[k] < n && i+dx[k] >= 0 && j+dy[k] < m && j+dy[k] >= 0 && result[i+dx[k]][j+dy[k]]!='*'){
                            result[i+dx[k]][j+dy[k]]++;
                        }
                    }
                }
            }
        }
        if(index != 1)cout<<"\n";
        cout<<"Field #"<<index<<":\n";
        index++;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<result[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}