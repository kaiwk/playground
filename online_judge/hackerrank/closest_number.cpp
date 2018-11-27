#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> a;
vector<int> res;
int n;

int main(){
    freopen("input", "r", stdin);
    cin >> n;
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    int m = INT_MAX;
    for(int i = 1; i < n; ++i){
        if (m > a[i]-a[i-1]) {
            res.resize(0);
            m = a[i] - a[i-1];
            res.push_back(a[i-1]);
            res.push_back(a[i]);
        }else if (m == a[i]-a[i-1]){
            res.push_back(a[i-1]);
            res.push_back(a[i]);
        }
    }



    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
}
