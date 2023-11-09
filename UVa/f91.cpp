#include <iostream>
#include <stdio.h>

using namespace std;

int f91(int n){
    if(n>=101) return n-10;
    return f91(f91(n+11));
}

int main(){
    int n;
    while(cin>>n && n != 0){
        cout<<"f91("<<n<<") = "<<f91(n)<<endl;
    }
    return 0;
}