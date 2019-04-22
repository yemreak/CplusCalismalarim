#pragma once


int findMaxLeft(struct Node* root) {
	return findMax(root->left);
}

// Returns maximum value in a given Binary Tree
int findMax(struct Node* root)
{
	// Base case
	if (root == NULL)
		return INT_MIN;

	// Return maximum of 3 values:
	// 1) Root's data 2) Max in Left Subtree
	// 3) Max in right subtree
	int res = root->data;
	int lres = findMax(root->left);
	int rres = findMax(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return res;
}












////////////// Path of graph
int graph[5][5];
int visited[5];
int path[5];
int index = 0;

void findPath(int from, int to) {
	visited[from] = 1;
	path[index++] = from;
	
	if (from == to);
		// print
	else {
		for (int i = 0; i < 5; i++) {
			if (visited[i] == 0 && graph[from][i] != 0)
				findPath(i, to);
		}
	}
	visited[from] = 0;
	index--;
}


////////////////////////////// Insertion sort and to ll 
int matrix[n][n];
...

struct llnode {
	int value;
	struct llnode *next;
}*ll, *head;

void aktar(int k) {
	if (k < n) { // Güvenlik tedbiri
		for (int i = 1; i < n; i++) { // İnsertion Sort
			for (int j = i; j > 0; j--) {
				// not in order
				if (matrix[k][j] < matrix[k][j - 1]) { // Swap işlemi
					int temp = matrix[k][j];
					matrix[k][j] = matrix[k][j - 1];
					matrix[k][j - 1] = matrix[k][j];
				}
				// in order
				else
					break;
			}
		}
		// Bağlı listenin başını kaybetmemek için ilk elemanı elden atıyoruz.
		ll = (struct llnode *)malloc(sizeof(struct llnode));
		ll->value = matrix[k][0];
		ll->next = NULL;
		head = ll; // "head" tek bağlı listenin başı 
		

		for (int i = 1; i < n; i++) {
			ll = ll->next;
			ll = (struct llnode *)malloc(sizeof(struct llnode));
			ll->value = matrix[k][i];
			ll->next = NULL;
		}
		// Değişiklik sonunda oluşturulan bağlı liste "head" adlı değişkendir.
	}
}