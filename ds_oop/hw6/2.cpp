#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

int lcm(int x, int y){
    return ((x*y)/gcd(x, y));
}*/

int s_to_int(string s){
    int p = 1, answer = 0;
    for(int i = s.size()-1; i>=0; i--){
        answer += p*int(s[i]-'a'+1);
        p *= 32;
    }
    return answer;
}

/*bool check(vector<int>dp, int c){
    for(int i = 0; i<dp.size(); i++){
        for(int j = i+1; j<dp.size(); j++){
            if((c/dp[i])%dp.size() == (c/dp[j])%dp.size()) return false;
        }
    }
    return true;
}*/

int main(){
    int n;
    cin>>n;
    cin.ignore();
    //cin.ignore();
    while(n--){
        string s, temp;
        getline(cin, s);
        vector<string>dp1;
        vector<int>dp2;
        stringstream ss("");
        ss << s;
        while(ss >> temp){
            dp1.push_back(temp);
            dp2.push_back(s_to_int(temp));
        }
        /*for(int i = 0; i<s.size(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }else{
                //dp1.push_back(temp);
                dp2.push_back(s_to_int(temp));
                temp = "";
            }
        }*/
        //dp1.push_back(temp);
        //dp2.push_back(s_to_int(temp));
        sort(dp2.begin(), dp2.end());
        int c = dp2[0];
        //for(int i = 0; i<dp1.size(); i++){
        //     cout<<dp1[i]<<" "<<dp2[i]<<"\n";
        //}
        while(true){
            bool check = false;
            for(int i = 0; i<dp2.size(); i++){
                for(int j = i+1; j<dp2.size(); j++){
                    if((c/dp2[i])%dp2.size() == (c/dp2[j])%dp2.size()){
                        c = min((c/dp2[i] + 1)*dp2[i], (c/dp2[j] + 1)*dp2[j]);
                        check = true;
                    }
                }
            }
            if(!check) break;
        }
        cout<<s+"\n";
        cout<<c<<"\n\n";
    }
    return 0;
}