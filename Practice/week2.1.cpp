#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* next;
	Node* prev;

	friend class S_LinkedList;
};

class S_LinkedList {
public:
	S_LinkedList();
	int List_size();
	bool Empty();
	void Print();
	void Append(int elem);
	int Delete(int idx);
	void AfterMax(int idx);
	void Sum();

private:
	Node* head;
	Node* tail;
};

S_LinkedList::S_LinkedList() {
	head = new Node;
	tail = new Node;

	head = NULL;
	tail = NULL;
}

bool S_LinkedList::Empty() {
	return (head == NULL && tail == NULL);
}

int S_LinkedList::List_size() {
	int list_size = 0;

	if (Empty()) {
		return list_size;
	}
	else {
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			list_size++;
			cur_node = cur_node->next;
		}
		list_size++;
		return list_size;
	}
}

void S_LinkedList::Print() {
	if (Empty()) {
		cout << "empty" << endl;
	}
	else {
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			cout << cur_node->elem << ' ';
			cur_node = cur_node->next;
		}
		cout << cur_node->elem << endl;
	}
}

void S_LinkedList::Append(int elem) {
	Node* new_node = new Node;
	new_node->elem = elem;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (Empty()) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		new_node->prev = tail;
		tail = tail->next;
	}

	Print();
}

int S_LinkedList::Delete(int idx) {
	int removeNum = 0;
	int count = 0;
	Node* cur_node;
	Node* pre_node;

	if (Empty() || List_size() <= idx) {
		return -1;
	}
	else if (idx == 0) {
		if (List_size() == 1) {
			removeNum = head->elem;
			tail = NULL;
			head = NULL;
		}
		else {
			cur_node = head;
			removeNum = cur_node->elem;
			head = cur_node->next;
			head->prev = NULL;
		}
	}
	else {
		pre_node = cur_node = head;
		while (count != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			count++;
		}
		removeNum = cur_node->elem;
		pre_node->next = cur_node->next;

		if (cur_node == tail) {
			tail = pre_node;
		}
		else {
			cur_node->next->prev = cur_node->prev;
		}
	}

	return removeNum;
}

void S_LinkedList::AfterMax(int idx) {
	int count = 0;
	int max = 0;

	if (Empty() || List_size() <= idx) {
		cout << "error" << endl;
	}
	else {
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			if (count >= idx) {
				if (max < cur_node->elem) {
					max = cur_node->elem;
				}
			}
			cur_node = cur_node->next;
			count++;
		}
		if (max < cur_node->elem) {
			max = cur_node->elem;
		}

		cout << max << endl;
	}
}

void S_LinkedList::Sum() {
	if (Empty()) {
		cout << 0 << endl;
	}
	else {
		int sum = 0;
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			sum += cur_node->elem;
			cur_node = cur_node->next;
		}
		sum += cur_node->elem;

		cout << sum << endl;
	}
}

int main() {
	int M = 0, elem = 0, idx = 0, updateElem = 0;
	string str;
	S_LinkedList list;
	cin >> M;
	while (M--) {
		cin >> str;

		if (str == "Print") {
			list.Print();
		}
		else if (str == "Append") {
			cin >> elem;
			list.Append(elem);
		}
		else if (str == "Delete") {
			cin >> elem;
			cout << list.Delete(elem) << endl;
		}
		else if (str == "AfterMax") {
			cin >> idx;
			list.AfterMax(idx);
		}
		else if (str == "Sum") {
			list.Sum();
		}
	}
}