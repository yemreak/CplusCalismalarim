#include "sehir.h"
#include <string>
#include <cstring>
#include <cstdlib>

Sehir::Sehir(string okunacakDosyaAdi, string yazilacakDosyaAdi) {
	okunacakDosya.open(okunacakDosyaAdi.c_str());
	Sehir::yazilacakDosyaAdi = yazilacakDosyaAdi;

	verileriOlustur();
}

void Sehir::verileriOlustur() {
	string line;

	getline(okunacakDosya, line);
	getline(okunacakDosya, line);
	getline(okunacakDosya, line);

	while (!okunacakDosya.eof()) {
		// String'i char* yapma
		char *cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());

		char delim[] = "# "; // String ayirma karakterleri
		char *token = strtok(cstr, delim);
		sehirler.push_back(token); // Sehri ekleme

		vector<int> mesafe;

		while ((token = strtok(NULL, delim)) != NULL) { // Sonuna gelene kadar devam ediyoruz.
			mesafe.push_back(atoi(token)); // Char*'i int yaptik.
		}

		mesafeler.push_back(mesafe);
		delete[] cstr;

		getline(okunacakDosya, line);
	}
}

void Sehir::yakinIller() {
	string sehir; // Sehrin ismi
	int maxMesafe = 500; // 500km mesafesi.

	okunacakDosya.clear();
	okunacakDosya.seekg(0, ios::beg); // Dosyayi bastan okumak icin ilk basa geciyoruz.

	getline(okunacakDosya, sehir); // Satir okuma

	int i = 0; // Sayac
	for (i; i < sehirler.size(); i++) { // Sehrimizin vectordeki sirasini buluyoruz
		if (sehirler[i].compare(sehir) == 0) {
			break;
		}
			
	}

	vector<string> yakinIller;
	int j = 0;
	for (j; j < mesafeler[i].size(); j++) { // Buldugumuz sira ile mesafeler vectorunden uzunluklarda arama yapiyoruz.
		if (mesafeler[i][j] <= maxMesafe) { // Eger 500km den az veya esit ise kaydediyoruz.
			if (i == j)
				continue;
			yakinIller.push_back(sehirler[j]);
		}
	}

	ofstream dosya((yazilacakDosyaAdi + ".dat").c_str(), std::ofstream::out); // Bastan olusturup yazma
	dosya << endl << sehir << " iline 500 km sinir icinde en yakin iller:" << endl;
	
	for (i = 0; i < yakinIller.size(); i++) {
		dosya << yakinIller[i] << endl;
	}

	dosya.close();
}

void Sehir::mesafeBul() {
	string line, sehir1, sehir2;
	getline(okunacakDosya, line);

	// String'i char* yapma
	char *cstr = new char[line.length() + 1];
	strcpy(cstr, line.c_str());

	char delim[] = "-"; // String ayirma karakterleri
	char *token = strtok(cstr, delim);
	sehir1 = token; // Ilk sehir

	token = strtok(NULL, delim);
	sehir2 = token; // Ikinci sehir

	int i = 0;
	for (i; i < sehirler.size(); i++) { // Ilk sehrin kodunu buluyoruz
		if (sehir1.compare(sehirler[i]) == 0) {
			break;
		}
	}

	int j = 0;
	for (j; j < sehirler.size(); j++) { // Ikinci sehrin kodunu buluyoruz
		if (sehir2.compare(sehirler[j]) == 0) {
			break;
		}
	}

	ofstream dosya((yazilacakDosyaAdi + ".dat").c_str(), std::ofstream::app); // Eklemeli yazma
	dosya << endl << sehir1 << " - " << sehir2 << " arasi mesafe:" << endl;
	dosya << mesafeler[i][j] << "km" << endl;

	dosya.close();
}

void Sehir::uzakIller() {
	int minMesafe = 1400; // 500km mesafesi.

	ofstream dosya((yazilacakDosyaAdi + ".dat").c_str(),std::ofstream::app); // Eklemeli yazma
	dosya << endl << "Birbirine " << minMesafe << " km'den daha uzak olan iller:" << endl << endl;

	vector< vector <int> > temp; // Daha onceden eklenen sehirleri eklememek icin gecici bir vector tanimliyoruz.

	int i;
	for (i = 0; i < mesafeler.size(); i++) {
		int j;
		for (j = 0; j < mesafeler[i].size(); j++) {
			if (mesafeler[i][j] > minMesafe) {
				bool kaydet = true;
				
				int n;
				for (n = 0; n < temp.size(); n++) { // Daha onceden kayit ettik mi kontrolu
					if (i == temp[n][0] && j == temp[n][1] ||
						j == temp[n][0] && i == temp[n][1]) {
						kaydet = false;
					}
				}

				if (kaydet) {
					dosya << sehirler[i] << " - " << sehirler[j] << endl;
					
					vector<int> temp2; // Iki degeri bu vectore atayip kaydediyoruz.
					temp2.push_back(i);
					temp2.push_back(j);					
					temp.push_back(temp2);
				}
			}
		}
	}

	dosya.close();
}
