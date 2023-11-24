#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin>>s){
        for(int i = 0; i<s.size(); i++){
            s[i] = s[i]-7;
        }
        cout<<s<<endl;
    }
    return 0;
}