#include <iostream>
#include <vector>

using namespace std;

int sum;

int solve(vector<vector<string>>&card, vector<int>&top, int now, int move){
    int count = 0, temp = now;
    //cout<<"c0\n";
    while(count < move && temp >= 0){
        temp--;
        if(top[temp] >= 0){
            count++;
        }
    }
    //cout<<"c1\n";
    if(temp >= 0 && (card[now][top[now]][0]==card[temp][top[temp]][0] || card[now][top[now]][1]==card[temp][top[temp]][1])){
        top[temp]++;
        card[temp][top[temp]] = card[now][top[now]];
        top[now]--;
        if(top[now]<0)sum++;
        return temp;
    }
    //cout<<"c2\n";
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<string>>card(54, vector<string>(54));
    while(cin>>card[0][0] && card[0][0] != "#"){
        for(int i = 1; i<52; i++){
            cin>>card[i][0];
        }
        vector<int>top(54, 0);
        sum = 0;
        //cout<<"c\n";
        for(int i = 1; i<52; ){
            while(top[i]<0)i++;
            int temp = solve(card, top, i, 3);
            if(temp >= 0){
                i = temp;
            }else{
                temp = solve(card, top, i, 1);
                if(temp >= 0){
                    i = temp;
                }else{
                    i++;
                }
            }
        }
        cout<<(52-sum)<<" pile";
        if((52-sum)>1)cout<<"s";
        cout<<" remaining:";
        for(int i = 0; i<52; i++){
            if(top[i]>=0) cout<<" "<<top[i]+1;
        }
        cout<<"\n";
    }
    return 0;
}