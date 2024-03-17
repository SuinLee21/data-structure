//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//	int elem;
//	Node* next;
//
//	friend class S_LinkedList;
//};
//
//class S_LinkedList {
//public:
//	S_LinkedList();
//	int List_size();
//	bool Empty();
//	void Print();
//	void Append(int elem);
//	void Delete(int num);
//	void Merge(S_LinkedList& list1, S_LinkedList& list2);
//	void FindIdx(int num);
//
//private:
//	Node* head;
//	Node* tail;
//};
//
//S_LinkedList::S_LinkedList() {
//	head = new Node;
//	tail = new Node;
//
//	head = NULL;
//	tail = NULL;
//}
//
//bool S_LinkedList::Empty() {
//	return (head == NULL && tail == NULL);
//}
//
//int S_LinkedList::List_size() {
//	int list_size = 0;
//
//	if (Empty()) {
//		return list_size;
//	}
//	else {
//		Node* cur_node = head;
//		while (cur_node->next != NULL) {
//			list_size++;
//			cur_node = cur_node->next;
//		}
//		list_size++;
//		return list_size;
//	}
//}
//
//void S_LinkedList::Print() {
//	if (Empty()) {
//		cout << "empty" << endl;
//	}
//	else {
//		Node* cur_node = head;
//		while (cur_node->next != NULL) {
//			cout << cur_node->elem << ' ';
//			cur_node = cur_node->next;
//		}
//		cout << cur_node->elem << endl;
//	}
//}
//
//void S_LinkedList::Append(int elem) {
//	Node* new_node = new Node;
//	new_node->elem = elem;
//	new_node->next = NULL;
//
//	if (Empty()) {
//		head = new_node;
//		tail = new_node;
//	}
//	else {
//		tail->next = new_node;
//		tail = tail->next;
//	}
//}
//
//void S_LinkedList::Delete(int num) {
//	Node* cur_node;
//	Node* pre_node;
//
//	pre_node = cur_node = head;
//	while (1) {
//		if (num == cur_node->elem) {
//			if (cur_node == head) {
//				head = cur_node->next;
//				break;
//			}
//			pre_node->next = cur_node->next;
//			break;
//		}
//		pre_node = cur_node;
//		cur_node = cur_node->next;
//	}
//
//	if (cur_node == tail) {
//		tail = pre_node;
//	}
//}
//
//void S_LinkedList::FindIdx(int num) {
//	Node* cur_node;
//	int count = 0;
//
//	cur_node = head;
//	while (1) {
//		if (num == cur_node->elem) {
//			break;
//		}
//		cur_node = cur_node->next;
//		count++;
//	}
//
//	cout << count << endl;
//}
//
//void S_LinkedList::Merge(S_LinkedList& list1, S_LinkedList& list2) {
//	list1.tail->next = list2.head;
//}
//
//int main() {
//	int M = 0, n = 0, m = 0;
//	cin >> M;
//
//	while (M--) {
//		S_LinkedList list1 = S_LinkedList();
//		S_LinkedList list2 = S_LinkedList();
//		cin >> n;
//
//		for (int i = 0; i < n; i++) {
//			cin >> m;
//			list1.Append(m);
//		}
//
//		cin >> n;
//
//		for (int i = 0; i < n; i++) {
//			cin >> m;
//			list2.Append(m);
//		}
//
//		list1.Merge(list1, list2);
//		list1.Print();
//		list2.Print();
//
//		cin >> n;
//
//		list1.Delete(n);
//		list1.Print();
//
//		cin >> n;
//
//		list1.FindIdx(n);
//	}
//}