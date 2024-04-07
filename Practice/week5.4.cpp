#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string data;
	Node* prev;
	Node* next;
};

class DoublyList {
private:
	Node* header;
	Node* trailer;
	Node* p;
	int n;

public:
	DoublyList();
	bool empty();
	int size();
	Node* begin();
	Node* end();
	void nextP();
	void prevP();
	void up(int x);
	void down(int x);
	void cut();
	void append(string name);
	void insertBack(string name);
	void setPosition(int i);
	void print();
	void getData();
};

DoublyList::DoublyList() {
	header = new Node;
	trailer = new Node;

	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;

	p = begin();

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

void DoublyList::nextP() {
	p = p->next;
}

void DoublyList::prevP() {
	p = p->prev;
}

void DoublyList::up(int x) {
	if (empty()) {
		return;
	}

	for (int i = 0; i < x; i++) {
		if (p == begin()) {
			break;
		}
		prevP();
	}
}

void DoublyList::down(int x) {
	if (empty()) {
		return;
	}

	for (int i = 0; i < x; i++) {
		if (p == end()->prev) {
			break;
		}
		nextP();
	}
}

void DoublyList::cut() {
	if (empty()) {
		return;
	}
	Node* u = p->prev;
	Node* w = p->next;

	u->next = w; w->prev = u;

	delete p;

	if (u == header) {
		p = w;
	}
	else {
		p = u;
	}

	this->n--;
}

void DoublyList::append(string name) {
	Node* newNode = new Node;
	newNode->data = name;

	if (empty()) {
		newNode->next = trailer;
		newNode->prev = header;
		trailer->prev = newNode;
		header->next = newNode;

		p = newNode;
	}
	else {
		newNode->next = p->next;
		newNode->prev = p;
		p->next->prev = newNode;
		p->next = newNode;
	}
	this->n++;
}

void DoublyList::insertBack(string name) {
	Node* newNode = new Node;
	newNode->data = name;

	newNode->next = trailer;
	newNode->prev = trailer->prev;
	trailer->prev->next = newNode;
	trailer->prev = newNode;

	this->n++;
}

void DoublyList::setPosition(int i) {
	Node* temp = begin();
	int j = 0;

	while (temp != end()) {
		if (j == i) {
			p = temp;
			break;
		}
		j++;
		temp = temp->next;
	}
}

void DoublyList::print() {
	Node* temp = begin();

	if (empty()) {
		cout << "And Then There Were None";
	}
	while (temp != end()) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void DoublyList::getData() {
	cout << p->data << endl;
}

int main() {
	int T, N, M, K, num;
	string name, str;

	cin >> T;

	for (int i = 0; i < T; i++) {
		DoublyList list;
		cin >> N >> M >> K;

		for (int j = 0; j < N; j++) {
			cin >> name;
			list.insertBack(name);
		}
		list.setPosition(K);

		for (int j = 0; j < M; j++) {
			cin >> str;

			if (str == "up") {
				cin >> num;
				list.up(num);
			}
			else if (str == "down") {
				cin >> num;
				list.down(num);
			}
			else if (str == "append") {
				cin >> name;
				list.append(name);
			}
			else if (str == "cut") {
				list.cut();
			}
			else if (str == "print") {
				list.print();
			}
			else if (str == "get") {
				list.getData();
			}
		}
		list.print();
	}
}