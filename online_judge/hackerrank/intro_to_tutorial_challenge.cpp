#include <cstdio>

int v;
int n;
int input;

int main(){

    scanf("%d %d", &v, &n);

    int index = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &input);
        if(input == v){ index = i; }
    }
    printf("%d\n", index);

    return 0;
}
