#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int T;
int N;
long M;
LL e[100000];
LL res;

LL find_(LL a[], int l, int mid, int r){
    LL sum = 0;
    LL ls = 0;
    for(int i = mid; i >= l; --i){
        sum += a[i];
        if(sum > ls){ ls = sum; }
    }

    sum = 0;
    LL rs = 0;
    for(int i = mid+1; i <= r; ++i){
        sum += a[i];
        if(sum > rs){ rs = sum; }
    }

    return ls + rs;
}

LL find_max(LL a[], int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        return max(max(find_max(a, l, mid), find_max(a, mid+1, r)), find_(a, l, mid, r));
    }
    return 0;
}

int main(){
    freopen("input", "r", stdin);
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d %ld", &N, &M);
        for(int i = 0; i < N; ++i){ scanf("%lld", &e[i]); }

        res = find_max(e, 0, N-1) % M;

        printf("%lld\n", res);
    }
    return 0;
}
