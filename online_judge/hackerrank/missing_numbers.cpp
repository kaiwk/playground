#include <iostream>
#include <vector>

using namespace std;

int n, m;
int a[10000] = {0}, b[10000] = {0};

int main() {

    freopen("input", "r", stdin);
    cin >> n;

    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        ++a[tmp];
    }
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> tmp;
        ++b[tmp];
    }

    vector<int> res;
    for(int i = 0; i < 10000; ++i) {
        if (a[i] != b[i]) res.push_back(i);
    }

    int vsize = res.size();
    for (int i = 0; i < vsize; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
