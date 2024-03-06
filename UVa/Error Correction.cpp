#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n!=0){
        int temp, row = -1, column = -1;
        vector<int>rows(n, 0), columns(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>temp;
                rows[i]+=temp;
                columns[j]+=temp;
            }
            if(rows[i]%2 != 0) row = i+1;
        }
        bool check = false;
        for(int i = 0; i<n; i++){
            if(columns[i]%2 != 0 ){
                if(column != -1){
                    check = true;
                    break;
                }
                column = i+1;
            }
        }
        if(row == -1 && column == -1) cout<<"OK\n";
        else if((row == -1 || column == -1) || check)cout<<"Corrupt\n";
        else cout<<"Change bit ("<<row<<","<<column<<")\n";
    }
    return 0;
}