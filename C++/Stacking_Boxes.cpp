#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


struct BOX{
    int pos;
    vector<int> len;

    BOX(int i = 0, int n = 0, int value = 0){
        pos = i;
        len = vector<int>(n, value);
    }
};

bool isboxcontained(BOX &a, BOX &b){
    for(int i = 0; i<a.len.size(); i++){
        if(a.len[i] <= b.len[i]) return false;
    }
    return true;
}

void printBox(vector<int> &prepos, vector<BOX> &boxSequence, int lastbox, bool printSpace){
    if(lastbox == -1) return ;
    printBox(prepos, boxSequence, prepos[lastbox], true);
    printf("%d", boxSequence[lastbox].pos);
    if(printSpace) printf(" ");
}

bool boxCompare(BOX &a, BOX &b){
    for(int i = 0; i < a.len.size(); i++){
        if(a.len[i] < b.len[i]) return true;
        if(a.len[i] > b.len[i]) return false;
    }
    return true;
}

int main(){
    int boxes[30][10] = {0}, number, dimension;
    while(scanf("%d %d", &number, &dimension) != EOF){
        vector<BOX> boxSequence;
        for(int i = 0; i<number; i++){
            BOX box(i+1, dimension, 0);
            for(int j = 0; j<dimension; j++){
                cin >> box.len[j];
            }
            sort(box.len.begin(), box.len.end());
            boxSequence.push_back(box);
        }
        sort(boxSequence.begin(), boxSequence.end(), boxCompare);
        vector<int> maxlen(number, 1), prepos(number, -1);
        int maxlength = 1, lastbox = 0;
        for(int i = 0; i < boxSequence.size(); i++){
            for(int j = 0; j<i; j++){
                if(isboxcontained(boxSequence[i], boxSequence[j])){
                    if(maxlen[j]+1 > maxlen[i]){
                        maxlen[i] = maxlen[j]+1;
                        prepos[i] = j;
                        if(maxlen[i] > maxlength){
                            maxlength = maxlen[i];
                            lastbox = i;
                        }
                    }
                }
            }
        }
        printf("%d\n", maxlength);
        printBox(prepos, boxSequence, lastbox, false);
        printf("\n");
        
    }
    return 0;
}