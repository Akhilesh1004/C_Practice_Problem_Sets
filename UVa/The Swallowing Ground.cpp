#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w;
    while(cin>>w){
        bool check = true;
        while(w--){
            if(!check){
                cout<<"\n";
            }
            check = false;
            int n, g = -1;
            bool flag = true;
            cin>>n;
            while(n--){
                int a, b;
                cin>>a>>b;
                if(g == -1) g = abs(a-b);
                else if(g != abs(a-b)) flag = false;
            }
            if(flag) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}