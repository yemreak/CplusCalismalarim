//  Date : 12.14.2017
//  Development Environment : Visual Studio2017 

#include <iostream>

using namespace std;

void printLine();

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int size = atoi(argv[1]);

		int **matrix = (int**)malloc(sizeof(int*) * size);
		for (int i = 0; i < argc; i++)
			matrix[i] = (int*)malloc(sizeof(int) * size);

		bool error = false;

		for (int row = 0; row < size; row++) {
			for (int column = 0; column < size; column++) {
				// Spliting string
				int x = (int)(atoi(argv[2]) / pow(10, ((size - row) * size - column - 1))) % 10;

				if (row > 0 && x == 1 && matrix[row - 1][column] == 2) {
					error = true;
					printLine();
					cout << "NOT MATCH [" << row  << "][" << column << "] : 1" << endl;
					cout << "Reason: Rule 1" << endl;

				}
				if (column > 0 && x == 3 && matrix[row][column - 1] == 2) {
					error = true;
					printLine();
					cout << "NOT MATCH [" << row << "][" << column << "] : 3" << endl;
					cout << "Reason: Rule 2" << endl;

				}
				if (row > 0 && x == 4 && matrix[row - 1][column] == 3) {
					error = true;
					printLine();
					cout << "NOT MATCH [" << row << "][" << column << "] : 4" << endl;
					cout << "Reason: Rule 3" << endl;

				}
				if (column > 0 && x == 4 && matrix[row][column - 1] == 1) {
					error = true;
					printLine();
					cout << "NOT MATCH [" << row << "][" << column << "] : 4" << endl;
					cout << "Reason: Rule 4" << endl;

				}
				matrix[row][column] = x;
			}
		}
		if (!error) {
			printLine();
			cout << "ACCEPTED" << endl;
		}
	}
}

void printLine() {
	cout << "---------------------------" << endl;
}
