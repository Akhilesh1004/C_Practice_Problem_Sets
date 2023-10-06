#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, x, ans, d;
    bool check;
    while(cin>>n>>x){
        ans = 0;
        check = true;
        vector<int> dp;
        for(int i = 0; i<n-1; i++){
            cin>>d;
            dp.push_back(d);
        }
        for(int i = 0; i<=100; i++){
            ans = 0;
            vector<int> dp_ = dp;
            dp_.push_back(i);
            sort(dp_.begin(), dp_.end());
            for(int j = 1; j<n-1; j++){
                ans += dp_[j];
            }
            if(ans>=x){
                cout<<i<<endl;
                check = false;
                break;
            }
        }
        if(check) cout<<-1<<endl;
    }
    return 0;
}