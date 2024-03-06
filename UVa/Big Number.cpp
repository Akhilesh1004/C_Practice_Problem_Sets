#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n;
    while(n--){
        cin>>m;
        double res = 0;
        for(int i = 1; i<=m; i++){
            res += log10(i);
        }
        cout<<(int)(res+1e-7)+1<<"\n";
    }
    return 0;
}