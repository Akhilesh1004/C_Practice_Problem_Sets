#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

bool isprime(int x){
    if(x<=1) return true;
    if(x%2 == 0) return false;
    for(int i = 3; i<x; i+=2){
        if(x%i == 0)  return false;
    }
    return true;
}

int main(){
    map<char, int>memo;
    for(int i = 0; i<26; i++){
        memo['a'+i] = i+1;
        memo['A'+i] = i+27;
    }
    string s;
    while(cin>>s){
        int total = 0;
        for(int i = 0; i<s.size(); i++){
            total += memo[s[i]];
        }
        if(isprime(total)) cout<<"It is a prime word."<<endl;
        else cout<<"It is not a prime word."<<endl;
    }
    return 0;
}