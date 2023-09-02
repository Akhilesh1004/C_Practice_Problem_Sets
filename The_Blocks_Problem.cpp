#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int n, a, b, blocks[25][25], top[25], position[25][2];

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
    string action1, action2;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i<n; i++){
            top[i] = 1;
            position[i][0] = i;
            position[i][1] = 0;
            blocks[i][0] = i;
        }
        while(cin >> action1 && action1 != "quit"){
            scanf("%d", &a);
            cin>>action2;
            scanf("%d", &b);
            if(position[a][0] == position[b][0]) continue;
            if(action1 == "move"){
                init_stack(a);
                if(action2 == "onto"){
                    init_stack(b);
                    add_onto(a, b);
                }
                if(action2 == "over"){
                    add_onto(a, b);
                }
            }
            if(action1 == "pile"){
                if(action2 == "onto"){
                    init_stack(b);
                    add_onto(a, b);
                }
                if(action2 == "over"){
                    add_onto(a, b);
                }
            }
        }
        for(int i = 0; i<n; i++){
            printf("%d:", i);
            for(int j = 0; j<top[i]; j++){
                printf(" %d", blocks[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}