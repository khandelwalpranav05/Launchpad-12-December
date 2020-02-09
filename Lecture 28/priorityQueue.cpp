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

int main() {

	priority_queue<int, vector<int>, greater<int> > pq;

	pq.push(3);
	pq.push(5);
	pq.push(4);
	pq.push(7);
	pq.push(1);

	cout << pq.size() << endl;

	// cout << pq.top() << endl;

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}