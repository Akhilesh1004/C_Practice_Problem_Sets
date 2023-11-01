#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int a, b, c, ans = 0;
            cin>>a>>b>>c;
            a+=b;
            while(a/c != 0){
                ans += a/c;
                int remain = a/c;
                a = a%c+remain;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}