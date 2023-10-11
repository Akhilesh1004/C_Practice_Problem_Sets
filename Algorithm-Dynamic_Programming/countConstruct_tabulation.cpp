#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
//O(mn^2) time, O(n) space;
int countconstruct(string n, vector<string>&arrays){
    vector<int>table(n.size()+1, 0);
    table[0] = 1;
    for(int i = 0; i<=n.size(); i++){
        for(string x : arrays){
            if(i+x.size() <= n.size() && n.substr(i, x.size()) == x){
                table[i+x.size()] += table[i];
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
        cout<<countconstruct(n, a)<<endl;
    }
    return 0;
}