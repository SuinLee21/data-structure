//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//	Node(int data) {
//		this->data = data;
//		this->next = NULL;
//	}
//};
//
//class LinkedList {
//public:
//	Node* front;
//	Node* rear;
//
//	LinkedList() {
//		this->front = NULL;
//		this->rear = NULL;
//	}
//
//	void addEnd(int data) {
//		Node* newNode = new Node(data);
//		if (front == NULL) {
//			front = rear = newNode;
//		}
//		else {
//			rear->next = newNode;
//			rear = newNode;
//		}
//	}
//
//	void removeFront() {
//		if (front != NULL) {
//			Node* tmp = front;
//			front = front->next;
//			delete tmp;
//		}
//	}
//};
//
//class LinkedQueue {
//public:
//	LinkedList* Q;
//	int n;
//
//	LinkedQueue() {
//		this->Q = new LinkedList();
//		this->n = 0;
//	}
//
//	int size() {
//		return n;
//	}
//
//	bool isEmpty() {
//		return n == 0;
//	}
//
//	int front() {
//		if (isEmpty()) {
//			return -1;
//		}
//		return Q->front->data;
//	}
//
//	int rear() {
//		if (isEmpty()) {
//			return -1;
//		}
//		return Q->rear->data;
//	}
//
//	void enqueue(int e) {
//		Q->addEnd(e);
//		n++;
//	}
//
//	void dequeue() {
//		if (isEmpty()) {
//			cout << "Empty" << endl;
//		}
//		else {
//			Q->removeFront();
//			n--;
//		}
//	}
//
//	void battle(LinkedQueue& P1, LinkedQueue& P2) {
//		int hp1 = 0, hp2 = 0;
//		int front1 = 0, front2 = 0;
//		int point1 = 0, point2 = 0;
//		int lastPointP1 = 0, lastPointP2 = 0;
//		int N = P1.size();
//		bool a = false;
//		int b = 0;
//
//		for (int i = 0; i < N; i++) {
//			front1 = P1.front() + hp1;
//			front2 = P2.front() + hp2;
//
//			cout << "Round" << i + 1 << " ";
//
//			if (front1 > front2) {
//				if (i == N - 1 && a == true) {
//					b = 1;
//				}
//				hp2 = front1 - front2;
//				hp1 = 0;
//				point1++;
//
//				cout << front1 << ">" << front2 << " ";
//			}
//			else if (front1 < front2) {
//				if (i == N - 1 && a == true) {
//					b = 2;
//				}
//				hp2 = 0;
//				hp1 = front2 - front1;
//				point2++;
//
//				cout << front1 << "<" << front2 << " ";
//			}
//			else if (front1 == front2) {
//				if (i == N - 2) {
//					a = true;
//				}
//				hp1 = hp2 = 0;
//
//				cout << front1 << "=" << front2 << " ";
//			}
//			P1.dequeue();
//			P2.dequeue();
//			cout << point1 << ":" << point2 << endl;
//
//			if (i == N - 2) {
//				lastPointP1 = point1;
//				lastPointP2 = point2;
//			}
//		}
//		if (point1 > point2) {
//			cout << "Winner P1" << endl;
//		}
//		else if (point1 < point2) {
//			cout << "Winner P2" << endl;
//		}
//		else if (point1 == point2) {
//			if (lastPointP1 > lastPointP2) {
//				cout << "Winner P2" << endl;
//			}
//			else if (lastPointP1 < lastPointP2) {
//				cout << "Winner P1" << endl;
//			}
//			else if (lastPointP1 == lastPointP2) {
//				cout << "Draw" << endl;
//			}
//		}
//	}
//};
//
//int main() {
//	LinkedQueue P1, P2, Dual;
//	int T, N, data;
//
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//		cin >> N;
//
//		for (int j = 0; j < N; j++) {
//			cin >> data;
//			P1.enqueue(data);
//		}
//		for (int j = 0; j < N; j++) {
//			cin >> data;
//			P2.enqueue(data);
//		}
//
//		Dual.battle(P1, P2);
//	}
//}