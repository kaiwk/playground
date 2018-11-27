#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int find_min(int a[], int n){
    int minv = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(a[i] != 0){ minv = min(minv, a[i]); }
    }
    if(minv == INT_MAX) return 0;
    else return minv;
}

int n;
int a[1000] = {0};
int cnt = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){ scanf("%d", &a[i]); }

    int cut = -1;
    while((cut = find_min(a, n)) != 0){
        cnt = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] != 0){ a[i] = a[i] - cut; ++cnt; }
        }
        printf("%d\n", cnt);
    }


    return 0;
}
