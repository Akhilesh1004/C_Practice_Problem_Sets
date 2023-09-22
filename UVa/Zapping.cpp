#include <iostream>
#include <stdint.h>

using namespace std;

void sort_(int &s, int &n){
    int temp;
    if(s > n){
        temp = s;
        s = n;
        n = temp;
    }
}

int main(){
    int s, n, ans, ans1;
    while(cin>>s>>n){
        sort_(s, n);
        ans = n-s;
        ans1 = 99-n+s+1;
        if(ans>=ans1) cout<<ans1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}