#include <cstdio>

int T;
int n;
int k;

int main(){

    scanf("%d", &T);

    for(int t = 0; t < T; ++t){

        scanf("%d %d", &n, &k);

        int ontime = 0;
        for(int i = 0; i < n; ++i){
            int temp;
            scanf("%d", &temp);
            if(temp <= 0){ ++ontime; }
        }

        if(ontime >= k){
            printf("NO\n");
        }else printf("YES\n");

    }


    return 0;
}
