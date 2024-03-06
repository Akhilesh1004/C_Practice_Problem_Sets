#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n){
        while(n--){
            int a, b;
            cin>>a>>b;
            if(a < b) cout<<"<\n";
            else if(a > b) cout<<">\n";
            else if( a== b ) cout<<"=\n";
        }
    }
    return 0;
}