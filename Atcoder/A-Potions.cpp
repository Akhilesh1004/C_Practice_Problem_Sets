#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n, h, x;
    while(scanf("%d %d %d", &n, &h, &x) != EOF){
        vector<int> p(n+5);
        int min = 0;
        p[0] = 1000;
        for(int i = 1; i<=n; i++){
            scanf("%d", &p[i]);
        }
        for(int i = 1; i<=n; i++){
            if(p[i]==(x-h)){
                min = i;
                break;
            }
            if(p[min]>p[i] && p[i]>(x-h)) min = i;
        }
        printf("%d\n", min);
    }
    return 0;
}