#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    bool flag = true;
    while(getline(cin, s)){
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '"' && flag){
                t += "``";
                flag = false;
            }
            else if(s[i] == '"' && !flag){
                t += "''";
                flag = true;
            }else{
                t += s[i];
            }
        }
        cout<<t+"\n";
        t = "";
    }
    return 0;
}