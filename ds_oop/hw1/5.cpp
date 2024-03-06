#include <iostream>
#include <unordered_map>

using namespace std;

string dp[60000];

int cnt = 0;
unordered_map<string, int>memo;

void solve(string s1, string s2){
    char temp = s1[0];
    s1[0] = s2[0];
    s2[0] = temp;
    if(memo.count(s1) || memo.count(s2)) return ;
    cnt += 2;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>dp[i];
        memo[dp[i]] = 1;
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            solve(dp[i], dp[j]);
        }
    }
    cout<<cnt<<"\n";
    return 0;
}