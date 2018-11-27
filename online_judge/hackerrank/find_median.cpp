#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int n;

int partition(int pivot, int low, int high){
    int pivot_value = a[pivot];
    swap(a[pivot], a[high]);
    int store_index = low;
    for(int i = low; i < high; ++i){
        if (a[i] < pivot_value) {
            swap(a[store_index], a[i]);
            ++store_index;
        }
    }

    // after that
    // a[low..store_index) is smaller part,
    // a[store_index..high] are larger part.
    swap(a[store_index], a[high]);
    // after that
    // a[low..store_index) <= a[store_index] <= a(store_index, high]
    return store_index;
}

int quickselect(int n, int low, int high){
    if (low > high) {
        return a[low];
    }
    int pivot = partition(low, low, high);
    if(n == pivot){
        return a[pivot];
    }else if (n < pivot){
        return quickselect(n, low, pivot-1);
    }else{
        return quickselect(n, pivot+1, high);
    }
}

int main(){
    freopen("input", "r", stdin);
    cin >> n;
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        a.push_back(temp);
    }

    //    cout << quickselect(n/2, 0, n-1) << endl;
    cout << partition(0, 0, n -1) << endl;
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}
