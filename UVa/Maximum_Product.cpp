#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n;
    int index = 1;
    while(cin>>n){
        long long int maximun = 0;
        vector<int>dp(n);
        for(int i = 0; i<n; i++){
            cin>>dp[i];
        }
        for(int i = 0; i<n; i++){
            long long int result = 1;
            for(int j = i; j<n; j++){
                result *= dp[i];
                maximun = max(maximun, result);
            }
        }
        cout<<"Case #"<<index<<": The maximum product is "<<maximun<<"."<<endl;
        cout<<endl;
        index++;
    }
}