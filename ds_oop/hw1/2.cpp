#include <iostream>

using namespace std;

int arr[305][305];

int main(){
    int n;
    cin>>n;
    for(int t = 1; t<=n; t++){
        int m;
        cin>>m;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        int x = 0, y = 0, index = 1;
        bool check = true;
        while(x < m && y < m){
            if(!check) break;
            index = 1;
            while(x-index >=0 && y-index >= 0){
                if(arr[x-index][y] != arr[x][y-index]){
                    check = false;
                    break;
                }
                index++;
            }
            x++;
            y++;
        }
        cout<<"Test #"<<t;
        if(check) cout<<": Symmetric.\n";
        else cout<<": Non-symmetric.\n";
    }
}