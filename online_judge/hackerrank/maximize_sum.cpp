#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned long long ULL;

/* (a+b)%m = (a%m + b%m)%m */
/* prefix[n] = (a1 + a2 + .. + ai)%m = (a1%m + a2%m + .. + a1%m)%m */
/* modulo[i..j] = (ai + .. + aj)%m = prefix[j] - prefix[i-1] */

int T;
int N;
ULL M;
pair<ULL, int> prefix[100000];

int main(){

    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        scanf("%d %llu", &N, &M);

        for(int i = 0; i < N; ++i){
            scanf("%llu", &prefix[i].first);
            prefix[i].second = i;
        }

        prefix[0].first = prefix[0].first % M;
        ULL maxv = prefix[0].first;
        for(int i = 1; i < N; ++i){
            prefix[i].first = (prefix[i-1].first % M + prefix[i].first % M) % M;
            maxv = max(maxv, prefix[i].first);
        }

        sort(prefix, prefix+N);

        ULL minv = ULONG_MAX;
        for(int i = 1; i < N; ++i){
            if(prefix[i-1].second > prefix[i].second){
                minv = min(minv, prefix[i].first-prefix[i-1].first);
            }
        }
        printf("%llu\n", max(maxv, M-minv));
    }

    return 0;
}
