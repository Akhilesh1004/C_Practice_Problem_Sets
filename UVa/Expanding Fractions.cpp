#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    map<int, int>dp;
    while(cin>>n>>m && (n+m) != 0){
        dp.clear();
        dp[n] = 0;
        int index = 1, result = -1;
        cout<<".";
        while(n){
            n *= 10;
            cout<<n/m;
            if(dp.count(n%m)) {
                result = index-dp[n%m];
                //cout<<dp[n%m]<<"\n";
                break;
            }
            dp[n%m] = index;
            n %= m;
            index++;
            if(index && !(index%50)) cout<<"\n";
        }
        cout<<"\n";
        if(n == 0) cout<<"This expansion terminates.\n";
        else cout<<"The last "<<result<<" digits repeat forever.\n";
        cout<<"\n";
        //cout<<index<<"\n";
    }
    return 0;
}