#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int a[3];
    bool check;
    while(cin>>a[0]>>a[1]>>a[2]){
        check = true;
        if(a[0]>=a[1]+a[2]) check = false;
        if(a[1]>=a[0]+a[2]) check = false;
        if(a[2]>=a[0]+a[1]) check = false;
        if(check){
            if(a[0]==a[1]&& a[1]==a[2]&&a[0]==a[2]) cout<<"Equilateral"<<endl;
            else if(a[0]==a[1]|| a[1]==a[2]|| a[0]==a[2]) cout<<"Isosceles"<<endl;
            else cout<<"Scalene"<<endl;
        }else{
            cout<<"Invalid"<<endl;
        }
    }
    return 0;
}