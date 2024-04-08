#include <iostream> 
#include <vector> 
 
using namespace std; 
 
 
int main(){ 
    int m; 
    cin>>m; 
    vector<int>dp(m); 
    vector<int>check; 
    int n = 1; 
    for(int i = 0; i<m; i++) cin>>dp[i]; 
    for(int i = 0; i<m; i++){ 
        if(check.size() != 0 && check.back() == dp[i]){ 
            check.pop_back(); 
        }else{ 
            while(n <= m && n != dp[i]){ 
                check.push_back(n); 
                n++; 
            } 
            if(n > m || n != dp[i]){ 
                cout<<"NO\n"; 
                return 0; 
            } 
            n++; 
        } 
    } 
    if(check.size() == 0) cout<<"YES\n"; 
    else cout<<"NO\n"; 
    return 0; 
} 