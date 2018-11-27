#include <cstdio>
#include <cstring>
#include <cstdlib>

int T;
char n[10];

int main(){
    scanf("%d", &T);

    for(int t = 0; t < T; ++t){
        scanf("%s", n);
        int cnt = 0;
        int num = atoi(n);
        int len = strlen(n);
        for(int i = 0; i < len; ++i){
            if(n[i] - '0' != 0){
                if(num % (n[i] - '0') == 0) { ++cnt; }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
