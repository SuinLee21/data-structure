#include <iostream>
using namespace std;

class arrayStack {
public:
	arrayStack(int capacity);
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();

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
		return;
	}
	arr[++topIndex] = data;
}

void arrayStack::pop() {
	if (empty()) {
		return;
	}
	topIndex--;
}

int main() {

}