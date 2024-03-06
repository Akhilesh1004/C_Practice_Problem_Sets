#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z;
    while(cin>>x>>y>>z){
        double total = x+y;
        double cow = x-z;
        cout<<fixed<<setprecision(5)<<(x*(y/(cow-1+y)) + y*((y-1)/(y-1+cow)))/total<<"\n";
    }
    return 0;
}