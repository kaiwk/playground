#include <cstdio>

long long dp[30];
int a, b;
int n;

int main(){

    scanf("%d %d %d", &a, &b, &n);
    dp[1] = a, dp[2] = b;

    for(int i = 3; i <= n; ++i){
        dp[i] = dp[i-1] * dp[i-1] + dp[i-2];
    }

    printf("%lld\n", dp[n]);

    return 0;
}
