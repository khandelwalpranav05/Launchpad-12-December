#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

void display(vector<int> &v) {
	for (int val : v) {
		cout << val << " ";
	}
	cout << endl;
}

void upHeapify(vector<int> &v, int idx) {
	if (idx == 0) {
		return;
	}

	int parentIdx = (idx - 1) / 2;

	if (v[parentIdx] < v[idx]) {
		swap(v[parentIdx], v[idx]);
		// display(v);
		upHeapify(v, parentIdx);
	}

}

void insert(vector<int> &v, int data) {

	v.push_back(data);

	int idx = v.size() - 1;

	upHeapify(v, idx);
}

void downHeapify(vector<int> &v, int idx, int n) {

	int leftChild = 2 * idx + 1;
	int rightChild = 2 * idx + 2;

	if (leftChild >= n  and rightChild >= n) {
		return;
	}

	int largestIdx = idx;

	if (leftChild < n and v[leftChild] > v[largestIdx]) {
		largestIdx = leftChild;
	}

	if (rightChild < n and v[rightChild] > v[largestIdx]) {
		largestIdx = rightChild;
	}

	if (idx != largestIdx) {
		swap(v[idx], v[largestIdx]);
		downHeapify(v, largestIdx, n);
	}
}

void erase(vector<int> &v) {
	int n = v.size() - 1;

	swap(v[0], v[n]);
	v.pop_back();

	downHeapify(v, 0, v.size());
}

void arrayToHeap(vector<int> &v) {
	int n = v.size();
	int start = n / 2 - 1;

	for (int i = start; i >= 0; i--) {
		downHeapify(v, i, n);
	}

	display(v);
}

void heapSort(vector<int> &v) {
	arrayToHeap(v);

	int n = v.size();

	for (int i = n - 1; i >= 1; i--) {
		swap(v[0], v[i]);
		downHeapify(v, 0, i);
	}
}

int main() {

	// vector<int> v({10, 8, 7, 2, 6, 5});

	// display(v);

	// insert(v, 19);

	// display(v);

	// erase(v);

	// display(v);

	vector<int> v({4, 5, 6, 1, 3, 8, 12});

	heapSort(v);

	display(v);

	return 0;
}