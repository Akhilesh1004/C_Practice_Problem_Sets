#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int f;
        cin>>f;
        vector<vector<int>>dp(f, vector<int>(3));
        for(int i = 0; i<f; i++){
            for(int j = 0; j<3; j++){
                cin>>dp[i][j];
            }
        }
        int total = 0;
        for(int i = 0; i<f; i++){
            total += dp[i][0]*dp[i][2];
        }
        cout<<total<<"\n";
    }
    return 0;
}