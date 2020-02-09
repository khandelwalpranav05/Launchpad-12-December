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

class ArrayPointer {
public:
	int idx;
	int row;
	int value;

	ArrayPointer(int idx, int row, int value) {
		this->idx = idx;
		this->row = row;
		this->value = value;
	}

	void display() {
		cout << "This is idx " << idx << endl;
		cout << "This is row " << row << endl;
		cout << "This is value " << value << endl;
		cout << "****************************" << endl;
	}
};

class ArrayCompare {
public:
	bool operator()(ArrayPointer a, ArrayPointer b) {
		// cout << a.value << "," << b.value << endl;
		return a.value > b.value;
	}
};

vector<int> merge(vector<vector<int> > matrix) {
	priority_queue<ArrayPointer, vector<ArrayPointer>, ArrayCompare> pq;

	for (int i = 0; i < matrix.size(); i++) {
		ArrayPointer obj(0, i, matrix[i][0]);
		pq.push(obj);
	}

	vector<int> res;

	while (pq.top().value != INT_MAX) {

		ArrayPointer val = pq.top();
		pq.pop();

		res.push_back(val.value);

		val.idx += 1;

		if (val.idx == matrix[val.row].size()) {
			val.value = INT_MAX;
		} else {
			val.value = matrix[val.row][val.idx];
		}

		pq.push(val);
	}

	return res;
}

int main() {

	vector<vector<int> > matrix({{1, 4, 7, 10},
		{2, 5, 8},
		{3, 6, 9, 11, 12}
	});

	vector<int> res = merge(matrix);

	for (int val : res) {
		cout << val << " ";
	}
	cout << endl;

	// priority_queue<int, vector<int>, greater<int> > pq;

	// priority_queue<ArrayPointer, vector<ArrayPointer>, ArrayCompare> pq;



	// ArrayPointer a(1, 2, 3);
	// ArrayPointer b(4, 5, 6);
	// ArrayPointer p(3, 4, 7);

	// pq.push(a);
	// cout << "***********" << endl;
	// pq.push(b);
	// cout << "***********" << endl;
	// pq.push(p);
	// cout << "***********" << endl;


	// while (!pq.empty()) {

	// 	ArrayPointer temp = pq.top();
	// 	pq.pop();

	// 	temp.display();
	// }

	return 0;
}



