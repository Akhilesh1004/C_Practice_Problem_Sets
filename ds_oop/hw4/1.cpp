#include <iostream>

using namespace std;

string solve(string s1, string s2, int index, int x, int y){
    if(x == y){
        string temp = "";
        temp += s2[x];
        return temp;
    }
    int i = 0;
    while(s1[index] != s2[x+i]) i++;
    if(i == 0) return solve(s1, s2, index+(i+1), x+i+1, y)+s2[x+i];
    else if(x+i == y) return solve(s1, s2, index+1, x, x+(i-1))+s2[x+i];
    else return solve(s1, s2, index+1, x, x+(i-1))+solve(s1, s2, index+(i+1), x+i+1, y)+s2[x+i];
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int index = 0;
    string result = solve(s1, s2, 0, 0, s1.size()-1);
    cout<<result<<"\n";
    return 0;
}