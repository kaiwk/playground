#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int expand[200000];
int n;
int d;

// partition
int partition(int pivot, int low, int high){
    int pivot_value = expand[pivot];
    swap(expand[pivot], expand[high]);
    int store_index = low;
    for(int i = low; i < high; ++i){
        if (expand[i] < pivot_value) {
            swap(expand[i], expand[store_index]);
            ++store_index;
        }
    }
    // after that
    // expand[low..store_index) is smaller part,
    // expand[store_index..high] are larger part.
    swap(expand[store_index], expand[high]);
    // after that
    // expand[low..store_index) <= expand[store_index] <= expand(store_index, high]
    return store_index;
}

int findnth(int n, int low, int high){
    if (low >= high) {
        return expand[low];
    }
    int pivot = low;
    while(pivot != n){
        if (pivot > n) {
            high = pivot - 1;
        }else if(pivot < n){
            low = pivot + 1;
        }
        pivot = partition(low, low, high);
    }
    return expand[pivot];
}

int findDoubleMedian(int low, int high){
    int temp = low + high;
    if (d%2 != 0) {
        int mid = temp / 2;
        return findnth(mid, low, high) * 2;
    }else{
        int mid = temp / 2;
        int mid2 = temp / 2 + 1;
        return (findnth(mid, low, high) + findnth(mid2, low, high));
    }
}

int main(){

    freopen("input", "r", stdin);
    cin >> n >> d;
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> expand[i];
    }

    int start = 0;
    int cnt = 0;
    for(int i = 0; i+d < n; ++i){
        start = i;
        if (expand[i+d] >= findDoubleMedian(start, start+d-1)) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
