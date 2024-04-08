#include <iostream>
#include <string>

using namespace std;

bool check(string s, int x, int y){
    if(x > y) return false;
    if(x == y) return true;
    int mid = (y)/2;
    for(int i = 0; i<mid; i++){
        if(s[x+i] != s[y-i]) return false;
    }
    return true;
}

int main() {
    // Implement your solution here
    string S;
    cin>>S;
    int x = 0, y = S.size()-1;
    int result = 0;
    while(check(S, x, y)){
        x++;
        result++;
    }
    cout<<result<<"\n";
    return 0;
}