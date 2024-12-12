#include <iostream>
using namespace std;

class PizzaOrderSystem
{
  private:
	static const int MAX_ORDERS = 10;
	int orders[MAX_ORDERS];
	int front;
	int rear;
	int size;

  public:
	PizzaOrderSystem() : front(-1), rear(-1), size(0) {}

	bool isFull()
	{
		return size == MAX_ORDERS;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void placeOrder(int orderId)
	{
		if (isFull()) {
			cout << "Order system is full. Cannot accept more orders." << endl;
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		} else {
			rear = (rear + 1) % MAX_ORDERS;
		}
		orders[rear] = orderId;
		size++;
		cout << "Order placed: " << orderId << endl;
	}

	void serveOrder()
	{
		if (isEmpty()) {
			cout << "No orders to serve." << endl;
			return;
		}
		cout << "Order served: " << orders[front] << endl;
		if (front == rear) {
			front = rear = -1;
		} else {
			front = (front + 1) % MAX_ORDERS;
		}
		size--;
	}

	void displayOrders()
	{
		if (isEmpty()) {
			cout << "No orders to display." << endl;
			return;
		}
		cout << "Current orders: ";
		for (int i = 0; i < size; i++) {
			int index = (front + i) % MAX_ORDERS;
			cout << orders[index] << " ";
		}
		cout << endl;
	}
};

int main()
{
	PizzaOrderSystem system;
	int choice, orderId;

	do {
		cout << "\nPizza Order System" << endl;
		cout << "1. Place Order" << endl;
		cout << "2. Serve Order" << endl;
		cout << "3. Display Orders" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter order ID: ";
			cin >> orderId;
			system.placeOrder(orderId);
			break;
		case 2:
			system.serveOrder();
			break;
		case 3:
			system.displayOrders();
			break;
		case 4:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);

	return 0;
}
