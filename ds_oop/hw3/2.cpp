#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    int result = 0;
    vector<char>dp;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(') dp.push_back(s[i]);
        else{
            if(dp.size() == 0) result++;
            else dp.pop_back();
        }
    }
    cout<<result+dp.size()<<"\n";
    return 0;
}