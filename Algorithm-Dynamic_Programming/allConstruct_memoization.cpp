#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<vector<string>> allconstruct(string n, vector<string>&arrays, map<string, vector<vector<string>>>&memo){
    if(n.empty()) return {{}};
    if(memo.find(n) != memo.end()) return memo[n];
    vector<vector<string>> allcombination;
    for(string x:arrays){
        if(n.find(x) == 0){
            string n_ = n.substr(x.size());
            allcombination = allconstruct(n_, arrays, memo);
            for(vector<string> combination: allcombination){
                combination.push_back(x);
                memo[n].push_back(combination);
            }
        }
    }
    return memo[n];
}

int main(){
    int m;
    string n;
    while(cin>>n>>m){
        vector<string>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<string, vector<vector<string>>>memo;
        vector<vector<string>> result = allconstruct(n, a, memo);
        if(result.empty()) cout<<"[]"<<endl;
        for(vector<string> combination:result){
            cout<<"[ ";
            for(int i = combination.size()-1; i>=0; i--){
                cout<<combination[i]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    return 0;
}
/*
vector<string> allconstruct(string n, vector<string>&arrays, map<string, vector<string>>&memo){
    if(n.empty()) return {};
    if(memo.find(n) != memo.end()) return memo[n];
    vector<string> shortest_combination;
    for(string x:arrays){
        if(n.find(x) == 0){
            string n_ = n.substr(x.size());
            vector<string>substr_combination = allconstruct(n_, arrays, memo);
            substr_combination.push_back(x);
            if(substr_combination.empty() || substr_combination[0] != "-1"){
                if(shortest_combination.empty() || shortest_combination.size()>substr_combination.size()){
                    shortest_combination = substr_combination;
                }
            }
        }
    }
    if(shortest_combination.empty()) memo[n] = {"-1"};
    else memo[n] = shortest_combination;
    return memo[n];
}

int main(){
    int m;
    string n;
    while(cin>>n>>m){
        vector<string>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        map<string, vector<string>>memo;
        vector<string> result = allconstruct(n, a, memo);
        if(result.empty()) cout<<"[]"<<endl;
        cout<<"[ ";
        for(string x:result){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
*/