#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n){
        for(int i = 1; i<=n; i++){
            cin>>m;
            vector<int>a(m);
            for(int j = 0; j<m; j++){
                cin>>a[j];
            }
            int now = a[0];
            int high = 0, low = 0;
            for(int j = 1; j<m; j++){
                if(now < a[j]) high++;
                if(now > a[j]) low++;
                now = a[j];
            }
            cout<<"Case "<<i<<": "<<high<<" "<<low<<endl;
        }
    }
    return 0;
}