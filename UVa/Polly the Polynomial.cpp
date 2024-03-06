#include <iostream>
#include <vector>

using namespace std;

vector<int> output(string s){
    vector<int>dp;
    for(int i = 0; i<s.size(); i++){
        int temp = 0;
        bool check = false;
        while(s[i] != ' ' && i<s.size()){
            if(s[i] == '-') check = true;
            else{
                temp *= 10;
                temp += (s[i]-'0');
            }
            i++;
        }
        if(check) temp *= -1;
        dp.push_back(temp);
    }
    return dp;
}

long long int solve2(vector<int>dp, int x){
    long long int temp = 0, y = 1;
    for(int i = dp.size()-1; i>=0; i--){
        temp += dp[i]*y;
        y *= x;
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin, s)){
        vector<int>dp = output(s);
        getline(cin, s);
        vector<int>dp1 = output(s);
        for(int i = 0; i<dp1.size(); i++){
            if(i) cout<<" ";
            cout<<solve2(dp, dp1[i]);
        }
        cout<<"\n";
    }
    return 0;
}