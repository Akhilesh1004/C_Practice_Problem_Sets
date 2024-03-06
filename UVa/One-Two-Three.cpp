#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(string s){
    if(s.size() == 3){
        string g = "one";
        int result = 0;
        for(int i = 0; i<3; i++){
            if(g.find(s[i]) == i) result++;
        }
        if(result>=2) return 1;
        else return 2;
    }
    else return 3;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    while(cin>>n){
        for(int i = 0; i<n; i++){
            cin>>s;
            cout<<compare(s)<<"\n";
        }
    }
    return 0;
}