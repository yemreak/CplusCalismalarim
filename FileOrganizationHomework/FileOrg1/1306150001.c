// Yunus Emre AK
// 1306150001
// Visual Studio 2017 üzerinden yazılmıştır.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 0-499 books 5 x 30 shelf
#define SIZE_BUCKET 5
#define SIZE_CHAR 15
#define SIZE_SHELVES 30


// Second file contain the books
typedef struct book {
	int index;
	char name[SIZE_CHAR];
	char author[SIZE_CHAR];
}Book;

// First file contain the index data
typedef struct shelf {
	int value[SIZE_BUCKET];
}Shelf;

// Defination of bookshelf
Shelf bookshelf[SIZE_SHELVES];
FILE* file;

int hashing(int);
void printLine();
int compareStrings(char*, char*);

void writeBookshelf();
void writeBook(Book);
void writeBookName(int);

void printBook(Book);

void createBookshelf();
Book createBook(int, char*, char*);

int addToBookshelf(int);
void insertBook();

void searchBook(int);
void searchBookMenu();

void listAllBookshelf();

void menu();

int main() {
	createBookshelf();
	menu();
}


// Hash function
int hashing(int a) {
	return a % SIZE_SHELVES;
}

void printLine() {
	printf("--------------------------------------\n");
}

// 2 String'i büyük-küçük ayrımı yapmaksızın kontrol etme
int compareStrings(char* str_1, char* str_2) {
	int i = 0;
	while (str_1[i]) {
		str_1[i] = tolower(str_1[i]);
		i++;
	}
	i = 0;
	while (str_2[i]) {
		str_2[i] = tolower(str_2[i]);
		i++;
	}

	return strcmp(str_1, str_2);
}

// Kitaplık indexlerini oluşturma / dosyadan alma
void createBookshelf() {
	if ((file = fopen("index.txt", "r")) == NULL){
		for (int i = 0; i < SIZE_SHELVES; i++)
			for (int j = 0; j < SIZE_BUCKET; j++)
				bookshelf[i].value[j] = 0; // 0 atama
	}
	else {
		for (int i = 0; i < SIZE_SHELVES; i++) {
			int temp;
			fscanf(file, "%d ", &temp);
			for (int j = 0; j < SIZE_BUCKET; j++) {
				fscanf(file, "%d ",&bookshelf[i].value[j]);
			}
			fscanf(file, "\n");
		}

		fclose(file);
	}
}

// Kitap oluşturma
Book createBook(int i, char* name, char* author) {
	Book book;
	book.index = i;
	strcpy(book.name, name);
	strcpy(book.author, author);

	return book;
}

// Kitaplığa indexi kaydetme
int addToBookshelf(int i) {
	for (int a = 0; a < SIZE_BUCKET; a++) {
		if (bookshelf[hashing(i)].value[a] == 0) {
			bookshelf[hashing(i)].value[a] = i;
			return 1; // Succed
		}
	}
	printLine();
	printf("%s", "Insertion failed, there is no place !\n");
	return 0; // Fail
}

// Kitaplığı dosyaya yazma (index.txt)
void writeBookshelf() {
	if ((file = fopen("index.txt", "w+")) != NULL) {
		for (int i = 0; i < SIZE_SHELVES; i++) {
			fprintf(file, "%d ", i);

			for (int j = 0; j < SIZE_BUCKET; j++) {
				fprintf(file, "%d ", bookshelf[i].value[j]);
			}
			
			fprintf(file, "\n");
		}

		fclose(file);
	}
	
}

// Kitabı dosyaya yazma (book.txt)
void writeBook(Book b) {
	if ((file = fopen("book.txt", "a+")) != NULL) {
		fprintf(file, "%d %s %s \n", b.index, b.author, b.name);
		
		fclose(file);
	}
}

// Kitap yazma işlemi
void insertBook() {
	printLine();
	printf("%15s", "Type the index of the book\n");
	
	int i;
	scanf_s("%d", &i);
	
	if (addToBookshelf(i)) {
		writeBookshelf();

		printf("%15s", "Type the name of the book. [Don't use \" \" (ex. Iskender_Pala)]\n");
		char name[SIZE_CHAR];
		scanf("%s", &name);

		printf("%15s", "Type the author of the book. [Don't use \" \" (ex. Iskender_Pala)]\n");
		char author[SIZE_CHAR];
		scanf("%s", &author);

		writeBook(createBook(i, name, author)); 
	}

}

