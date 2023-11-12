#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

int LCS(string a, string b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>>lcs(n+1, vector<int>(m+1));
    if(n == 0 || m == 0) return 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }
    return lcs[n][m];
}

void solve(int i, int j, vector<char>&lcsword, vector<string>&result, string a, string b, vector<vector<int>>lcs){
    if(i == 0 || j == 0){
        if(lcsword.size() == lcs[a.size()][b.size()]){
            string r = "";
            for(int z = lcs[a.size()][b.size()]-1; z>=0; z--){
                r += lcsword[z];
            }
            result.push_back(r);
        }
        return ;
    }
    if(a[i-1] == b[j-1]){
        lcsword.push_back(a[i-1]);
        solve(i-1, j-1, lcsword, result, a, b, lcs);
        lcsword.pop_back();
    }else{
        if(lcs[i-1][j] >= lcs[i][j-1]){
            solve(i-1, j, lcsword, result, a, b, lcs);
        }
        if(lcs[i][j-1] >= lcs[i-1][j]){
            solve(i, j-1, lcsword, result, a, b, lcs);
        }
    }
}

vector<string> LCS_all(string a, string b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>>lcs(n+1, vector<int>(m+1, 0));
    if(n == 0 || m == 0) return {};
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    vector<char>lcsword;
    vector<string>result;
    solve(a.size(), b.size(), lcsword, result, a, b, lcs);
    return result;
}

string LCS_word(string a, string b){
    int n = a.size();
    int m = b.size();
    vector<vector<int>>lcs(n+1, vector<int>(m+1));
    if(n == 0 || m == 0) return 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }
    vector<char>lcsword(lcs[n][m]);
    int i = a.size(), j = b.size(), index = 0;
    while(i >= 1 && j >= 1){
        int v = lcs[i][j];
        while(i>1 && lcs[i-1][j] == v) i--;
        while(j>1 && lcs[i][j-1] == v) j--;
        if(v>0){
            lcsword[lcs[n][m] - index - 1] = a[i-1];
            index++;
        }
        i--;
        j--;
    }
    string result = "";
    for(int z = 0; z<lcs[n][m]; z++){
        result += lcsword[z];
    }
    return result;
}
int main(){
    string a, b;
    while(getline(cin, a)){
        getline(cin, b);
        /*
        int result = LCS(a, b);
        string sresult = LCS_word(a, b);
        cout<<result<<endl;
        cout<<sresult<<endl;*/
        vector<string>result = LCS_all(a, b);
        set<string>s(result.begin(), result.end());
        result.assign(s.begin(), s.end());
        for(int i = 0; i<result.size(); i++){
            cout<<result[i]<<endl;
        }
    }
    return 0;
}