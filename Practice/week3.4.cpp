#include <iostream>
#include <string>
using namespace std;

class node {
	int data;
	node* next;

	friend class listStack;
};

class listStack {
public:
	listStack();
	//~listStack();
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();

private:
	node* head;
	int capacity;
};

listStack::listStack() {
	head = NULL;
	capacity = 0;
}

//listStack::~listStack() {
//	node* curNode;
//
//	while (head != NULL) {
//		curNode = head;
//		head = curNode->next;
//		delete curNode;
//	}
//	head = NULL;
//	capacity = 0;
//	delete head;
//}

bool listStack::empty() {
	return (capacity == 0);
}

int listStack::size() {
	return capacity;
}

int listStack::top() {
	if (empty()) {
		return -1;
	}
	return head->data;
}

void listStack::push(int data) {
	node* newNode = new node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	capacity++;
}

void listStack::pop() {
	if (empty()) {
		cout << -1 << endl;
		return;
	}
	node* curNode = head;
	head = curNode->next;
	delete curNode;
	capacity--;
}

void infixToPostfix(string str) {
	listStack stack;
	int maxsize = -2;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			while (!stack.empty()) {
				if (stack.top() == 1) {
					cout << "+";
				}
				if (stack.top() == 2) {
					cout << "-";
				}
				if (stack.top() == 3) {
					cout << "*";
				}
				stack.pop();
			}
			if (str[i] == '+') {
				stack.push(1);
				if (stack.size() > maxsize) {
					maxsize = stack.size();
				}
			}
			if (str[i] == '-') {
				stack.push(2);
				if (stack.size() > maxsize) {
					maxsize = stack.size();
				}
			}
		}
		else if (str[i] == '*') {
			while (stack.top() == 3) {
				cout << "*";
				stack.pop();
			}
			stack.push(3);
			if (stack.size() > maxsize) {
				maxsize = stack.size();
			}
		}
		else if (str[i] != '(' && str[i] != ')') {
			cout << str[i];
		}
	}
	while (!stack.empty()) {
		if (stack.top() == 1) {
			cout << "+";
		}
		if (stack.top() == 2) {
			cout << "-";
		}
		if (stack.top() == 3) {
			cout << "*";
		}
		stack.pop();
	}
	cout << " " << maxsize << endl;
}

int main() {
	int n;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		infixToPostfix(str);
	}
}