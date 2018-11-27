#include <iostream>

using namespace std;

int main(){

    int n, q, k;

    freopen("input", "r", stdin);
    cin >> n >> q;
    int **a = new int *[n];
    for(int i = 0; i < n; ++i){
        cin >> k;
        int *b = new int[k];
        for(int j = 0; j < k; ++j){
            cin >> b[j];
        }
        a[i] = b;
    }

    int qi;
    int index;
    for(int i = 0; i < q; ++i){
        cin >> qi >> index;
        cout << a[qi][index] << endl;
    }


    return 0;

}
