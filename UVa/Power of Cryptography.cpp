#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, m;
    while(cin>>n>>m){
        cout<<fixed<<setprecision(0)<<pow(m, 1.0/n)<<"\n";
    }
    return 0;
}