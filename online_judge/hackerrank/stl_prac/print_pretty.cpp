#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		cout << resetiosflags(ios::uppercase | ios::scientific);
		cout << setiosflags(ios::fixed | ios::showbase);
		cout << setw(0) << std::hex;
		cout << (unsigned long)A << endl;

		cout << resetiosflags(ios::showbase);
		cout << setprecision(2) << setw(15) << setfill('_') << std::dec;
		cout << setiosflags(ios::showpos | ios::left);
		cout << B << endl;

		cout << resetiosflags(ios::showpos | ios::fixed);
		cout << setiosflags(ios::scientific | ios::uppercase);
		cout << setprecision(9);
		cout << C << endl;

	}
	return 0;
}
