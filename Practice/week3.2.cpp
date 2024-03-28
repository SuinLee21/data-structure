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

int postfix(string str) {
	int pop1, pop2;
	listStack stack;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			pop2 = stack.top();
			stack.pop();
			pop1 = stack.top();
			stack.pop();

			if (str[i] == '+') {
				stack.push(pop1 + pop2);
			}
			else if (str[i] == '-') {
				stack.push(pop1 - pop2);
			}
			else if (str[i] == '*') {
				stack.push(pop1 * pop2);
			}
		}
		else {
			stack.push(str[i] - '0');
		}
	}
	return stack.top();
}

int main() {
	int n, num;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str >> num;

		if (postfix(str) < 0) {
			cout << postfix(str) * -1 % num << endl;
		}
		else {
			cout << postfix(str) % num << endl;
		}
	}
}