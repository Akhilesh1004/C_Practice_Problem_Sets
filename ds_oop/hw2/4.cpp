#include <iostream>
#include <map>

using namespace std;

string change(string s, int k){
    for(int i = 0; i<s.size(); i++){
        if(i+k-1 >= s.size())break;
        for(int j = 0; j<(k)/2; j++){
            swap(s[i+j], s[i+k-1-j]);
        }
    }
    return s;
}

int main(){
    int n;
    string s, s1, s2;
    cin>>n;
    for(int i = 0; i<n; i++){
        char temp;
        cin>>temp;
        s += temp;
    }
    map<string, int>memo;
    memo[s] = 1;
    s2 = s;
    for(int k = 2; k<=n; k++){
        s1 = change(s, k);
        if(!memo.count(s1)) memo[s1] = k;
        if(s1 < s2) s2 = s1;
    }
    cout<<s2+"\n";
    cout<<memo[s2]<<"\n";
    return 0;
}