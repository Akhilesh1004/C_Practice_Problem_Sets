#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    while(cin>>a>>b){
        cout<<abs(a-b)<<"\n";
    }
    return 0;
}