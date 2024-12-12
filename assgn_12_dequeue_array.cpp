#include <iostream>
using namespace std;

class Deque {
private:
	static const int MAX_SIZE = 10;
	int deque[MAX_SIZE];
	int front;
	int rear;
	int size;

public:
	Deque() : front(-1), rear(-1), size(0) {}

	bool isFull()
	{
		return size == MAX_SIZE;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void addFront(int value)
	{
		if (isFull()) {
			cout << "Deque is full. Cannot add element at the front." << endl;
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		} else {
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		}
		deque[front] = value;
		size++;
		cout << "Added " << value << " to the front." << endl;
	}

	void addRear(int value)
	{
		if (isFull()) {
			cout << "Deque is full. Cannot add element at the rear." << endl;
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		} else {
			rear = (rear + 1) % MAX_SIZE;
		}
		deque[rear] = value;
		size++;
		cout << "Added " << value << " to the rear." << endl;
	}

	void deleteFront()
	{
		if (isEmpty()) {
			cout << "Deque is empty. Cannot delete element from the front." << endl;
			return;
		}
		cout << "Deleted " << deque[front] << " from the front." << endl;
		if (front == rear) {
			front = rear = -1;
		} else {
			front = (front + 1) % MAX_SIZE;
		}
		size--;
	}

	void deleteRear()
	{
		if (isEmpty()) {
			cout << "Deque is empty. Cannot delete element from the rear." << endl;
			return;
		}
		cout << "Deleted " << deque[rear] << " from the rear." << endl;
		if (front == rear) {
			front = rear = -1;
		} else {
			rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
		}
		size--;
	}

	void displayDeque()
	{
		if (isEmpty()) {
			cout << "Deque is empty." << endl;
			return;
		}
		cout << "Deque elements: ";
		for (int i = 0; i < size; i++) {
			int index = (front + i) % MAX_SIZE;
			cout << deque[index] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Deque deque;
	int choice, value;

	do {
		cout << "\nDeque Simulation (Array)" << endl;
		cout << "1. Add to Front" << endl;
		cout << "2. Add to Rear" << endl;
		cout << "3. Delete from Front" << endl;
		cout << "4. Delete from Rear" << endl;
		cout << "5. Display Deque" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to add to front: ";
			cin >> value;
			deque.addFront(value);
			break;
		case 2:
			cout << "Enter value to add to rear: ";
			cin >> value;
			deque.addRear(value);
			break;
		case 3:
			deque.deleteFront();
			break;
		case 4:
			deque.deleteRear();
			break;
		case 5:
			deque.displayDeque();
			break;
		case 6:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 6);

	return 0;
}
