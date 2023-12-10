#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    string s;
    string result = "";
    char flag;
    while(cin>>s && s != "~"){
        if(s == "#"){
            int num = 0;
            for(int i = 0; i<result.size(); i++){
                if(i) num*=2;
                if(result[i] == '1') num += 1;
            }
            cout<<num<<endl;
            num = 0;
            result = "";
        }
        else if(s.size() == 1) flag = '1';
        else if(s.size() == 2) flag = '0';
        else{
            for(int i = 0; i<s.size()-2; i++){
                result += flag;
            }
        }
    }
    return 0;
}