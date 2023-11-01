#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            int x, y;
            cin>>x>>y;
            if(x>y) cout<<">"<<endl;
            else if(x<y) cout<<"<"<<endl;
            else if(x == y) cout<<"="<<endl;
        }
    }
    return 0;
}