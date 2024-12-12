#include <iostream>
using namespace std;

void bubbleSort(float* arr, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				float temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number of students: ";
	cin >> n;

	float* percentages = new float[n];

	cout << "Enter the percentages of students:\n";
	for (int i = 0; i < n; i++) {
		cout << "Percentage of student " << (i + 1) << ": ";
		cin >> percentages[i];
	}

	bubbleSort(percentages, n);

	cout << "\nPercentages in ascending order (Bubble Sort):\n";
	for (int i = 0; i < n; i++) {
		cout << percentages[i] << " ";
	}
	cout << endl;

	delete[] percentages;

	return 0;
}
