#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin>>n){
        for(int i = 1; i<=n; i++){
            cin>>m;
            vector<int>a(m);
            int high = 0, low = 0;
            cin>>a[0];
            for(int j = 1; j<m; j++){
                cin>>a[j];
                if(a[j] > a[j-1]) high++;
                else if(a[j] < a[j-1]) low++;
            }
            cout<<"Case "<<i<<": "<<high<<" "<<low<<endl;
        }
    }
    return 0;
}