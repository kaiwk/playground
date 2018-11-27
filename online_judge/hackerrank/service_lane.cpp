#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int T;
int N;
int i, j;
int a[100000];

int main(){

    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }

    for(int t = 0; t < T; ++t){
        scanf("%d %d", &i, &j);
        int minz = INT_MAX;
        for(int m = i; m <= j; ++m){
            minz = min(a[m], minz);
        }
        printf("%d\n", minz);
    }

    return 0;
}

