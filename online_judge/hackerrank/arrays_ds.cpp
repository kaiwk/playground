#include <iostream>

using namespace std;

int a[1000];
int n;

int main(){

    cin >> n;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
    }

    for(int i = n-1; i > -1; --i){
	cout << a[i] << " ";
    }
    cout << endl;
}
