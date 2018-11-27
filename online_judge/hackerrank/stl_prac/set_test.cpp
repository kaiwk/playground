#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

set<int> st;
int n;
int type;

int main() {
	freopen("input", "r", stdin);
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> type >> temp;
		switch(type){
			case 1:
				st.insert(temp);
				break;
			case 2:
				if (st.find(temp) != st.end()) {
					st.erase(temp);
				}
				break;
			case 3:
				if (st.find(temp) != st.end()) {
					cout << "Yes" << endl;
				}else{
					cout << "No " << endl;
				}
				break;
			default:
				break;
		}
	}

	return 0;
}

