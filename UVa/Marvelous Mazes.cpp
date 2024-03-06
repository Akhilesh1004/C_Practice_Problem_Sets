#include <iostream>

using namespace std;

int main(){
    string s;
    int index = 0;
    while(getline(cin, s)){
        if(index) {
            cout<<"\n";
            index = 0;
        }
        if(s.size() == 0) index++;
        int temp = 0;
        string result;
        for(int i = 0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                temp += int(s[i]-'0');
            }
            else if(s[i] == '!'){
                cout<<result+"\n";
                result = "";
            }
            else if(s[i] == 'b'){
                while(temp--) result += ' ';
                temp = 0;
            }else{
                while(temp--) result += s[i];
                temp = 0;
            }
        }
        if(s.size()) cout<<result+"\n";
    }
    return 0;
}