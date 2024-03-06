#include <iostream>
#include <vector>

using namespace std;

int r, c;
int dx[8] = {1, 1, -1, -1, 0, 0, 1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

bool find_result(vector<vector<char>>arr, string s, int x, int y, int index){
    if(index == 8) return false;
    int x1 = x, y1 = y;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == arr[x1][y1]){
            if(i != s.size()-1 && x1+dx[index] >=0 && x1+dx[index] < r && y1+dy[index] >= 0 && y1+dy[index] < c){
                x1 += dx[index];
                y1 += dy[index];
            }
        }else{
            return find_result(arr, s, x, y, index+1);
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    bool check = true;
    cin>>n;
    while(n--){
        cin>>r>>c;
        vector<vector<char>>arr(r, vector<char>(c));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                cin>>arr[i][j];
                arr[i][j] = tolower(arr[i][j]);
            }
        }
        int m;
        bool flag;
        cin>>m;
        string s;
        if(!check) cout<<"\n";
        check = false;
        for(int i = 0; i<m; i++){
            flag = false;
            cin>>s;
            for(int i = 0; i<s.size(); i++) s[i] = tolower(s[i]);
            for(int i = 0; i<r; i++){
                for(int j = 0; j<c; j++){
                    if(arr[i][j] == s[0]){
                        if(find_result(arr, s, i, j, 0)){
                            cout<<i+1<<" "<<j+1<<"\n";
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag){
                    break;
                }
            }
        }
    }
    return 0;
}