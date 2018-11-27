#include <cstdio>

using namespace std;

int n;
int a[1000];

void print_arr(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){ scanf("%d", &a[i]); }
    int e = a[n-1];

    int i;
    for(i = n-2; e < a[i]; --i){
        a[i+1] = a[i];
        print_arr(a, n);
        printf("\n");
    }
    a[i+1] = e;
    print_arr(a, n);
    printf("\n");

    return 0;
}
