#include <iostream>
#include <cmath>

using namespace std;



int main(){
    string x, y;
    while(cin>>x>>y){
        int x2 = 1, y2 = 1;
        int x1 = 0, y1 = 0;
        for(int i = 0; i<x.size(); i++){
            if(x[i] >= '0' && x[i] <= '9')x2 = max(x2, x[i]-'0');
            else x2 = max(x2, x[i]-'A'+10);
        }
        for(int i = 0; i<y.size(); i++){
            if(y[i] >= '0' && y[i] <= '9')y2 = max(y2, y[i]-'0');
            else y2 = max(y2, y[i]-'A'+10);
        }
        //cout<<x2+1<<" "<<y2+1<<"\n";
        bool check = false;
        for(int i = x2+1; i<=36; i++){
            for(int j = y2+1; j<=36; j++){
                x1 = 0, y1 =0;
                for(int z = 0; z<x.size(); z++){
                    if(x[z] >= '0' && x[z] <= '9') x1 += int(x[z]-'0')*pow(i, x.size()-1-z);
                    else x1 += int(x[z]-'A'+10)*pow(i, x.size()-1-z);
                }
                for(int z = 0; z<y.size(); z++){
                    if(y[z] >= '0' && y[z] <= '9') y1 += int(y[z]-'0')*pow(j, y.size()-1-z);
                    else y1 += int(y[z]-'A'+10)*pow(j, y.size()-1-z);
                }
                if(x1 == y1){
                    cout<<x+" (base "<<i<<") = "+y+" (base "<<j<<")\n";
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        if(!check) cout<<x+" is not equal to "+y+" in any base 2..36\n";
    }
    return 0;
}