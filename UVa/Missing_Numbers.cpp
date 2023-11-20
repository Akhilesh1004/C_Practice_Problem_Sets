#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, x;
    while(cin>>n>>m){
        vector<int>dp;
        for(int i= 0; i<m; i++){
            cin>>x;
            dp.push_back(x);
        }
        sort(dp.begin(), dp.end());
        vector<int>dp_;
        vector<int>diff;
        for(int i = 1; i<n; i++){
            for(int j = m-i-1; j>=0; j--){
                cin>>x;
                dp_.push_back(x);
            }
            sort(dp_.begin(), dp_.end());
            set_difference(dp.begin(), dp.end(), dp_.begin(), dp_.end(), inserter(diff, diff.begin()));
            cout<<diff[0]<<endl;
            dp = dp_;
            dp_.clear();
            diff.clear();
        }
    }
    return 0;
}