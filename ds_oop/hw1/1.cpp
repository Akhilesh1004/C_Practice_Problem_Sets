#include <iostream>
#include <map>

using namespace std;

map<char, char>memo = {
    {'A', 'A'},
    {'E', '3'},
    {'H', 'H'},
    {'I', 'I'},
    {'J', 'L'},
    {'L', 'J'},
    {'M', 'M'},
    {'O', 'O'},
    {'S', '2'},
    {'T', 'T'},
    {'U', 'U'},
    {'V', 'V'},
    {'W', 'W'},
    {'X', 'X'},
    {'Y', 'Y'},
    {'Z', '5'},
    {'1', '1'},
    {'2', 'S'},
    {'3', 'E'},
    {'5', 'Z'},
    {'8', '8'}
};

bool check_palin(string s){
    int mid = s.size()/2;
    int index = s.size()-1;
    for(int i = 0; i<mid; i++){
        if(s[i] != s[index-i]) return false;
    }
    return true;
}

bool check_mrror(string s){
    string t;
    for(int i = s.size()-1; i>=0; i--){
        if(memo.count(s[i])) t += memo[s[i]];
        else t += s[i];
    }
    if(t == s) return true;
    else return false;
}

int main(){
    string s;
    while(cin>>s){
        bool mirror = check_mrror(s); 
        bool palin = check_palin(s);
        cout<<s;
        if(mirror && palin) cout<<" -- is a mirrored palindrome.\n";
        else if(mirror) cout<<" -- is a mirrored string.\n";
        else if(palin) cout<<" -- is a regular palindrome.\n";
        else cout<<" -- is not a palindrome.\n";
    }
    return 0;
}