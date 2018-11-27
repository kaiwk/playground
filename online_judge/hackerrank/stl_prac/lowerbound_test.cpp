#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int n;
int q;

int main(int argc, const char *argv[]) {

	freopen("input", "r", stdin);

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> q;
	int val;
	for (int i = 0; i < q; i++) {
		cin >> val;
		vector<int>::iterator low = lower_bound(v.begin(), v.end(), val);
		if (*low == val) {
			cout << "Yes ";
		}else {
			cout << "No ";
		}
		cout << low-v.begin()+1 << endl;
	}

	return 0;
}
