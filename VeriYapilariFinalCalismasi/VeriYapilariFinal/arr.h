#pragma once

void show_spc(int arr[], int size, int tabSize) {
	for (int i = 0; i < tabSize; i++)
		printf(" ");
	printf("The array is: ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void show(int arr[], int size) {
	printf("The array is: ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void show_str(char* str, int arr[], int size) {
	printf(str);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}