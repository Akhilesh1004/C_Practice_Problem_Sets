#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

string d = "0123456789";

int main(){
    string s;
    int result = -1;
    while(getline(cin, s) && !cin.eof()){
        stack<int>stk;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' ') continue;
            if(d.find(s[i]) != -1){
                int num = 0;
                int j = i;
                while(d.find(s[i]) != -1){
                    i--;
                }
                i++;
                for(int k = i; k<=j; k++){
                    num = num*10+(s[k]-'0');
                }
                stk.push(num);
            }else{
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                switch(s[i]){
                    case '+':
                        stk.push(num1+num2);
                        break;
                    case '-':
                        stk.push(num1-num2);
                        break;
                    case '/':
                        stk.push(num1/num2);
                        break;
                    case '%':
                        stk.push(num1%num2);
                        break;
                    case '*':
                        stk.push(num1*num2);
                        break;
                }
            }
        }
        result = stk.top();
        cout<<result<<endl;
    }
    return 0;
}