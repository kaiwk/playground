#include <iostream>

using namespace std;

int a[3];
int b[3];

int main(){

    int res_a = 0, res_b = 0;

    for(int i = 0; i < 3; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < 3; ++i){
        cin >> b[i];
    }

    for(int i = 0; i < 3; ++i){
        if (a[i] > b[i]) {
            res_a += 1;
        }else if(a[i] < b[i]){
            res_b += 1;
        }
    }

    cout << res_a << " " << res_b << endl;

    return 0;
}
