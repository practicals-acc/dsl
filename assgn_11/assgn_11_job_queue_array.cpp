#include <iostream>
#include <string>
using namespace std;

struct Job
{
	int id;
	string name;
};

class JobQueueArray
{
  private:
	static const int MAX_SIZE = 10;
	Job queue[MAX_SIZE];
	int front;
	int rear;
  
  public:
	JobQueueArray() : front(-1), rear(-1) {}

	void addJob(int jobId, string jobName)
	{
		if (rear == MAX_SIZE - 1) {
			cout << "Queue is full. Cannot add more jobs." << endl;
			return;
		}
		if (front == -1 && rear == -1) {
			front = 0;
			rear = 0;
		} else {
			rear++;
		}
		queue[rear] = {jobId, jobName};
		cout << "Job added: [ID: " << jobId << ", Name: " << jobName << "]" << endl;
	}

	void deleteJob()
	{
		if (front == -1 && rear == -1) {
			cout << "Queue is empty. No jobs to delete." << endl;
			return;
		}
		cout << "Job deleted: [ID: " << queue[front].id << ", Name: " << queue[front].name << "]" << endl;
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front++;
		}
	}

	void displayQueue()
	{
		if (front == -1 && rear == -1) {
			cout << "Queue is empty." << endl;
			return;
		}
		cout << "Job Queue (Array): " << endl;
		for (int i = front; i <= rear; i++) {
			cout << "[ID: " << queue[i].id << ", Name: " << queue[i].name << "]" << endl;
		}
	}
};

int main()
{
	JobQueueArray jobQueue;
	int choice, jobId;
	string jobName;

	do {
		cout << "\nJob Queue Simulation (Array)" << endl;
		cout << "1. Add Job" << endl;
		cout << "2. Delete Job" << endl;
		cout << "3. Display Queue" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter Job ID: ";
			cin >> jobId;
			cout << "Enter Job Name: ";
			cin.ignore();
			getline(cin, jobName);
			jobQueue.addJob(jobId, jobName);
			break;
		case 2:
			jobQueue.deleteJob();
			break;
		case 3:
			jobQueue.displayQueue();
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
