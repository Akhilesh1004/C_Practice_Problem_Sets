#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>

using namespace std ;

int solve(string s, vector<vector<int>> memo){
    if(s.size() == 1) return 0;
    int total = 0;
    stack<int>stk;
    vector<int>temp;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(') stk.push(-2);
        else if(s[i] == ')'){
            while(stk.top() != -2){
                temp.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
            int x1 = memo[temp[1]][0];
            int y1 = memo[temp[1]][1];
            int x2 = memo[temp[0]][0];
            int y2 = memo[temp[0]][1];
            if(y1 != x2) return -1;
            total += x1*y1*y2;
            memo.push_back(vector<int>{x1, y2});
            stk.push(memo.size()-1);
            temp.clear();
        }
        else stk.push(s[i] - 'A');
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    char a;
    int x, y;
    vector<vector<int>>memo(26);
    for(int i = 0; i<n; i++){
        cin>>a>>x>>y;
        memo[a - 'A'].push_back(x);
        memo[a - 'A'].push_back(y);
    }
    string s;
    while(cin>>s){
        int result = solve(s, memo);
        if(result == -1) cout<<"error"<<endl;
        else cout<<result<<endl;
    }
    return 0;
}