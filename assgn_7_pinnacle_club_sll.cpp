#include <iostream>
#include <string>
using namespace std;

class Node
{
  public:
	int PRN;
	string name;
	Node* next;

	Node(int prn, string n) : PRN(prn), name(n), next(nullptr) {}
};

class PinnacleClub
{
  private:
	Node* head;

  public:
	PinnacleClub() : head(nullptr) {}

	void addMember(int prn, string name, bool isPresident = false, bool isSecretary = false)
	{
		Node* newNode = new Node(prn, name);
		if (isPresident) {
			newNode->next = head;
			head = newNode;
		} else if (isSecretary) {
			if (head == nullptr) {
				head = newNode;
			} else {
				Node* temp = head;
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				temp->next = newNode;
			}
		} else {
			if (head == nullptr) {
				cout << "Add a president first.\n";
				delete newNode;
				return;
			}
			Node* temp = head;
			while (temp->next != nullptr && temp->next->next != nullptr) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}

	void getInputAndAddMember()
	{
		int prn;
		string name;
		bool isPresident = false, isSecretary = false;
		cout << "Enter PRN: ";
		cin >> prn;
		cin.ignore(); // To ignore the newline
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Is this member President? (1 for Yes, 0 for No): ";
		cin >> isPresident;
		if (!isPresident) {
			cout << "Is this member Secretary? (1 for Yes, 0 for No): ";
			cin >> isSecretary;
		}
		addMember(prn, name, isPresident, isSecretary);
	}

	void deleteMember(int prn)
	{
		if (head == nullptr) {
			cout << "The list is empty. No members to delete.\n";
			return;
		}
		if (head->PRN == prn) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr && temp->next->PRN != prn) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			cout << "Member with PRN " << prn << " not found.\n";
			return;
		}
		Node* delNode = temp->next;
		temp->next = delNode->next;
		delete delNode;
	}

	int countMembers() const
	{
		int count = 0;
		Node* temp = head;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	void displayMembers() const
	{
		if (head == nullptr) {
			cout << "The list is empty.\n";
			return;
		}
		Node* temp = head;
		while (temp != nullptr) {
			cout << "PRN: " << temp->PRN << ", Name: " << temp->name << endl;
			temp = temp->next;
		}
	}

	void concatenate(PinnacleClub& otherClub)
	{
		if (head == nullptr) {
			head = otherClub.head;
			otherClub.head = nullptr;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = otherClub.head;
		otherClub.head = nullptr;
	}

	~PinnacleClub()
	{
		Node* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main()
{
	PinnacleClub divA, divB;
	int choice;

	do {
		cout << "\n---- Pinnacle Club Menu ----\n";
		cout << "1. Add Member to Division A\n";
		cout << "2. Add Member to Division B\n";
		cout << "3. Delete Member from Division A\n";
		cout << "4. Delete Member from Division B\n";
		cout << "5. Display Members of Division A\n";
		cout << "6. Display Members of Division B\n";
		cout << "7. Count Members in Division A\n";
		cout << "8. Count Members in Division B\n";
		cout << "9. Concatenate Division B to A\n";
		cout << "10. Concatenate Division A to B\n";
		cout << "11. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				divA.getInputAndAddMember();
				break;
			case 2:
				divB.getInputAndAddMember();
				break;
			case 3: {
				int prn;
				cout << "Enter PRN of member to delete: ";
				cin >> prn;
				divA.deleteMember(prn);
				break;
			}
			case 4: {
				int prn;
				cout << "Enter PRN of member to delete: ";
				cin >> prn;
				divB.deleteMember(prn);
				break;
			}
			case 5:
				divA.displayMembers();
				break;
			case 6:
				divB.displayMembers();
				break;
			case 7:
				cout << "Total members in Division A: " << divA.countMembers() << endl;
				break;
			case 8:
				cout << "Total members in Division B: " << divB.countMembers() << endl;
				break;
			case 9:
				divA.concatenate(divB);
				cout << "Division B concatenated to Division A.\n";
				break;
			case 10:
				divB.concatenate(divA);
				cout << "Division A concatenated to Division B.\n";
				break;
			case 11:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 11);

	return 0;
}
