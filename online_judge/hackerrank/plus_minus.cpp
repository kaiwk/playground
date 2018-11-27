#include <cstdio>

int n;
int p = 0;
int ne = 0;
int z = 0;
int input = 0;

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &input);
        if(input == 0) ++z;
        else if(input > 0) ++p;
        else ++ne;
    }
    printf("%.6lf\n", 1.0*p/n);
    printf("%.6lf\n", 1.0*ne/n);
    printf("%.6lf\n", 1.0*z/n);

    return 0;
}
