#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n!=0){
        int m = 9e7;
        vector<char>dp(n);
        for(int i = 0; i<n; i++){
            cin>>dp[i];
        }
        int index = -1;
        for(int i = 0; i<n; i++){
            if(dp[i] == '.') continue;
            if(dp[i] == 'Z'){
                m = 0;
                break;
            }
            else if((dp[i] == 'R' || dp[i] == 'D')){
                if(index != -1 && dp[i] != dp[index]){
                    m = min(m, i-index);
                }
                index = i;
            }
        }
        cout<<m<<"\n";
    }
    return 0;
}