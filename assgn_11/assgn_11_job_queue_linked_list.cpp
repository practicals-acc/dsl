#include <iostream>
#include <string>
using namespace std;

class Job
{
  public:
	int id;
	string name;
	Job* next;

	Job(int jobId, string jobName) : id(jobId), name(jobName), next(nullptr) {}
};

class JobQueueLinkedList
{
  private:
	Job* front;
	Job* rear;

  public:
	JobQueueLinkedList() : front(nullptr), rear(nullptr) {}

	void addJob(int jobId, string jobName)
	{
		Job* newJob = new Job(jobId, jobName);
		if (!rear) {
			front = rear = newJob;
		} else {
			rear->next = newJob;
			rear = newJob;
		}
		cout << "Job added: [ID: " << jobId << ", Name: " << jobName << "]" << endl;
	}

	void deleteJob()
	{
		if (!front) {
			cout << "Queue is empty. No jobs to delete." << endl;
			return;
		}
		Job* temp = front;
		front = front->next;
		if (!front) {
			rear = nullptr;
		}
		cout << "Job deleted: [ID: " << temp->id << ", Name: " << temp->name << "]" << endl;
		delete temp;
	}

	void displayQueue()
	{
		if (!front) {
			cout << "Queue is empty." << endl;
			return;
		}
		cout << "Job Queue (Linked List): " << endl;
		Job* current = front;
		while (current) {
			cout << "[ID: " << current->id << ", Name: " << current->name << "]" << endl;
			current = current->next;
		}
	}
};

int main()
{
	JobQueueLinkedList jobQueue;
	int choice, jobId;
	string jobName;

	do {
		cout << "\nJob Queue Simulation (Linked List)" << endl;
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
