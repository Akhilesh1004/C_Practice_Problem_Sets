#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>dp, vector<bool>&check, int x){
    check[x] = true;
    for(int i = 0; i<dp[x].size(); i++){
        if(check[dp[x][i]]) continue;
        else dfs(dp, check, dp[x][i]);
    }
}

int main(){
    char n;
    cin>>n;
    cin.ignore();
    //vector<vector<int>>dp(n-'A', vector<int>(n-'A'));
    vector<vector<int>>dp(n-'A'+1);
    vector<bool>check(n-'A'+1, false);
    string s;
    while(getline(cin, s) && s!="\n"){
        if(s[0] == s[1]) continue;
        dp[s[0]-'A'].push_back(s[1]-'A');
        dp[s[1]-'A'].push_back(s[0]-'A');
    }
    int c = 0;
    for(int i = 0; i<=n-'A'; i++){
        if(check[i]) continue;
        else{
            c++;
            dfs(dp, check, i);
        }

    }
    cout<<c<<"\n";
    return 0;
}