#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(int x){
    if(x > 1){
        int result = 0, count = x;
        while(count%3!=0){
            count -= 2;
            result++;
        }
        result += count/3;
        return result;
    }
    else return -1;
    
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n);
    for(int i = 0; i<n; i++) cin>>dp[i];
    sort(dp.begin(), dp.end());
    //for(int i = 0; i<n; i++) cout<<dp[i]<<" ";
    int answer = 0, count = 1, cur = dp[0];
    for(int i = 1; i<n; i++){
        if(cur == dp[i]) count++;
        else{
            int result = check(count);
            if(result == -1){
                cout<<-1<<"\n";
                return 0;
            }else{
                answer += result;
            }
            cur = dp[i];
            count = 1;
        }
    }
    int result = check(count);
    if(result == -1){
        cout<<-1<<"\n";
        return 0;
    }else{
        answer += result;
    }
    cout<<answer<<"\n";
    return 0;
}