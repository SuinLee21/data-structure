#include <iostream>
#include <string>
using namespace std;

class arrQ {
private:
	int* Q;
	int rear;
	int front;
	int capacity;

public:
	arrQ(int capacity) {
		this->capacity = capacity + 1;
		Q = new int[this->capacity];
		front = rear = 0;

		for (int i = 0; i < capacity; i++) {
			Q[i] = 0;
		}
	}

	bool isFull() {
		return front == (rear + 1) % capacity;
	}

	bool isEmpty() {
		return front == rear;
	}

	void enqueue(int value) {
		if (isFull()) {
			cout << "Full" << endl;
		}
		else {
			rear = (rear + 1) % capacity;
			Q[rear] = value;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			_front();
			front = (front + 1) % capacity;
			Q[front] = 0;
		}
	}

	void _front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Q[(front + 1) % capacity] << endl;
		}
	}

	int _rear() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return Q[rear];
		}
	}

	int size() {
		return (rear - front + capacity) % capacity;
	}

	void rearNsum(int num) {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else if (num > size()) {
			cout << "error" << endl;
		}
		else {
			int sum = 0;
			for (int i = 0; i < num; i++) {
				sum += Q[rear - i];
			}
			cout << sum << endl;
		}
	}

	void print() {
		cout << "================================" << endl;
		cout << "front index is " << front << endl;
		cout << "rear index is " << rear << endl;

		for (int i = 0; i < capacity; i++) {
			cout << Q[i] << " ";
		}
		cout << endl;
		cout << "================================" << endl;
	}
};

int main() {
	int N, T, data;
	string str;
	cin >> N >> T;

	arrQ arQ(N);

	for (int i = 0; i < T; i++) {
		cin >> str;

		if (str == "size") {
			cout << arQ.size() << endl;
		}
		else if (str == "isEmpty") {
			if (arQ.isEmpty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (str == "full") {
			if (arQ.isFull()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (str == "front") {
			arQ._front();
		}
		else if (str == "rearNsum") {
			cin >> data;
			arQ.rearNsum(data);
		}
		else if (str == "enqueue") {
			cin >> data;
			arQ.enqueue(data);
		}
		else if (str == "dequeue") {
			arQ.dequeue();
		}
	}
}