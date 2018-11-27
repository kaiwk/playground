#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
	vector<int> res;
	char ch;
	int tmp;
	while(ss >> tmp){
		res.push_back(tmp);
		ss >> ch;
	}
	return res;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for(int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";

	}

	return 0;

}

