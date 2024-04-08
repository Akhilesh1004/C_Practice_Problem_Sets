#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s, s2;
    cin>>s;
    vector<char>dp;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ']'){
            vector<char>temp;
            while(dp.back() != '['){
                temp.push_back(dp.back());
                dp.pop_back();
            }
            dp.pop_back();
            string s3, s4;
            while(temp.size() != 0){
                s3 += temp.back();
                temp.pop_back();
            }
            int x = 0, base = 1;
            while(dp.size() != 0 && dp.back() >= '0' && dp.back() <= '9'){
                x += int(dp.back()-'0')*base;
                base *= 10;
                dp.pop_back();
            }
            for(int i = 0; i<x; i++) s4 += s3;
            if(dp.size() == 0) s2 += s4;
            else {
                for(int j = 0; j<s4.size(); j++) dp.push_back(s4[j]);
            }

        }else{
            dp.push_back(s[i]);
        }
    }
    cout<<s2+"\n";
    return 0;
}
