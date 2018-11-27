#include <cstdio>

int T;
int n;

int main(){
    scanf("%d", &T);

    for(int t = 0; t < T; ++t){
        scanf("%d", &n);

        int res = 1;
        for(int i = 1; i <= n; ++i){
            if(i%2 == 1){ res = res * 2; }
            else { ++res; }
        }

        printf("%d\n", res);
    }


    return 0;
}
