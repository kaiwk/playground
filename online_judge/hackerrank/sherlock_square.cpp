#include <cstdio>
#include <cmath>

int T;
int a, b;

int main(){

    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d %d", &a, &b);

        int cnt = 0;
        int sb = sqrt(b);
        for(int i = 1; i < sb+1; ++i){
            int pows = pow(i, 2);
            if(pows >= a && pows <= b) ++cnt;
        }

        printf("%d\n", cnt);

    }

    return 0;
}
