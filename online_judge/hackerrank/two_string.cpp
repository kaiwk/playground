#include <cstdio>
#include <cstring>

int T;
char a[1000000];
char b[1000000];

int az[26] = {0};
int bz[26] = {0};

char c[] = "abcdefghijklmnopqrstuvwxyz";

int main(){

    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%s %s", a, b);

        int ok = 0;
        for(int i = 0; i < strlen(c); ++i){
            if(strchr(a, c[i]) && strchr(b, c[i])){
                ok = 1;
                break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
