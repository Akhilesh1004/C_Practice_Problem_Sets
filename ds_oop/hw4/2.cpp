#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n, vector<int>(2));
    vector<int>dis(n, 1e9);
    vector<bool>visited(n, false);
    for(int i = 0; i<n; i++) cin>>dp[i][0]>>dp[i][1];
    dis[0] = 0;
    int result = 0;
    for(int i = 0; i<n; i++){
        int m = 1e9;
        int a = -1;
        for(int j = 0; j<n; j++){
            if(!visited[j] && m > dis[j]){
                a = j;
                m = dis[j];
            }
        }
        if(a == -1) break;
        visited[a] = true;
        result += dis[a];
        //cout<<a<<" "<<dis[a]<<" "<<visited[a]<<"\n";
        for(int j = 0; j<n; j++){
            int temp = abs(dp[a][0]-dp[j][0])+abs(dp[a][1]-dp[j][1]);
            if(!visited[j] && temp<dis[j]){
                dis[j] = temp;
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}