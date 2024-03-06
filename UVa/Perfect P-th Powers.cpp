#include <iostream>
#include <map>

using namespace std;

map<long long int, int>memo;

void table(int n){
    for(int i = 2; i<=n; i++){
        long long int a = i, b = i;
        int cnt = 1;
        while(a*b <= 2147483648){
            a *= b;
            cnt++;
            if(!memo.count(a)){
                memo[a] = cnt;
            }else{
                memo[a] = max(memo[a], cnt);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n, ans;
    table(47000);
    while(cin>>n && n){
        if(memo.count(n)) ans = memo[n];
        else if(n < 0){
            if(memo.count(-1*n)){
                ans = memo[-1*n];
                while(ans%2==0) ans /= 2;
            }else{
                ans = 1;
            }
        }
        else ans = 1;
        cout<<ans<<"\n";
    }
    return 0;
}