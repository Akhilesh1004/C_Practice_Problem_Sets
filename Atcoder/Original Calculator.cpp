#include <iostream>
#include <map>

using namespace std;

int main(){
    long long int n, k;
    map<int, int>memo, memo2;
    while(cin>>n>>k){
        memo.clear();
        memo2.clear();
        int index = 0, len = -1, cnt = k;
        memo[n] = index;
        memo2[index] = n;
        while(cnt--){
            index++;
            int temp = n;
            while(temp){
                n += temp%10;
                temp /= 10;
                n = n%100000;
            }
            if(memo.count(n)){
                len = index - memo[n];
                break;
            }else{
                memo[n] = index;
                memo2[index] = n;
            }
        }
        if(len != -1) cout<<memo2[(k-memo[n])%len+memo[n]]<<"\n";
        else cout<<n%100000<<"\n";
    }
    return 0;
}