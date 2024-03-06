#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s, s0, s1;
        getline(cin, s);
        getline(cin, s0);
        s0 = s0.substr(0, s0.size()-3);
        vector<string>substring1(2), substring2(2);
        int index = 0;
        for(int i = 0; i<s.size();){
            if(s[i] == '<'){
                while(s[++i] != '>'){
                    s1 += s[i];
                    substring1[index]+=s[i];
                }
                while(++i <s.size() && s[i] != '<'){
                    s1 += s[i];
                    substring2[index]+=s[i];
                }
                index++;
            }else{
                s1 += s[i];
                i++;
            }
        }
        s0 += substring1[1]+substring2[0]+substring1[0]+substring2[1];
        cout<<s1+"\n";
        cout<<s0+"\n";
    }
    return 0;
}