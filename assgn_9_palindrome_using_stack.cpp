#include <iostream>

#define MAX 20

using namespace std;

class Stack
{
	char stack[MAX];
	int top;

 public:
	Stack()
	{
		top = -1;
	}

	int empty()
	{
		return top == -1;
		/* OR
		 * if (top == -1) {
		 * 	return 1;
		 * } else {
		 * 	return 0;
		 * }
		 */
	}

	int full()
	{
		return top == MAX - 1;
		/* OR
		 * if (top == MAX - 1) {
		 * 	return 1;
		 * } else {
		 * 	return 0;
		 * }
		 */
	}

	void push(char ch)
	{
		if (full()) {
			cout<<"Stack is full! Cannot push\n";
		} else {
			stack[++top] = ch;
		}
	}

	char pop()
	{
		if (empty()) {
			cout<<"Stack is empty! Cannot pop\n";
			return '\0';
		} else {
			return stack[top--];
		}
	}
};

int main(void)
{
	char input[MAX], reverse[MAX];
	int i, palindrome = 1;
	Stack stack;

	cout<<"Enter a string: ";
	cin>>input;
	cout<<"Original String: "<<input<<endl;

	for (i = 0; input[i] != '\0'; i++) {
		stack.push(input[i]);
	}

	for (i = 0; !stack.empty(); i++) {
		reverse[i] = stack.pop();
	}
	reverse[i] = '\0';

	cout<<"Reversed String: "<<reverse<<endl;

	for (i = 0; input[i] != '\0'; i++) {
		if (input[i] != reverse[i]) {
			palindrome = 0;
			break;
		}
	}

	if (palindrome) {
		cout<<"String is a palindrome.\n";
	} else {
		cout<<"String is NOT a palindrome.\n";
	}

	return 0;
}
