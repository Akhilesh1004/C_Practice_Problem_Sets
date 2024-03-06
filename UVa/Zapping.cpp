/*#include <iostream>
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
}*/

#include <iostream>

using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b && a!=-1){
        cout<<min((a-b+100)%100, (b-a+100)%100)<<"\n";
    }
    return 0;
}