#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve(vector<string> ss, map<string, pair<int, int>>&memo, vector<vector<string>>&result){
    for(int i = 0; i<ss.size(); i++){
        int j = 0;
        string temp = "";
        pair<int, int>node;
        int pos = i, index = 0;
        while(ss[i][j]){
            if(ss[i][j] != '\\'){
                temp += ss[i][j];
            }else{
                result[i].push_back(temp);
                if(memo.find(temp) == memo.end()){
                    memo[temp] = {pos, index};
                    result[pos][index] = temp;
                    index++;
                }else{
                    node = memo[temp];
                    pos = node.first;
                    index = node.second;
                }
                temp = "";
            }
            j++;
        }
    }   
}

int main(){
    int n;
    while(cin>>n){
        vector<string>ss(n);
        for(int i = 0; i<n; i++){
            cin>>ss[i];
        }
        vector<vector<string>>result(100, vector<string>(100));
        map<string, pair<int, int>>memo;
        solve(ss, memo, result);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<result[i].size(); j++){
                for(int k = 0; k<j; k++) cout<<" ";
                cout<<result[i][j]<<endl;
            }
        }
    }
    return 0;
}