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

bool comparatorFunction(int a, int b) {
	return a > b;
}

void display(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	int arr[] = {5, 6, 4, 1, 2, 34, 7};
	int n = 7;

	sort(arr, arr + n, comparatorFunction);

	display(arr, n);

	return 0;
}