#include <iostream>

using namespace std;

int top[30], blocks[30][30], position[30][5];

void init_stack(int a){
    int temp;
    for(int i = position[a][1]+1; i < top[position[a][0]]; i++){
        temp = blocks[position[a][0]][i];
        position[temp][0] = temp;
        position[temp][1] = top[temp];
        blocks[temp][top[temp]++] = temp;
    }
    top[position[a][0]] = position[a][1]+1;
}

void add_onto(int a, int b){
    int temp, pos, len, initx, inity;
    initx = position[a][0];
    inity = position[a][1];
    len = top[position[a][0]];
    top[position[a][0]] = position[a][1];
    for(int i = inity; i < len; i++){
        temp = blocks[initx][i];
        pos = position[b][0];
        position[temp][0] = position[b][0];
        position[temp][1] = top[pos];
        blocks[pos][top[pos]++] = temp;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        top[i] = 1;
        position[i][0] = i;
        position[i][1] = 0;
        blocks[i][0] = i;
    }
    string a1, a2;
    int a, b;
    while(cin>>a1 && a1 != "quit"){
        cin>>a>>a2>>b;
        if(position[a][0] == position[b][0]) continue;
        if(a1 == "move"){
            init_stack(a);
            if(a2 == "onto"){
                init_stack(b);
                add_onto(a, b);
            }else if(a2 == "over"){
                add_onto(a, b);
            }
        }else if(a1 == "pile"){
            if(a2 == "onto"){
                init_stack(b);
                add_onto(a, b);
            }else if(a2 == "over"){
                add_onto(a, b);
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<i<<":";
        for(int j = 0; j<top[i]; j++){
            cout<<" "<<blocks[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
