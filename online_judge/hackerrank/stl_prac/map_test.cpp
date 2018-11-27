#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<string, int> mp;

string name;
int mk;
int n;
int type;

int main() {

	freopen("input", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> type;
		switch (type) {
			case 1:
				cin >> name >> mk;
				if (mp.find(name) != mp.end()) {
					mp[name] += mk;
				}else{
					mp.insert(make_pair(name, mk));
				}
				break;
			case 2:
				cin >> name;
				mp.erase(name);
				break;
			case 3:
				cin >> name;
				if (mp.find(name) != mp.end()) {
					cout << mp[name] << endl;
				}else{
					cout << "0" << endl;
				}
				break;
			default:
				break;
		}
	}


	return 0;
}

