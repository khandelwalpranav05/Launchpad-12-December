#include <iostream>
#include <vector>
#include <list>
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

template <typename T>
class Graph {

	unordered_map<T, list<T> > adjList;

public:

	void addEdge(T u, T v, bool bidir = true) {
		adjList[u].push_back(v);

		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void display() {

		for (auto node : adjList) {

			auto u = node.first;
			cout << u << "->";
			for (T val : node.second) {
				cout << val << " ,";
			}
			cout << endl;
		}
		cout << "**********************" << endl;
	}

	void bfs(T src) {
		queue<T> q;
		unordered_map <T, bool> visited;

		visited[src] = true;
		q.push(src);

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ,";

			for (T neighbor : adjList[node]) {
				if (visited.count(neighbor) == 0) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}

		cout << endl;
	}

	void dfsHelper(T node, unordered_map<T, bool> &visited) {

		cout << node << " ";
		visited[node] = true;

		for (T neighbor : adjList[node]) {
			if (visited.count(neighbor) == 0) {
				dfsHelper(neighbor, visited);
			}
		}
	}

	void dfs(T src) {

		unordered_map<T, bool> visited;

		dfsHelper(src, visited);

		cout << endl;
	}

	void allComponents() {
		unordered_map<T, bool> visited;

		int component = 0;

		for (auto node : adjList) {

			T val = node.first;

			if (visited.count(val) == 0) {
				dfsHelper(val, visited);
				component++;
				cout << endl;
			}
		}

		cout << "Number of components " << component << endl;
	}


};

int main() {

	Graph<int> g;

	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(3, 2);
	g.addEdge(4, 3);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	g.addEdge(6, 7);

	g.addEdge(9, 10);
	g.addEdge(8, 9);

	g.allComponents();

	// g.display();

	// g.bfs(5);

	// g.dfs(1);

	return 0;
}