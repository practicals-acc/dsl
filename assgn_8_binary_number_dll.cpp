#include <iostream>
#include <string>
using namespace std;

class Node
{
  public:
	int data;
	Node* prev;
	Node* next;

	Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class BinaryNumber
{
  private:
	Node* head;
	Node* tail;

  public:
	BinaryNumber() : head(nullptr), tail(nullptr) {}

	void append(int value)
	{
		Node* newNode = new Node(value);
		if (!head) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void display()
	{
		Node* current = head;
		while (current) {
			cout << current->data;
			current = current->next;
		}
		cout << endl;
	}

	BinaryNumber computeOnesComplement()
	{
		BinaryNumber complement;
		Node* current = head;
		while (current) {
			complement.append(1 - current->data);
			current = current->next;
		}
		return complement;
	}

	BinaryNumber computeTwosComplement()
	{
		BinaryNumber onesComplement = computeOnesComplement();

		// Add 1 to the one's complement
		Node* current = onesComplement.tail;
		int carry = 1;

		while (current && carry) {
			int sum = current->data + carry;
			current->data = sum % 2;
			carry = sum / 2;
			current = current->prev;
		}

		// If carry is still 1, prepend it
		if (carry) {
			Node* newNode = new Node(1);
			newNode->next = onesComplement.head;
			onesComplement.head->prev = newNode;
			onesComplement.head = newNode;
		}

		return onesComplement;
	}

	static BinaryNumber addBinaryNumbers(BinaryNumber& num1, BinaryNumber& num2)
	{
		BinaryNumber result;
		Node* current1 = num1.tail;
		Node* current2 = num2.tail;

		int carry = 0;
		while (current1 || current2 || carry) {
			int sum = carry;
			if (current1) {
				sum += current1->data;
				current1 = current1->prev;
			}
			if (current2) {
				sum += current2->data;
				current2 = current2->prev;
			}
			result.append(sum % 2);
			carry = sum / 2;
		}

		// Reverse the result list
		result.reverse();
		return result;
	}

	void reverse()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp) {
			head = temp->prev;
		}
	}
};

int main()
{
	BinaryNumber binaryNumber1, binaryNumber2;

	string input1, input2;
	cout << "Enter the first binary number: ";
	cin >> input1;
	cout << "Enter the second binary number: ";
	cin >> input2;

	for (char digit : input1) {
		binaryNumber1.append(digit - '0');
	}

	for (char digit : input2) {
		binaryNumber2.append(digit - '0');
	}

	cout << "First binary number: ";
	binaryNumber1.display();

	cout << "Second binary number: ";
	binaryNumber2.display();

	BinaryNumber sum = BinaryNumber::addBinaryNumbers(binaryNumber1, binaryNumber2);
	cout << "Sum of binary numbers: ";
	sum.display();

	BinaryNumber onesComplement = binaryNumber1.computeOnesComplement();
	cout << "1's Complement of the first number: ";
	onesComplement.display();

	BinaryNumber twosComplement = binaryNumber1.computeTwosComplement();
	cout << "2's Complement of the first number: ";
	twosComplement.display();

	return 0;
}
