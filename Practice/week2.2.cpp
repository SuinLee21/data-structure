#include <iostream>
#include <string>
using namespace std;

class Node {
	int elem;
	Node* next;

	friend class S_LinkedList;
};

class S_LinkedList {
public:
	S_LinkedList();
	~S_LinkedList();
	int List_size();
	bool Empty();
	void Print();
	void Append(int elem);
	void Merge(S_LinkedList list1, S_LinkedList list2);
	int FindElem(int num);
	void Insert(int num, int insertion);

private:
	Node* head;
	Node* tail;
	Node* temp_tail;
};

S_LinkedList::S_LinkedList() {
	head = new Node;
	tail = new Node;
	temp_tail = new Node;

	head = NULL;
	tail = NULL;
	temp_tail = NULL;
}

S_LinkedList::~S_LinkedList() {
	Node* delete_node;
	if (temp_tail) {
		tail = temp_tail;
		tail->next = NULL;
	}

	while (head) {
		delete_node = head;
		head = head->next;
		cout << delete_node->elem << " »èÁ¦µÊ¿ä." << endl;
		delete delete_node;
	}
	head = NULL;
	tail = NULL;
	delete head;
	delete tail;
	Print();
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

	if (Empty()) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = tail->next;
	}
}

int S_LinkedList::FindElem(int num) {
	Node* cur_node;

	cur_node = head;
	while (1) {
		if (num == cur_node->elem) {
			return cur_node->elem;
		}
		cur_node = cur_node->next;
	}
}

void S_LinkedList::Insert(int num, int insertion) {
	Node* cur_node;
	Node* new_node = new Node;
	new_node->elem = insertion;
	new_node->next = NULL;

	cur_node = head;
	while (1) {
		if (cur_node == head && cur_node->elem == FindElem(num)) {
			new_node->next = cur_node;
			head = new_node;
			break;
		}
		if (cur_node->next->elem == FindElem(num)) {
			new_node->next = cur_node->next;
			cur_node->next = new_node;
			break;
		}
		cur_node = cur_node->next;
	}
}

void S_LinkedList::Merge(S_LinkedList list1, S_LinkedList list2) {
	list1.temp_tail = list1.tail;
	list1.tail->next = list2.head;
	list1.tail = list2.tail;
}

int main() {
	int M = 0, n = 0, n1 = 0, m = 0;
	cin >> M;

	while (M--) {
		S_LinkedList list1 = S_LinkedList();
		S_LinkedList list2 = S_LinkedList();
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> m;
			list1.Append(m);
		}

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> m;
			list2.Append(m);
		}
		
		list1.Merge(list1, list2);
		list1.Print();

		cin >> n >> n1;

		list1.Insert(n, n1);
		list1.Print();
	}
}