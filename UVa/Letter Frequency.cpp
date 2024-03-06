#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin>>n;
    map<char, int>memo;
    cin.ignore();
    while(n--){
        m = -1;
        memo.clear();
        getline(cin, s);
        for(int i = 0; i<s.size(); i++){
            if(s[i] <= 'z' && s[i] >= 'a'){
                memo[s[i]]++;
                m = max(m, memo[s[i]]);
            }else if(s[i] <= 'Z' && s[i] >= 'A'){
                char c = tolower(s[i]);
                memo[c]++;
                m = max(m, memo[c]);
            }
        }
        for(char j = 'a'; j<='z'; j++){
            if(memo.find(j) != memo.end()){
                if(memo[j] == m) cout<<j;
            }
        }
        cout<<"\n";
    }
    return 0;
}