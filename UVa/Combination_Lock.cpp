#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n, a1, a2, a3, ans;
    while(cin>>n>>a1>>a2>>a3){
        ans = 360*3;
        ans += ((40+n-a1)%40)*9;
        ans += ((40+a2-a1)%40)*9;
        ans += ((40+a2-a3)%40)*9;
        cout<<ans<<endl;
    }
    return 0;
}