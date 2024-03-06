#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>

using namespace std;

int main(){
    int n;
    while(cin>>n && n){
        vector<int>dp(n+1);
        vector<vector<int>>order(n+5, vector<int>(205));
        for(int i = 1; i<=n; i++){
            cin>>dp[i];
        }
        for(int i = 1; i<=n; i++){
            int temp = i, j = 0;
            do{
                order[i][++j] = temp;
                temp = dp[temp];
            }while(temp != i);
            order[i][0] = j;
        }
        string s, s1;
        int m;
        while(cin>>m && m){
            string s;
            cin.ignore();
            getline(cin, s);
            vector<char>ans(n+1, ' ');
            for(int i = 1; i<=s.size(); i++){
                int p = m%order[i][0];
                ans[order[i][p+1]] = s[i-1];
            }
            for(int i = 1; i<=n; i++) cout<<ans[i];
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}