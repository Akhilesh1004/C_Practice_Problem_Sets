#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b && (a!=0 || b!=0)){
        int ans = 0;
        bool carry = false;
        while(a>=1 || b>=1){
            int x = (a%10 + b%10);
            if(carry) x++;
            if(x >= 10){
                ans++;
                carry = true;
            }else{
                carry = false;
            }
            a /= 10;
            b /= 10;
        }
        if(ans == 0) cout<<"No carry operation."<<endl;
        else if(ans == 1) cout<<ans<<" carry operation."<<endl;
        else cout<<ans<<" carry operations."<<endl;
    }
    return 0;
}