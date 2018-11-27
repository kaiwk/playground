#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> v;
int n;
int x;
int a, b;
int tmp;

int main() {

	freopen("input", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	cin >> x;
	cin >> a >> b;

	v.erase(v.begin()+x-1);
	v.erase(v.begin()+a-1, v.begin()+b-1);

	cout << v.size() << endl;

	for (auto i : v) {
		cout << i << " ";
	}

	cout << endl;

	return 0;
}

