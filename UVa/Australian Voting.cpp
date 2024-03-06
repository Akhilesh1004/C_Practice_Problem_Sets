#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int arr[2500][25], vote[25];
string name[25];

int main(){
    int n, m, a1, a2, a3;
    cin>>n;
    for(int t = 0; t<n; t++){
        if(t) cout<<"\n";
        memset(arr, 0, sizeof(arr));
        memset(vote, 0, sizeof(vote));
        cin>>m;
        cin.ignore();
        for(int i = 1; i<=m; i++){
            getline(cin, name[i]);
        }
        int index = 0, ma = 0, mi = 100000, y = 0;
        string s;
        while(getline(cin, s) && s[0]){
            y = 0;
            for(int i = 0; i<s.size(); i++){
                int temp = 0;
                while(s[i] >= '0' && s[i] <='9'){
                    temp *= 10;
                    temp += (s[i]-'0');
                    i++;
                }
                arr[index][y] = temp;
                y++;
            }
            vote[arr[index][0]]++;
            index++;
        }
        for(int i = 1; i<=m; i++){
            ma = max(ma, vote[i]);
            mi = min(mi, vote[i]);
        }
        /*for(int i = 0; i<index; i++){
            cout<<arr[i][0];
            for(int j = 1; j<m; j++){
                cout<<" "<<arr[i][j];
            }
            cout<<"\n";
        }*/
        map<int, int>memo;
        while(1){
            vector<int>win;
            for(int i = 1; i<=m; i++){
                if(memo.count(i)) continue;
                if(vote[i] == ma) win.push_back(i);
                else if(vote[i] == mi) memo[i] = 1;
            }
            /*cout<<"max min  ";
            cout<<ma<<" "<<mi<<"\n";
            cout<<"check ";
            cout<<vote[win[0]]*2<<" "<<index<<"\n";*/
            if(vote[win[0]]*2 >= index || mi == ma){
                for(int i = 0; i<win.size(); i++){
                    cout<<name[win[i]]<<"\n";
                }
                break;
            }
            ma = 0, mi = 200000;
            memset(vote, 0, sizeof(vote));
            for(int i = 0; i<index; i++){
                int x = 0;
                while(memo.count(arr[i][x])) x++;
                vote[arr[i][x]]++;
            }
            for(int i = 1; i<=m; i++){
                if(memo.count(i)) continue;
                ma = max(ma, vote[i]);
                mi = min(mi, vote[i]);
            }
        }
    }
    return 0;
}