#include <iostream>

using namespace std;

int main(){
    string s;
    int n, m;
    while(cin>>n>>m>>s){
        long long int temp = 0;
        bool check = false;
        for(int i = 0; i<s.size(); i++){
            temp *= n;
            if(s[i] >= '0' && s[i] <= '9'){
                if(int(s[i] - '0') >= n) check = true;
                temp += int(s[i] - '0');
            }
            else{
                if(int(s[i]-'A'+10) >= n) check = true;
                temp += int(s[i]-'A'+10);
            }
        }
        string ans;
        while(temp){
            if(temp%m < 10) ans += '0'+temp%m;
            else ans += 'A'+(temp%m)%10;
            temp /= m;
        }
        if(check) cout<<s+" is an illegal base "<<n<<" number";
        else{
            cout<<s+" base "<<n<<" = ";
            for(int i = ans.size()-1; i>=0; i--) cout<<ans[i];
            if(ans.size() == 0) cout<<0;
            cout<<" base "<<m;
        }
        cout<<"\n";
    }
    return 0;
}