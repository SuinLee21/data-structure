#include <iostream>
#include <string>
using namespace std;

class SequenceList {
private:
	struct Node
	{
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);
	public:
		int& operator*();
		bool operator==(const Iterator& p) const;
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();
		Iterator& operator--();
	
		friend class SequenceList;
	};
	
private:
	int n;
	Node* header;
	Node* trailer;

public:
	SequenceList();
	int size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	int& operator[](int i);
	void insertFront(const int& e);
	void insertBack(const int& e);
	void insert(const Iterator& p, const int& e);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);

	SequenceList::Iterator atIndex(int i) const;
	int indexOf(const Iterator& p) const;
	void print();
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::insert(const SequenceList::Iterator& p, const int& e) {
	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::insertFront(const int& e) {
	insert(begin(), e);
}

void SequenceList::insertBack(const int& e) {
	insert(end(), e);
}

void SequenceList::erase(const Iterator& p) {
	Node* v = p.v;
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v;
	this->n--;
}

void SequenceList::eraseFront() {
	erase(begin());
}

void SequenceList::eraseBack() {
	erase(--end());
}

int SequenceList::size() const {
	return n;
}

bool SequenceList::empty() const {
	return (n == 0);
}

SequenceList::Iterator::Iterator(Node* u) {
	v = u;
}

SequenceList::Iterator SequenceList::begin() const {
	return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const {
	return Iterator(trailer);
}

int& SequenceList::operator[](int i) {
	Iterator p = atIndex(i);

	return *p;
}

int& SequenceList::Iterator::operator*() {
	return v->e;
}

bool SequenceList::Iterator::operator==(const Iterator& p) const {
	return v == p.v;
}

bool SequenceList::Iterator::operator!=(const Iterator& p) const {
	return v != p.v;
}

SequenceList::Iterator& SequenceList::Iterator::operator++() {
	v = v->next;
	return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--() {
	v = v->prev;
	return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i) const {
	Iterator p = begin();
	for (int j = 0; j < i; j++) {
		++p;
	}
	return p;
}

int SequenceList::indexOf(const Iterator& p) const {
	Iterator q = begin();
	int j = 0;
	
	while (q != p) {
		++q;
		++j;
	}
	return j;
}

void SequenceList::print() {
	Iterator p = begin();

	while (p != end()) {
		cout << *p << " ";
		++p;
	}
	cout << endl;
}

int main() {
	int T, data;
	cin >> T;

	SequenceList dl;
	SequenceList::Iterator iter = dl.begin();

	for (int i = 0; i < T; i++) {
		string oper;
		cin >> oper;

		if (oper == "insert") {
			cin >> data;
			dl.insert(iter, data);
			dl.print();
			iter = dl.begin();
		}
		else if (oper == "insertFront") {
			cin >> data;
			dl.insertFront(data);
			dl.print();
		}
		else if (oper == "insertBack") {
			cin >> data;
			dl.insertBack(data);
			dl.print();
		}
		else if (oper == "erase") {
			dl.erase(iter);
			dl.print();
		}
		else if (oper == "eraseFront") {
			dl.eraseFront();
			dl.print();
		}
		else if (oper == "eraseBack") {
			dl.eraseBack();
			dl.print();
		}
		else if (oper == "begin") {
			
		}
		else if (oper == "end") {

		}
		else if (oper == "++") {

		}
		else if (oper == "--") {

		}
		else if (oper == "atIndex") {
			cin >> data;

			cout << dl[data] << endl;
			iter = dl.atIndex(data);
		}
		else if (oper == "indexOf") {
			cout << dl.indexOf(iter) << endl;
		}
		else if (oper == "size") {
			cout << dl.size() << endl;

		}
	}
}

//struct node {
//	int data;
//	node* prev;
//	node* next;
//};
//
//class nodeList {
//public:
//	nodeList();
//	bool empty();
//	int size();
//	node* begin();
//	node* end();
//	void insert(node* pos, int data);
//	void insertFront(int data);
//	void insertBack(int data);
//	void erase(node* pos);
//	void eraseFront();
//	void eraseBack();
//
//private:
//	node* header;
//	node* trailer;
//	int n;
//};
//
//nodeList::nodeList() {
//	header = new node();
//	trailer = new node();
//	header->next = trailer;
//	trailer->prev = header;
//	header->prev = trailer->next = NULL;
//	n = 0;
//}
//
//bool nodeList::empty() {
//	return (n == 0);
//}
//
//int nodeList::size() {
//	return n;
//}
//
//node* nodeList::begin() {
//	return header->next;
//}
//
//node* nodeList::end() {
//	return trailer;
//}
//
//void nodeList::insert(node* pos, int data) {
//	node* newNode = new node();
//	newNode->data = data;
//	newNode->prev = pos->prev;
//	newNode->next = pos;
//	pos->prev->next = newNode;
//	pos->prev = newNode;
//	n++;
//}
//
//void nodeList::insertFront(int data) {
//	insert(begin(), data);
//}
//
//void nodeList::insertBack(int data) {
//	insert(end(), data);
//}
//
//void nodeList::erase(node* pos) {
//	pos->prev->next = pos->next;
//	pos->next->prev = pos->next;
//	delete pos;
//	n--;
//}
//
//void nodeList::eraseFront() {
//	erase(begin());
//}
//
//void nodeList::eraseBack() {
//	erase(end()->prev);
//}
//
//int main() {
//	int data;
//
//	nodeList list;
//	node* p = list.begin();
//
//	cin >> data;
//	list.insert(p, data);
//
//	list.erase(p);
//
//	if (p != list.end()) {
//		p = p->next;
//	}
//
//	if (p != list.begin()) {
//		p = p->prev;
//	}
//}