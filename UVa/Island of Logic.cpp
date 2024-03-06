#include <iostream>
#include <map>

using namespace std;

string X[55], buf, Ans[55], ans[55], days[2], saves[120][3];
string type[3] = {"divine.", "evil.", "human."};
char speakers[55];
map<char, int>memo;
map<char, string>memo2;

void solve(int n, int time){
    string t = time?"night.":"day.";
    bool check = true;
    for(int i = 0; i<n; i++){
        if(ans[i]=="day." || ans[i]=="night.") check = (t==ans[i]);
        else{
            char m = (X[i][0]=='I')?speakers[i]:X[i][0];
            if(ans[i] == "lying."){
                check = (memo2[m]=="human." && time)||(memo2[m]=="evil.");
            }else{
                check = (memo2[m]==ans[i]);
            }
        }
        if(Ans[i] == "not") check = !check;
        if(memo2[speakers[i]]=="divine." && !check) return ;
        if(memo2[speakers[i]]=="evil." && check) return ;
        if(memo2[speakers[i]]=="human." && check==time) return ;
    }
    days[time] = t;
    for(char a = 'A'; a<='E'; a++){
        if(!memo.count(a))continue;
        if(memo2[a]=="divine.") saves[a][0]="divine.";
        if(memo2[a]=="evil.") saves[a][1]="evil.";
        if(memo2[a]=="human.") saves[a][2]="human.";
    }

}

void dfs(char c, int n){
    while(c <= 'E' && !memo.count(c)) c++;
    if(c > 'E'){
        solve(n, 1);
        solve(n, 0);
        return ;
    }
    for(int i = 0; i<3; i++){
        memo2[c] = type[i];
        dfs(c+1, n);
    }
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n, index = 1;
    while(cin>>n && n!=0){
        memo.clear();
        memo2.clear();
        days[0]=days[1]="";
        for(char c = 'A'; c<='E'; c++){
            saves[c][0]=saves[c][1]=saves[c][2]="";
        }
        for(int i = 0; i<n; i++){
            cin>>speakers[i]>>buf>>X[i]>>buf>>Ans[i];
            if(Ans[i] == "not") cin>>ans[i];
            else ans[i] = Ans[i];
            memo[speakers[i]] = 1;
            if(X[i][0] != 'I') memo[X[i][0]] = 1;
        }
        dfs('A', n);
        cout<<"Conversation #"<<index++<<"\n";
        int sum = 0, sure = 0;
        for(char c = 'A'; c<='E'; c++){
            int count = 3;
            for(int i = 0; i<3; i++){
                count -= (saves[c][i]=="");
            }
            for(int i = 0; i<3; i++){
                if(count==1 && saves[c][i]!=""){
                    cout<<c<<" is "<<saves[c][i]<<"\n";
                    sure++;
                }
            }
            if(count>0)sum++;
        }
        if((days[0]=="" || days[1]=="") && (days[0]!="" || days[1]!="")){
            sum++;
            sure++;
            cout<<"It is "<<((days[0]!="")?days[0]:days[1])<<"\n";
        }
        if(!sum) cout<<"This is impossible.\n";
        else if(!sure)cout<<"No facts are deducible.\n";
        cout<<"\n";
    }
    return 0;
}