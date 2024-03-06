#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ans, s;
    int a, b;
    while(cin>>s>>a>>b){
        ans = "";
        int temp  = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] <= '9' && s[i] >= '0') temp += int(s[i]-'0')*pow(a, s.size()-1-i);
            else if(s[i] <= 'F' && s[i] >= 'A') temp += (int(s[i]-'A')+10)*pow(a, s.size()-1-i);
        }
        //cout<<temp<<"\n";
        if(temp == 0){
            cout<<"      0\n";
            continue;
        }
        for(int i = 0; i<7; i++, temp/=b){
            if(temp){
                if(temp%b < 10) ans = char('0'+temp%b)+ans;
                else ans = char('A'+(temp%b)%10)+ans;
            }
            else ans = ' '+ans;
        }
        if(temp) cout<<"  ERROR\n";
        else cout<<ans+"\n";
    }
    return 0;
}