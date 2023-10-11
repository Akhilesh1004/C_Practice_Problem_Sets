#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
//O(m^n) time, O(m^n) space;
vector<vector<string>> allconstruct(string n, vector<string>&arrays){
    vector<vector<vector<string>>>table(n.size()+1);
    table[0] = {{}};
    for(int i = 0; i<=n.size(); i++){
        for(string x : arrays){
            if(n.substr(i, x.size()) == x){
                for(vector<string> combination : table[i]){
                    combination.push_back(x);
                    table[i+x.size()].push_back(combination);
                }
            }
        }
    }
    return table[n.size()];
}

int main(){
    int m;
    string n;
    while(cin>>n>>m){
        vector<string>a(m);
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        vector<vector<string>> result = allconstruct(n, a);
        for(vector<string> combination : result){
            cout<<"[ ";
            for(string x : combination){
                cout<<x<<" ";
            }
            cout<<"]"<<endl;
        }
    }
    return 0;
}