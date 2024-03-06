#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z;
    int index = 1;
    while(cin>>x>>y>>z && (x+y+z)!=0){
        cout<<"Case "<<index<<":\n";
        int h = 2*z+1, w = 2*z+1;
        for(int i = 1; i<=h; i++){
            if(i%2 == 0){
                for(int s = 0; s<x; s++){
                    for(int j = 1; j<=w; j++){
                        if(j%2 == 0){
                            for(int k = 0; k<x; k++) cout<<".";
                        }else{
                            for(int k = 0; k<y; k++) cout<<"*";
                        }
                    }
                    cout<<"\n";
                }
            }else{
                for(int s = 0; s<y; s++){
                    for(int j = 0; j<y*(z+1)+x*z; j++) cout<<"*";
                    cout<<"\n";
                }
            }
        }
        cout<<"\n";
        index++;
    }
    return 0;
}