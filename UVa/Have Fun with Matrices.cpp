#include <iostream>

using namespace std;

int arr[15][15], arr2[15][15];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin>>n;
    for(int t = 1; t<=n; t++){
        cin>>m;
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                char temp;
                cin>>temp;
                arr[i][j] = temp-'0';
            }
        }
        int q, x, y;
        cin>>q;
        while(q--){
            cin>>s;
            switch(s[0]){
                case 'r':
                    cin>>x>>y;
                    for(int i = 1; i<=m; i++){
                        int temp;
                        temp = arr[x][i];
                        arr[x][i] = arr[y][i];
                        arr[y][i] = temp;
                    }
                    break;
                case 'c':
                    cin>>x>>y;
                    for(int i = 1; i<=m; i++){
                        int temp;
                        temp = arr[i][x];
                        arr[i][x] = arr[i][y];
                        arr[i][y] = temp;
                    }
                    break;
                case 'i':
                    for(int i = 1; i<=m; i++){
                        for(int j = 1; j<=m; j++){
                            arr[i][j] = (arr[i][j]+1)%10;
                        }
                    }
                    break;
                case 'd':
                    for(int i = 1; i<=m; i++){
                        for(int j = 1; j<=m; j++){
                            arr[i][j] = (arr[i][j]+9)%10;
                        }
                    }
                    break;
                case 't':
                    for(int i = 1; i<=m; i++){
                        for(int j = 1; j<=m; j++){
                            arr2[j][i] = arr[i][j];
                        }
                    }
                    for(int i = 1; i<=m; i++){
                        for(int j = 1; j<=m; j++){
                            arr[i][j] = arr2[i][j];
                        }
                    }
                    break;
            }
        }
        cout<<"Case #"<<t<<"\n";
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}