#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int x = 1; x<=t; x++){
        cout<<"Testcase #"<<x<<"\n";
        int n, m;
        cin>>n;
        map<int, int>memo;
        for(int i = 1; i<=n; i++){
            int k, temp;
            cin>>k;
            while(k--){
                cin>>temp;
                memo[temp] = i;
            }
        }
        cin>>m;
        string s;
        vector<int>q;
        int cur = -1, next = -1, index = 0;
        while(m--){
            cin>>s;
            if(s == "ENQUEUE"){
                int c;
                cin>>c;
                if(q.size() == 0) q.push_back(c);
                else {
                    bool check = true;
                    for(int i = q.size()-1; i>=index; i--){
                        if(memo[q[i]] == memo[c]){
                            q.insert(q.begin()+i+1, c);
                            check = false;
                            break;
                        }
                    }
                    if(check) q.push_back(c);
                }
            }else{
                cout<<q[index]<<"\n";
                index++;
            }
        }
    }
    return 0;
}