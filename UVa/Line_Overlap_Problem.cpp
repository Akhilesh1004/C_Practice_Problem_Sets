/*#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main(){
    stringstream ss;
    int dp[200000][2], n = 0;
    string input;
    int total = 0;
    while(getline(cin, input)){
        if(input == ".") break;
        ss.clear();
        ss << input;
        ss >> dp[n][0] >> dp[n][1];
        n++;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(dp[i][0] >= dp[j][0] && dp[i][1] <= dp[j][1]){
                total += (dp[i][1] - dp[i][0]);
            }
            else if(dp[i][0] <= dp[j][0] && dp[i][1] >= dp[j][1]){
                total += (dp[j][1] - dp[j][0]);
            }
            else if(dp[i][0] <= dp[j][1] && dp[i][0] >= dp[j][0]){
                total += (dp[j][1] - dp[i][0]);
            }else if(dp[j][0] <= dp[i][1] && dp[j][0] >= dp[i][0]){
                total += (dp[i][1] - dp[j][0]);
            }
        }
    }
    cout<<total<<endl;
    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
    int start;
    int end;
};

bool compare(line &a, line &b){
    return a.start<b.start;
}

int main(){
    string s1, s2;
    vector<line>dp;
    while(cin>>s1 && s1!="."){
        cin>>s2;
        line l;
        int temp = 0;
        for(int i = 0; i<s1.size(); i++){
            temp *= 10;
            temp += s1[i]-'0';
        }
        l.start = temp;
        temp = 0;
        for(int i = 0; i<s2.size(); i++){
            temp *= 10;
            temp += s2[i]-'0';
        }
        l.end = temp;
        dp.push_back(l);
    }
    sort(dp.begin(), dp.end(), compare);
    int ans = 0;
    for(int i = 0; i<dp.size(); i++){
        cout<<dp[i].start<<" "<<dp[i].end<<"\n";
    }
    for(int i = 1; i<dp.size(); i++){
        if(dp[i].start < dp[i-1].end){
            if(dp[i].end < dp[i-1].end) ans += (dp[i].end-dp[i].start);
            else ans += (dp[i-1].end-dp[i].start);
        }
    }
    cout<<ans<<"\n";
    return 0;
}