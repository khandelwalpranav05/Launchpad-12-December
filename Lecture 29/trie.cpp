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
	char ch;
	unordered_map<char, node*> h;
	bool isTerminal;

	node(char ch) {
		this->ch = ch;
		this->isTerminal = false;
	}
};

class Trie {
	node* root;
public:
	Trie() {
		root = new node('\0');
	}

	void addWord(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool search(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				return false;
			}

		}

		return temp->isTerminal;
	}
};

int main() {

	Trie t;

	string words[] = {"apple", "application", "news", "new", "mango"};

	for (int i = 0; i < 5; i++) {
		t.addWord(words[i]);
	}

	cout << t.search("new") << endl;
	cout << t.search("newslkj") << endl;
	cout << t.search("news") << endl;
	cout << t.search("man") << endl;
	cout << t.search("app") << endl;
	cout << t.search("apple") << endl;


	return 0;
}






