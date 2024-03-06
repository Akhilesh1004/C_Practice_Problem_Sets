#include <iostream>

using namespace std;

int arr[4][4], combin[3],m = 999999999;
char sign[3] = {'B', 'G', 'C'};
bool visited[3]={0};
string result;

void dfs(int end){
    if(end == 3){
        int temp = 0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i == j)continue;
                temp += arr[j][combin[i]];
            }
        }
        string s;
        if(temp < m){
            m = temp;
            for(int i = 0; i<3; i++) s += sign[combin[i]];
            result = s;
        }else if(m == temp){
            for(int i = 0; i<3; i++) s += sign[combin[i]];
            if(result > s) result = s;
        }
        return ;
    }
    for(int i = 0; i<3; i++){
        if(visited[i]) continue;
        visited[i] = true;
        combin[end] = i;
        dfs(end+1);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>arr[0][0]){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i==0 && j==0) continue;
                cin>>arr[i][j];
            }
        }
        m = 999999999;
        dfs(0);
        cout<<result<<" "<<m<<"\n";
    }
    return 0;
}