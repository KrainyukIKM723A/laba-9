#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		int max = a[i][0];
		for (int j = 1; j < m; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		cout << max << " ";
	}
	cout << endl;

	
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][i] < 0) {
			sum += a[i][i];
			cnt++;
		}
	}
	double avg = (cnt == 0) ? 0 : (double)sum / cnt;

	cout << avg << endl;

	return 0;
}


#include <iostream>

using namespace std;

int* findMax(int** matrix, int m, int n) {
	int* maxValues = new int[m];

	for (int i = 0; i < m; ++i) {
		int maxVal = matrix[i][0];
		for (int j = 1; j < n; ++j) {
			if (matrix[i][j] > maxVal) {
				maxVal = matrix[i][j];
			}
		}
		maxValues[i] = maxVal;
	}

	return maxValues;
}

int main() {
	int m, n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;


	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << "Input matrix:" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int* maxValues = findMax(matrix, m, n);

	cout << "Maximum elements in each row:" << endl;
	for (int i = 0; i < m; ++i) {
		cout << maxValues[i] << " ";
	}
	cout << endl;

	return 0;
}


#include <iostream>

using namespace std;

double findAvg(int** matrix, int m, int n) {
	int count = 0;
	double sum = 0.0;

	for (int i = 0; i < min(m, n); ++i) {
		if (matrix[i][i] < 0) {
			sum += matrix[i][i];
			count++;
		}
	}

	if (count == 0)
		return 0;

	return (double)(sum / count);
}

int main() {
	int m, n;
	cout << "Enter size: ";
	cin >> m;
	n = m;
	int** matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << "Input matrix:" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	double average = findAvg(matrix, m, n);

	cout << "Average of negative elements on the main diagonal: " << average << endl;

	return 0;
}