#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
using namespace std;


/* O(n^2) */
void printKMax__(int arr[], int n, int k){

	deque<int> dq;

	for (int j = 0; j < k; j++) {
		dq.push_back(arr[j]);
	}

	int max;
	max = *max_element(dq.begin(), dq.end());
	cout << max;
	for (int i = k; i < n; i++) {
		dq.pop_front();
		dq.push_back(arr[i]);
		max = *max_element(dq.begin(), dq.end());
		cout << " " << max;
	}
	cout << endl;
}

/* O(kn) */
void printKMax_(int arr[], int n, int k){
	int j, max;
	for (int i = 0; i <= n-k; i++){
		max = arr[i];

		for (j = 1; j < k; j++) {
			if (arr[i+j] > max)
				max = arr[i+j];

		}
		printf("%d ", max);
	}
	cout << endl;
}

void printKMax(int arr[], int n, int k){
	deque<int> dq;

	for (int i = 0; i < k; i++) {
		while(!dq.empty() && arr[i] > arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for (int i = k; i < n; i++) {
		cout << arr[dq.front()] << " ";
		while(!dq.empty() && dq.front() <= i - k){
			dq.pop_front();
		}
		while(!dq.empty() && arr[i] > arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << arr[dq.front()] << endl;
}



int main(){
	freopen("input", "r", stdin);
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
		cin >> n >> k;
		int i;
		int arr[n];
		for(i=0;i<n;i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}

