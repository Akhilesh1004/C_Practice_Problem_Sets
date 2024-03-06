#include <iostream>

using namespace std;

void reversestring(string& s){
    string s1;
    for(int i = s.size()-1; i>=0; i--){
        s1 += s[i];
    }
    s = s1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin, s)){
        string s2, s1;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                reversestring(s2);
                s1 += s2;
                s1 += ' ';
                s2 = "";
            }else if(i == s.size()-1){
                s2 += s[i];
                reversestring(s2);
                s1 += s2;
            }else{
                s2 += s[i];
            }
        }
        cout<<s1+"\n";
    }
    return 0;
}