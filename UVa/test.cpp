#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int n, x, ans;
    while(cin>>n>>x){
        ans = 0;
        while(n+x >= 13 && x>0){
            n -= 12;
            x--;
            ans++;
            n++;
        }
        cout<<ans<<endl;
    }
    return 0;
}