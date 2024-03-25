#include <iostream>
#include <string>
using namespace std;

class arrayStack {
public:
	arrayStack(int capacity);
	bool empty();
	int size();
	int top();
	void push(int data);
	void popsum(int s);

private:
	int* arr;
	int capacity;
	int topIndex;
};

arrayStack::arrayStack(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	topIndex = -1;
}

bool arrayStack::empty() {
	return (topIndex == -1);
}

int arrayStack::size() {
	return topIndex + 1;
}

int arrayStack::top() {
	if (empty()) {
		return -1;
	}
	return arr[topIndex];
}

void arrayStack::push(int data) {
	if (size() == capacity) {
		cout << "FULL" << endl;
		return;
	}
	arr[++topIndex] = data;
}

void arrayStack::popsum(int s) {
	if (empty()) {
		cout << -1 << endl;
		return;
	}
	int sum = 0;

	if (s > size()) {
		s = size();
	}
	for (int i = 0; i < s; i++) {
		sum += arr[topIndex];
		topIndex--;
	}

	cout << sum << endl;
}

int main() {
	int t, N, num;
	string str;
	cin >> t >> N;

	arrayStack stack(t);

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "size") {
			cout << stack.size() << endl;
		}
		else if (str == "empty") {
			if (stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "top") {
			cout << stack.top() << endl;
		}
		else if (str == "push") {
			cin >> num;
			stack.push(num);
		}
		else if (str == "popsum") {
			cin >> num;
			stack.popsum(num);
		}
	}
}