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

//int prefix(string str) {
//	int pop1, pop2;
//	listStack stack;
//
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
//			pop2 = stack.top();
//			stack.pop();
//			pop1 = stack.top();
//			stack.pop();
//
//			if (str[i] == '+') {
//				stack.push(pop1 + pop2);
//			}
//			else if (str[i] == '-') {
//				stack.push(pop1 - pop2);
//			}
//			else if (str[i] == '*') {
//				stack.push(pop1 * pop2);
//			}
//		}
//		else {
//			stack.push(str[i] - '0');
//		}
//	}
//	return stack.top();
//}

//int priority(char operation) {
//	if (operation == '$') {
//		return -1;
//	}
//	else if (operation == '+' || operation == '-') {
//		return 1;
//	}
//	else if (operation == '*' || operation == '/') {
//		return 2;
//	}
//	else {
//		return 0;
//	}
//}
//
//int EvalExp(string str, listStack& val, listStack& op) {
//	int x, y;
//	char o;
//	/*listStack val;
//	listStack op;*/
//
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '$') {
//			while (val.size() > 1 && (priority(str[i]) <= priority(op.top()))) {
//				y = val.top();
//				val.pop();
//				x = val.top();
//				val.pop();
//
//				o = op.top();
//				op.pop();
//
//				if (o == '+') {
//					val.push(x + y);
//				}
//				else if (o == '-') {
//					val.push(x - y);
//				}
//				else if (o == '*') {
//					val.push(x * y);
//				}
//				else if (o == '/') {
//					val.push(x / y);
//				}
//			}
//			op.push(str[i]);
//		}
//		else {
//			val.push(str[i] - '0');
//		}
//	}
//
//	/*y = val.top();
//	val.pop();
//	x = val.top();
//	val.pop();
//
//	o = op.top();
//	op.pop();
//
//	if (o == '+') {
//		val.push(x + y);
//	}
//	else if (o == '-') {
//		val.push(x - y);
//	}
//	else if (o == '*') {
//		val.push(x * y);
//	}
//	else if (o == '/') {
//		val.push(x / y);
//	}*/
//
//
//	return val.top();
//}

void infixToPostfix(string str) {
	listStack stack;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') { //연산자라면
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
			}
			if (str[i] == '-') {
				stack.push(2);
			}
		}
		else if (str[i] == '*') {
			while (stack.top() == 3) {
				cout << "*";
				stack.pop();
			}
			stack.push(3);
		}
		else if (str[i] != '(' && str[i] != ')') { //피연산자라면
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
	cout << endl;
}

int main() {
	int n, data;
	string str;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		listStack val;
		listStack op;
		cin >> str;

		/*EvalExp(str, val, op);
		cout << EvalExp("$", val, op) << endl;*/

		infixToPostfix(str);

		//cout << prefix(str) << endl;

		/*if (str == "empty") {
			if (stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "size") {
			cout << stack.size() << endl;
		}
		else if (str == "top") {
			cout << stack.top() << endl;
		}
		else if (str == "push") {
			cin >> data;
			stack.push(data);
		}
		else if (str == "pop") {
			stack.pop();
		}*/
	}
}