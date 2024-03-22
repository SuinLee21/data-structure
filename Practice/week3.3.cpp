//#include <iostream>
//#include <string>
//using namespace std;
//
//class node {
//	int data;
//	node* next;
//
//	friend class listStack;
//};
//
//class listStack {
//public:
//	listStack();
//	bool empty();
//	int size();
//	int top();
//	void push(int data);
//	void pop(int s);
//
//private:
//	node* head;
//	int capacity;
//};
//
//listStack::listStack() {
//	head = NULL;
//	capacity = 0;
//}
//
//bool listStack::empty() {
//	return (capacity == 0);
//}
//
//int listStack::size() {
//	return capacity;
//}
//
//int listStack::top() {
//	if (empty()) {
//		return -1;
//	}
//	return head->data;
//}
//
//void listStack::push(int data) {
//	node* newNode = new node;
//	newNode->data = data;
//	newNode->next = head;
//	head = newNode;
//	capacity++;
//}
//
//void listStack::pop(int s) {
//	if (empty()) {
//		cout << -1 << endl;
//		return;
//	}
//
//	if (s > capacity) {
//		s = capacity;
//	}
//	for (int i = 0; i < s; i++) {
//		node* curNode = head;
//		cout << curNode->data << " ";
//		head = curNode->next;
//		delete curNode;
//		capacity--;
//	}
//	cout << endl;
//}
//
//int main() {
//	int n, data, s;
//	string str;
//	listStack stack;
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> str;
//		if (str == "empty") {
//			if (stack.empty()) {
//				cout << 1 << endl;
//			}
//			else {
//				cout << 0 << endl;
//			}
//		}
//		else if (str == "size") {
//			cout << stack.size() << endl;
//		}
//		else if (str == "top") {
//			cout << stack.top() << endl;
//		}
//		else if (str == "push") {
//			cin >> data;
//			stack.push(data);
//		}
//		else if (str == "pop") {
//			cin >> s;
//			stack.pop(s);
//		}
//	}
//}