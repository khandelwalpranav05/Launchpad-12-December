#include <iostream>

using namespace std;

template <typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string key,T value){
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T>
class HashTable{

	int currSize;
	int maxSize;
	node<T>* *bucket;

public:
	HashTable(int defaultSize = 7){
		this->maxSize = defaultSize;
		this->currSize = 0;
		this->bucket = new node<T>*[this->maxSize];

		for(int i=0;i<this->maxSize;i++){
			this->bucket[i] = NULL;
		}
	}

	int hashFunction(string key){

		int multiFactor = 1;
		int idx = 0;

		for(int i=0;i<key.length();i++){
			idx = (idx%this->maxSize + ((key[i]%this->maxSize)*(multiFactor%this->maxSize)%this->maxSize));
			idx = idx%this->maxSize;

			multiFactor = ((multiFactor%this->maxSize)*(37%this->maxSize)%this->maxSize);
		}

		return idx%this->maxSize;
	}

	void rehash(){

		int oldSize = this->maxSize;
		node<T>* *oldBucket = this->bucket;

		this->maxSize = 2*oldSize;
		this->bucket = new node<T>*[this->maxSize];

		for(int i=0;i<this->maxSize;i++){
			this->bucket[i] = NULL;
		}
		this->currSize = 0;

		for(int i=0;i<oldSize;i++){

			node<T>* temp = oldBucket[i];

			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
		}

		delete [] oldBucket;
	}

	void insert(string key,T value){

		float loadFactor = (float)currSize/maxSize;

		if(loadFactor > 0.7){
			rehash();
		}

		int idx = hashFunction(key);

		node<T>* n = new node<T>(key,value);
		n->next = bucket[idx];
		bucket[idx] = n;

		this->currSize++;
	}

	void display(){
		for(int i=0;i<this->maxSize;i++){

			node<T>* temp = bucket[i];

			while(temp!=NULL){
				cout<<temp->key<<"->"<<temp->value<<" ,";
				temp = temp->next;
			}
			cout<<endl;
		}

		cout<<"*********************************"<<endl;
	}

	T* search(string key){
		int idx = hashFunction(key);

		node<T>* temp =bucket[idx];

		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp = temp->next;
		}

		return NULL;
	}

	void erase(string key){
		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		if(temp==NULL){
			cout<<"Not Found!"<<endl;
			return;
		}

		if(temp->key==key){
			// cout<<"Check"<<endl;
			node<T>* toBeDeleted = bucket[idx];
			bucket[idx] = bucket[idx]->next;
			delete toBeDeleted;
			return;
		}

		while(temp->next!=NULL){
			if(temp->next->key==key){
				break;
			}
			temp = temp->next;
		}

		if(temp->next==NULL){
			cout<<"Not Found!"<<endl;
			return;
		}

		node<T>* toBeDeleted = temp->next;
		temp->next = temp->next->next;
		delete toBeDeleted;
	}
};

int main(){

	HashTable<int> h;

	h.insert("India",144);
	h.insert("Pakistan",67);
	h.insert("Sweden",3);
	h.insert("Norway",1);
	h.insert("North Korea",400);

	h.display();

	h.insert("China",70);

	h.display();

	// h.erase("Pakistan");

	// h.display();

	// int* val = h.search("Sweden");
	// cout<<(*val)<<endl;

	return 0;
}