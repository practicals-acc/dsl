#include <iostream>
#define MAX 100
using namespace std;

void selectionSort(float arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		float temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}

int main()
{
	int n;
	float percentages[MAX];

	cout << "Enter the number of students (max " << MAX << "): ";
	cin >> n;

	if (n > MAX) {
		cout << "Error: Number of students exceeds maximum limit of " << MAX << ".\n";
		return 1;
	}

	cout << "Enter the percentages of students:\n";
	for (int i = 0; i < n; i++) {
		cout << "Percentage of student " << (i + 1) << ": ";
		cin >> percentages[i];
	}

	selectionSort(percentages, n);

	cout << "\nPercentages in ascending order (Selection Sort):\n";
	for (int i = 0; i < n; i++) {
		cout << percentages[i] << " ";
	}
	cout << endl;

	return 0;
}
