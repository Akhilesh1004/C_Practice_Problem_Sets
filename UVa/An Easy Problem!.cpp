#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s, ds = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    while(cin>>s){
        int b = 2, ans = -1;
        bool flag = true;
        for(int i = 0; i<s.size(); i++){
            b = max(b, int(ds.find(s[i]))+1);
        }
        for(int n = b; n<=62; n++){
            long long r = 0;
            for(int i = s.size()-1; i>=0; i--){
                if(ds.find(s[i]) == -1) continue;
                r = (r*n+int(ds.find(s[i])))%(n-1); 
            }
            if(r == 0){
                ans = n;
                break;
            }
        }
        if(ans != -1) cout<<ans<<endl;
        else cout<<"such number is impossible!"<<endl;
    }
    return 0;
}