// Kitabı ekrana yazma
void printBook(Book b) {
	printLine();
	printf("Number of the book: %d\nAuthor of the book: %s\nName of the book: %s\n", b.index, b.author, b.name);
	printLine();
}


// Kitap arama
void searchBook(int type) {
	if ((file = fopen("book.txt", "r")) == NULL) {
		printf("File cannot found :(\n");
		return;
	}

	printLine();
	printf("Type data ->  ");
	
	char data[SIZE_CHAR];
	scanf("%s", data);

	switch (type){
		case 1:
			while (!feof(file)) {
				Book b;
				fscanf(file, "%d %s %s \n", &(b.index), b.author, b.name);
				if (b.index != 0 && b.index == atoi(data)) { // Casting string to int
					printBook(b);
					return;
				}
			}
			break;
		case 2:
			while (!feof(file)) {
				Book b;
				fscanf(file, "%d %s %s \n", &(b.index), b.author, b.name);
				if (b.index != 0 && !compareStrings(b.author, data)) { // Compare two string with lowercase
					printBook(b);
					return;
				}
			}
			break;
		case 3:
			while (!feof(file)) {
				Book b;
				fscanf(file, "%d %s %s \n", &(b.index), b.author, b.name);
				if (b.index != 0 && !compareStrings(b.name, data)) { // Compare two string with lowercase
					printBook(b);
					return;
				}
			}
			break;
	}

	printf("Book does not exist. \n");
	fclose(file);
}

// Kitap arama arayüzü
void searchBookMenu() {
	int answer;
	do {
		printLine();
		printf("%s", "1-) Search with \"book number\"\n");
		printf("%s", "2-) Search with \"author name\"\n");
		printf("%s", "3-) Search with \"book name\"\n");
		printf("%s", "4-) Back\n");
		printLine();

		scanf_s("%d", &answer);

		if (answer != 4) 
			searchBook(answer);
		
	} while (answer != 4);
}

// Index ile kitap ismini yazdırma
void writeBookName(int index) {
	FILE *books;
	if ((books = fopen("book.txt", "r")) == NULL) {
		printf("Book file cannot found :(\n");
		printf("%11s ", "Null");
		return;
	}

	while (!feof(books)) {
		Book b;
		fscanf(books, "%d %s %s \n", &(b.index), b.author, b.name);
		if (b.index == index) {
			printf("%11s ",b.name);
			return;
		}
	}

	fclose(books);

	printf("%11s ", "Null");
}

// Tüm kitapları gösterme
void listAllBookshelf() {
	if ((file = fopen("index.txt", "r")) != NULL) {
		printLine();
		printf("%11s %11s %11s %11s %11s %11s\n", "Shelf Num.", "B1", "B2", "B3", "B4", "B5");
		printLine();

		while (!feof(file)) {
			int i, b[5];
			fscanf(file, "%d %d %d %d %d %d\n", &i, &b[0], &b[1], &b[2], &b[3], &b[4]);

			printf("%11d ", i);
			for (int i = 0; i < 5; i++) 
				writeBookName(b[i]);
			
			printf("\n");
		}
	}
	else {
		printLine();
		printf("One of file cannot be openned or exist.\n");
	}
}

// Arayüz
void menu() {
	int answer;
	do {
		printLine();
		printf("\t 1306150001 Yunus Emre AK\n");
		printLine();
		printf("%s", "1-) Insert a book\n");
		printf("%s", "2-) Search a book\n");
		printf("%s", "3-) List all bookshelf\n");
		printf("%s", "4-) Exit\n");
		printLine();

		scanf_s("%d", &answer);

		switch (answer) {
		case 1:
			insertBook();
			break;
		case 2:
			searchBookMenu();
			break;
		case 3:
			listAllBookshelf();
			break;
		}

	} while (answer != 4);
	
}