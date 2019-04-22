#pragma once
#include "arr.h"

void sortingShell(int arr[], int size);
void sortBubble(int arr[], int size);
void sortSelection(int arr[], int size);
void sortInsertion(int arr[], int size);
void sortQuick(int arr[], int begin, int end);
void sortingShell_detail(int arr[], int size);

int partition(int arr[], int begin, int end);


void mainSort() {
	// The array
	int arr[] = { 1, 14, 2, 8, 9, 7, 5 };

	// Do not edit this line !
	int size = sizeof(arr) / sizeof(int);

	// Print the begin array 
	show_str("The main array: ", arr, size);

	// Sorting (sort...)
	sortBubble(arr, size);

	// Print the last array.
	show(arr, size);
	
}

void sortingShell(int arr[], int size) {
	int h = 1;
	while (h * 3 + 1 < size)
		h = h * 3 + 1;
	while (h > 0) {
		for (int i = h - 1; i < size; i++) {
			int B = arr[i];
			int j = i;
			for (j; (j >= h) && (arr[j - h] > B); j -= h)
				arr[j] = arr[j - h];
			arr[j] = B;
		}
		h = (h - 1) / 3;
	}
}

void sortBubble(int arr[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 1; j < size - i; j++)
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
}

void sortSelection(int arr[], int size) {
	int min;
	for (int i = 0; i < size - 1; i++) {
		// Find the minimum element in unsorted array
		min = i;
		for (int j = i + 1; j < size; j++) 
			if (arr[j] < arr[min]) 
				min = j;
	
		swap(&arr[i], &arr[min]);
	}
}

void sortInsertion(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			// not in order
			if (arr[j - 1] > arr[j]) 
				swap(&arr[j - 1], &arr[j]);
			// in order
			else 
				break;
		}
	}
}

int partition(int arr[], int begin, int end) {
	int temp;
	int x = arr[begin];
	int i = begin;

	for (int j = begin + 1; j < end; j++) {
		if (arr[j] <= x) {
			temp = arr[++i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i];
	arr[i] = arr[begin];
	arr[begin] = temp;
	return i;
}

void sortQuick(int arr[], int begin, int end) {
	if (begin < end) {
		int q = partition(arr, begin, end);
		sortQuick(arr, begin, end - 1);
		sortQuick(arr, begin + 1, end);
	}
}

void sortingShell_detail(int arr[], int size) {
	printf("SHELL SORTING\n");
	int h = 1;
	while ((h * 3 + 1) < size)
		h = h * 3 + 1;
	while (h > 0) {
		printf("------ h = %d ------\n", h);
		for (int i = h - 1; i < size; i++) {
			printf("-> i = %d\n", i);
			int B = arr[i];
			int j = i;
			for (j; (j >= h) && (arr[j - h] > B); j -= h) {
				arr[j] = arr[j - h];
				printf("j = %d -> ", j);
				show(arr, size);
			}
			arr[j] = B;
			show(arr, size);
		}
		h = (h - 1) / 3;
	}
}