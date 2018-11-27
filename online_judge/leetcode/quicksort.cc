#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int start, int end) {
    int pivot = nums[end];
    int i = start;
    for (int j = start; j < end; ++j) {
        if (nums[j] < pivot) {
            swap(nums[j], nums[i]);
            ++i;
        }
    }
    swap(nums[i], nums[end]);
    return i;
}

void quicksort(vector<int> &nums, int start, int end) {
    if (start < end) {
        int pivot = partition(nums, start, end);
        quicksort(nums, start, pivot-1);
        quicksort(nums, pivot+1, end);
    }
}

int main() {
    vector<int> nums = {9, 4, 6, 1, 2, 5, 3, 0, 7, 8};
    quicksort(nums, 0, nums.size()-1);

    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;
    }
}
