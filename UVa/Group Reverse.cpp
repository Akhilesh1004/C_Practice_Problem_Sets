#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
string s;
int t;

void exchange(int x, int y){
    for(int i = 0; i<t/2; i++){
        char temp = s[x+i];
        s[x+i] = s[y-i];
        s[y-i] = temp;
    }
}

int main(){
    int n;
    while(cin>>n&& n!=0){
        cin>>s;
        t = s.size()/n;
        int i = 0;
        while(n--){
            exchange(i, i+t-1);
            i += t;
        }
        cout<<s<<endl;
    }
}