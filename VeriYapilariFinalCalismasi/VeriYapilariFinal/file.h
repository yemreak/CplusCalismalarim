#pragma once

typedef struct _stdnt {
	int id;
	char name[20];
	int score;
}STUDENT;

FILE *file;

// Add data to "student.txt"
void fileAdd() {
	// Both of write and read
	file = fopen("stundent.txt", "a+");

	STUDENT s = fileGetData();

	fwrite(&s, sizeof(s), 1, file);
	fclose(file);
}

void fileReadSerial() {
	file = fopen("student.txt", "r");

	int num = fileGetNumberOfData();

	fseek(file, SEEK_CUR, 0);

	STUDENT s;

	for (int i = 0; i < num; i++) 
		fread(&s, sizeof(s), 1, file);
	
	fread(&s, sizeof(s), 1, file);
	filePrintData(s);
	fclose(file);
}

void fileReadDirectly() {
	file = fopen("student.exe", "r");
	
	STUDENT s;
	int num = fileGetNumberOfData();
	fseek(file, sizeof(s) * (num - 1), 0);
	fread(&s, sizeof(s), 1, file);
	filePrintData(s);
	fclose(file);
}

void filePrintData(STUDENT s) {
	printf("Id: %d\nName: %s\nScore: %d", s.id, s.name, s.score);
}

// Return number of data which user want to read
int fileGetNumberOfData() {
	int num;

	printf("Number of data: ");
	scanf_s("%d", &num);

	return num;
}

// Return data which created by user with value
STUDENT fileGetData() {
	STUDENT student;
	printf("-> Id: ");
	scanf_s("%d", &student.id);
	printf("-> Name: ");
	scanf_s("%s", &student.name);
	printf("-> Score: ");
	scanf_s("%d", &student.score);
	return student;
}

void mainFile() {
	while (1) {
		printf("*** *** ***\n");
		printf("      1    -->    Dosyaya kayit ekle                             \n");
		printf("      2    -->    Dosyadan kayit oku(sirali erisim ile)          \n");
		printf("      3    -->    Dosyadan kayit oku(dogrudan erisim ile)        \n");
		printf("      4    -->    Sonlandir                                      \n");
		printf("      5    -->    Erisim surelerini kiyasla                      \n");
		printf("*** *** ***\n");

		int selection;
		scanf_s("%d", &selection);

		switch (selection) {
		case 1:
			fileAdd();
			break;
		case 2:
			fileReadSerial();
			break;
		case 3:
			fileReadDirectly();
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
}