#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
//O(mn^2) time, O(n^2) space
bool canconstruct(string n, vector<string>&arrays){
    vector<bool>table(n.size()+1, false);
    table[0] = true;
    for(int i = 0; i<=n.size(); i++){
        if(table[i]){
            for(string x : arrays){
                if(i+x.size() <= n.size() && n.substr(i, x.size()) == x){
                    table[i+x.size()] = true;
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
        cout<<canconstruct(n, a)<<endl;
    }
    return 0;
}