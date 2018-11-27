#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> vec;
int t;
int n;

int main() {

	freopen("input", "r", stdin);

	cin >> t;

	int tmp;
	for (int k = 0; k < t; k++) {
		cin >> n;
		vec.clear();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			sum += tmp;
			vec.push_back(tmp);
		}

		bool eq = false;
		int left = 0,
			right = sum;

		cout << *(vec.begin()-1) << endl;

		for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter){
			left += *(iter-1);
			right -= *iter;
			if (left == right) {
				eq = true;
				break;
			}
		}

		if (eq) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
