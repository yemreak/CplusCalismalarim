#pragma once
#define INFINITY 9999
#define MAX 5

int G[MAX][MAX];

int minKeyIndex(int key[], int mstSet[]);
int MSTprim();
void setG();


void mainMST() {
	setG();
	MSTprim();
}

int MSTprim() {
	int parent[MAX]; // Array to store constructed MST
	int key[MAX]; // Key values used to pick minimum weight edge in cut
	int mstSet[MAX]; // To represent set of vertices not yet included in MST
	
	// Initialize all key as INFINITE
	for (int i = 0; i < MAX; i++)
		key[i] = INT_MAX, mstSet[i] = 0;

	// Always include first 1st vertex in MST.
	key[0] = 0; // Make key 0 so that this vertex is picked as first
	parent[0] = -1; // First node is always root of MST

	// The MST will have MAX vertices
	for (int count = 0; count < MAX - 1; count++) {
		// Pick the minimum key vertex from the set of vertices
		// not yet included in MST
		int minIndex = minKeyIndex(key, mstSet);
		// Add the picked vertex to the MST set
		mstSet[minIndex] = 1;
	

		// Update the key value and parent index of the adjacent vertices of 
		// the picked vertex. Consider only those verices which are not
		// included in MST
		for (int i = 0; i < MAX; i++) {
			// graph[minIndex][i] is non zero only for adjacent vertices of m
			// mstSet[i] is false for vertices not yet included in MST
			// Update the key only if graph[minIndex][i] is smaller then key
			if (graph[minIndex][i] && mstSet[i] == 0 && G[minIndex][i] < key[i])
				parent[i] = minIndex, key[i] = G[minIndex][i];
		}
	}
}

void printMST(int parent[]) {
	printf("Edge weight:\n");
	for (int i = 0; i < MAX; i++)
		printf("%d - %d\t%d \n", parent[i], i, G[parent[i]][i]);
}
	

// A utility function to find the vertex with minimum key value, from
// the set of vertice not yet included in MST
int minKeyIndex(int key[], int mstSet[]) {
	// Initialize min value and index
	int min = INT_MAX, minIndex;

	for (int i = 0; i < MAX; i++) {
		if (mstSet[i] == 0 && key[i] < min)
			min = key[i], minIndex = i;
	}

	return minIndex;
}

void setG() {
	for (int i = 0; i < MAX; i++) {
		printf("\t[ ");
		for (int j = 0; j < MAX; j++) {
			if (i == j)
				G[i][j] = 0;
			else if (i > j)
				G[i][j] = G[j][i];
			else
				G[i][j] = rand() % 10;
			printf("%d   ", G[i][j]);
		}
		printf(" ]\n");
	}
}