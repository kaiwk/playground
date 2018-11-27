#include<cstdio>

int n;

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        for(int k = 0; k < n-i-1; ++k){
            printf(" ");
        }
        for(int k = 0; k < i+1; ++k){
            printf("#");
        }
        printf("\n");
    }

}
