#include <cstdio>
#include <algorithm>

using namespace std;


int n;
int a[1000];

void print_arr(int a[], int n){
    for(int i = 0; i < n; ++i){ printf("%d ", a[i]); }
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i < n; ++i){
        for(int j = i; j > 0; --j){
            if(a[j] < a[j-1]){ swap(a[j], a[j-1]); }
        }
        print_arr(a, n);
        printf("\n");
    }

    return 0;
}
