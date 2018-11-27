#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {

	string a, b;
	cin >> a >> b;
	cout << a.size() << " " << b.size() << endl;

	cout << a + b << endl;

	swap(a[0], b[0]);

	cout << a << " " << b << endl;

	return 0;
}

