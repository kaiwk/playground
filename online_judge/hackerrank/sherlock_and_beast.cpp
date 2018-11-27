#include <cstdio>

int T;
int n;

int main(){

    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d", &n);
        int n5 = 0, n3 = 0;
        n5 = n;
        n3 = n - n5;

        for(;;){

            if(n5 % 3 == 0 && n3 % 5 == 0){
                for(int i = 0; i < n5; ++i){ printf("5"); }
                for(int i = 0; i < n3; ++i){ printf("3"); }
                printf("\n");
                break;
            }

            if(n5 == 0){ printf("-1\n"); break; }

            --n5;
            ++n3;
        }
    }

    return 0;
}
