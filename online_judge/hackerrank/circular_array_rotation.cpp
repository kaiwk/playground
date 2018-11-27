#include <iostream>
#include <cstdio>

using namespace std;

long n, k, q;
long a[100000] = {0};

int main(){

    freopen("input", "r", stdin);
    cin >> n >> k >> q;

    for(int i = 0; i < n; ++i){
	cin >> a[i];
    }

    int index = 0;
    for(int i = 0; i < q; ++i){
	cin >> index;
	cout << a[(-(k%n)+index+n)%n] << endl;
    }

    return 0;
}
