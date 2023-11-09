#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;

void permute(int index, vector<int>&ans, vector<bool>&used){
    if(index == n){
        for(int i = 0; i<n; i++){
            cout<<ans[i];
        }
        cout<<endl;
        return ;
    }
    for(int i = 0; i<10; i++){
        if(!used[i]){
            ans[index] = i;
            used[i] = true;
            permute(index+1, ans, used);
            used[i] = false;
        }
    }
}

int main(){
    while(cin>>n){
        vector<int>ans(100, 0);
        vector<bool>used(10, false);
        permute(0, ans, used);
    }
    return 0;
}