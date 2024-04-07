#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;
};

class DoublyList {
private:
	Node* header;
	Node* trailer;
	int n;

public:
	DoublyList();
	bool empty();
	int size();
	Node* begin();
	Node* end();
	void insert(int i, int data);
	void erase(int i);
	void find(int x);
	void print(int m);
};

DoublyList::DoublyList() {
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	n = 0;
}

int DoublyList::size() {
	return n;
}

bool DoublyList::empty() {
	return (size() == 0);
}

Node* DoublyList::begin() {
	return header->next;
}

Node* DoublyList::end() {
	return trailer;
}

void DoublyList::insert(int i, int data) {
	if (i < 0 || i > size()) {
		cout << "out_of_range" << endl;
		return;
	}

	Node* p = header;
	int j = 0;
	Node* newNode = new Node;
	newNode->data = data;

	while (p != end()) {
		if (j == i) {
			Node* u = p->next;
			newNode->next = u; u->prev = newNode;
			newNode->prev = p; p->next = newNode;

			break;
		}
		j++;
		p = p->next;
	}

	this->n++;
}

void DoublyList::erase(int i) {
	if (i < 0 || i >= size()) {
		cout << "out_of_range" << endl;
		return;
	}

	Node* p = header->next;
	int j = 0;

	while (p != end()) {
		if (j == i) {
			Node* u = p->prev;
			Node* w = p->next;
			u->next = w; w->prev = u;
			delete p;

			break;
		}
		j++;
		p = p->next;
	}

	this->n--;
}

void DoublyList::find(int x) {
	int j = 0;
	bool isFound = false;
	Node* p = trailer->prev;

	while (p != header) {
		if (p->data == x) {
			cout << j << endl;
			isFound = true;
			break;
		}
		j++;
		p = p->prev;
	}

	if (!isFound) {
		cout << "not_found" << endl;
	}
}

void DoublyList::print(int m) {
	if (empty()) {
		cout << "empty" << endl;
		return;
	}

	if (m == 0) {
		Node* p = begin();

		while (p != end()) {
			cout << p->data << " ";
			p = p->next;
		}
	}
	else if (m == 1) {
		Node* p = end()->prev;

		while (p != header) {
			cout << p->data << " ";
			p = p->prev;
		}
	}
	cout << endl;
}

int main() {
	int N, data, index;
	cin >> N;
	string str;
	DoublyList list;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "insert") {
			cin >> index >> data;
			list.insert(index, data);
		}
		else if (str == "erase") {
			cin >> index;
			list.erase(index);
		}
		else if (str == "empty") {
			if (list.empty()) {
				cout << "true";
			}
			else {
				cout << "false";
			}
			cout << endl;
		}
		else if (str == "find") {
			cin >> data;
			list.find(data);
		}
		else if (str == "print") {
			cin >> data;
			list.print(data);
		}
		else if (str == "size") {
			cout << list.size() << endl;
		}
	}
}