#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int t, m, n;

int my_bs(vector<pair<int, int> > a, int target) {
    int n = a.size();
    int low = 0, high = n-1;
    int mid = (low+high) / 2;

    while(low <= high) {
	mid = (low + high) / 2;
	if (target < a[mid].first) high = mid - 1;
	else if (target > a[mid].first) low = mid + 1;
	else return a[mid].second;
    }
    return -1;
}

int main() {

    freopen("input", "r", stdin);
    cin >> t;

    while(t > 0){

	cin >> m >> n;
	vector<pair<int, int> > a;

	for(int i = 0; i < n; ++i){
	    pair<int, int> temp;
	    cin >> temp.first;
	    temp.second = i + 1;
	    a.push_back(temp);
	}

	sort(a.begin(), a.end());

	pair<int, int> x;
	for(int i = 0; i < n; ++i){
	    if (a[i].first >= m || a[i].first > ceil(m/2)) break;
	    x = a[i];
	    int index = my_bs(a, m-x.first);
	    if (index > -1 && index != x.second) {
		cout << min(x.second, index) << " " << max(index, x.second) << endl;
		break;
	    }
	}
	--t;
    }

    return 0;
}
