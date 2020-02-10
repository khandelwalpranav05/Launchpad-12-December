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

class node {
public:
	int data;
	node* left;
	node* right;

	node() {
		this->left = NULL;
		this->right = NULL;
	}

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(node* root, int num) {

	int val = num;

	node* temp = root;

	for (int i = 31; i >= 0; i--) {

		int bit = (val >> i) & 1;

		if (bit) {
			if (temp->right) {
				temp = temp->right;
			} else {
				node* rightChild = new node();
				temp->right = rightChild;
				temp = temp->right;
			}

		} else {
			if (temp->left) {
				temp = temp->left;
			} else {
				node* leftChild = new node();
				temp->left = leftChild;
				temp = temp->left;
			}
		}
	}
}

int maxSum(int arr[], int n, node* root) {

	int maxXorSum = 0;

	for (int i = 0; i < n; i++) {

		int num = arr[i];

		node* temp = root;

		int currXor = 0;

		for (int j = 31; j >= 0; j--) {

			int bit = (num >> j) & 1;

			if (bit) {
				if (temp->left) {
					currXor += pow(2, j);
					temp = temp->left;
				} else {
					temp = temp->right;
				}

			} else {
				if (temp->right) {
					currXor += pow(2, j);
					temp = temp->right;
				} else {
					temp = temp->left;
				}
			}

		}

		maxXorSum = max(currXor, maxXorSum);
	}

	return maxXorSum;
}

int main() {

	// cout << (5 ^ 9) << endl;
	// cout << (2 ^ 9) << endl;
	// cout << (8 ^ 9) << endl;

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = 6;

	node* root = new node();

	for (int i = 0; i < n; i++) {
		insert(root, arr[i]);
	}

	cout << maxSum(arr, n, root) << endl;

	return 0;
}




