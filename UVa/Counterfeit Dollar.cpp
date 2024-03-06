#include <iostream>
#include <cstring>
#include <map>

using namespace std;

string arr[3][3];
int coin[15];
map<string, int>memo = {
    {"even", 0},
    {"up", -1},
    {"down", 1}
};

int solve(string s1, string s2){
    int r1 = 0, r2 = 0;
    for(int i = 0; i<s1.size(); i++){
        r1 += coin[s1[i]-'A'];
        r2 += coin[s2[i]-'A'];
    }
    return r2-r1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cin.ignore();
    for(int t = 1; t<=n; t++){
        bool check = false;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 0; i<12; i++){
            for(int j = 0; j<2; j++){
                memset(coin, 0, sizeof(coin));
                if(j) coin[i] = 1;
                else coin[i] = -1;
                check = true;
                for(int k = 0; k<3; k++){
                    if(solve(arr[k][0], arr[k][1]) != memo[arr[k][2]]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    cout<<(char)('A'+i)<<" is the counterfeit coin and it is ";
                    if(coin[i] > 0) cout<<"heavy.\n";
                    else cout<<"light.\n";
                    break;
                }
            }
            if(check) break;
        }
    }
    return 0;
}