#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    long long int n, x, y;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            cin>>x>>y;
            int a = (x+y)/2;
            int b = (x-y)/2;
            if((x+y)%2 == 1 || (x-y)%2 == 1 || a<0 || b<0){
                cout<<"impossible"<<endl;
            }else{
                cout<<max(a, b)<<" "<<min(a, b)<<endl;
            }
        }
    }
    return 0;
}