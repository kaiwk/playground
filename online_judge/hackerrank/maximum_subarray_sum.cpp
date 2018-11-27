#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int T, N;
vector<int> a(100000, 0);
vector<int> dp(100000, 0);

int main () {

    freopen("input", "r", stdin);

    cin >> T;

    while(T > 0) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        dp[0] = a[0];
        int contiguous_max_sum = dp[0];
        for (int i = 1; i < N; ++i) {
            dp[i] = max(dp[i-1]+a[i], a[i]);
            contiguous_max_sum = max(contiguous_max_sum, dp[i]);
        }

        sort(a.begin(),a.begin()+N);
        int non_contiguous_max_sum = 0;
        if (a[N-1] < 0) non_contiguous_max_sum = a[N-1];
        for (int i = 0; i < N; ++i) {
            if(a[i] > 0) non_contiguous_max_sum += a[i];
        }

        cout << contiguous_max_sum << " " << non_contiguous_max_sum << endl;
        dp.assign(N, 0);
        --T;
    }

    return 0;
}
