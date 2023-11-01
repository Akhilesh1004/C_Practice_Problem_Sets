#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m){
        long long int now = 0, result = 0, left = m;
        vector<long long int>a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int lim = (n-m)*2;
        for(int i = 0; i*2<lim; i++){
            result += (a[i]+a[lim-i-1])*(a[i]+a[lim-i-1]);
        }
        for(int i = lim; i<n; i++){
            result += a[i]*a[i];
        }
        cout<<result<<endl;
    }
    return 0;
}