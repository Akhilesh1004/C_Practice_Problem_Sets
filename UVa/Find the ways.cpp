#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    while(cin>>n>>k){
        double res = 0;
        for(int i = 1; i<=n; i++) res += log10(i);
        for(int i = 1; i<=k; i++) res -= log10(i);
        for(int i = 1; i<=(n-k); i++) res -= log10(i);
        cout<<(int)(res+1e-7)+1<<"\n";
    }
    return 0;
}