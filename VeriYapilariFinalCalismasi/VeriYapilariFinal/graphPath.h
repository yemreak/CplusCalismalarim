#pragma once

#define SIZE 5

int graph[SIZE][SIZE];

int path[SIZE];
int visited[SIZE];

int index = 0;

void findPath(int from, int to);
void setVisitedFalse();
void setGraphRandom();
void printPath();

void mainGraph() {
	int from, to;
	do {
		srand(time(NULL));

		setVisitedFalse();
		setGraphRandom();

		printf("From [0-%d]: ", SIZE - 1);
		scanf_s("%d", &from);

		printf("To [0-%d]: ", SIZE - 1);
		scanf_s("%d", &to);

		findPath(from, to);
	} while (from != -1 || to != -1);

}

void findPath(int from, int to) {
	// The path will start from the from so it will be visited
	visited[from] = 1;
	path[index] = from;
	index++;

	if (from == to)
		printPath();
	else {
		for (int i = 0; i < SIZE; i++) {
			if (visited[i] == 0 && graph[i][from] != 0) {
				findPath(i, to);
			}
		}
	}
	// Set default the changed values
	visited[from] = 0;
	index--;
}

void setVisitedFalse() {
	for (int i = 0; i < SIZE; i++)
		visited[i] = 0;
}

void setGraphRandom() {
	for (int i = 0; i < SIZE; i++) {
		printf("\t[ ");
		for (int j = 0; j < SIZE; j++) {
			graph[i][j] = rand() % 2;
			printf("%d ", graph[i][j]);
		}
		printf("]\n");
	}
}

void printPath() {
	printf("Path: ");

	int i;
	for (i = 0; i < index - 1; i++)
			printf("%d -> ", path[i]);
		printf("%d", path[i]);
	printf("\n");
}