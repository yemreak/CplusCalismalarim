#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

// Ogrenci yapisi
struct Ogrenci {
	int ogrenciId;
	string ad;
	string soyad;
	int sinav1, sinav2, sinav3;
	int toplamSkor;
	char harfNotu;
};

// Dosyayi okuyup, verileri parametreye ekleme.
void dosyayiOku();

// Satiri stringlere parcalama
vector<string> parcala(string, char);

// Toplam skoru ve harf notunu hesaplama
void skorVeHarfHesapla();

// Toplam skora gore verileri siralama
void verileriSirala();

// Yer degistirme islemi
void yerDegistir(int, int);

// En dusuk notlari hesaplama
vector<int> enDusukHesapla();

// En yüksek notlari hesaplama
vector<int> enYuksekHesapla();

// Ortalama hesaplama
vector<float> ortalamaHesapla();

// Standart sapma hesaplama
vector<float> standartSapmaHesapla();

// Ekrana veriyi yazdirma
void ekranaVeriyiBas();

// Ogrencilerin verisini tutan degiskenler
vector<Ogrenci> ogrenciler;

int main() {
	// Turkce dil destegi	
	setlocale(LC_ALL, "Turkish");

	dosyayiOku();
	skorVeHarfHesapla();
	verileriSirala();
	
	vector<int> enDusuk = enDusukHesapla();
	vector<int> enYuksek = enYuksekHesapla();
	vector<float> ortalamalar = ortalamaHesapla();
	vector<float> standartSapmalar = standartSapmaHesapla();
	
	ekranaVeriyiBas();

	system("pause");
}

void dosyayiOku() {

	ifstream okunacakDosya("dosya.txt", ios::in); // Dosya okuma degiskeni.
	string line;
	
	// Dosyayi sonuna kadar satir satir okuma
	while (getline(okunacakDosya, line)) {
		Ogrenci ogrenci;

		// String'i char* yapma
		char *cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());

		// Okunan satiri stringlere ayiriyoruz ve verileri sirayla degiskenlere atiyoruz.
		char delim[] = " "; // String ayirma karakterleri

		char *token = strtok(cstr, delim);
		ogrenci.ogrenciId = atoi(token); // Ogrenci id'sini aldik.
		
		token = strtok(NULL, delim);
		ogrenci.ad = token;

		token = strtok(NULL, delim);
		ogrenci.soyad = token;

		token = strtok(NULL, delim);
		ogrenci.sinav1 = atoi(token);

		token = strtok(NULL, delim);
		ogrenci.sinav2 = atoi(token);

		token = strtok(NULL, delim);
		ogrenci.sinav3 = atoi(token);

		ogrenciler.push_back(ogrenci); // Vector'e ogrenci verimizi ekliyoruz
	}
}

vector<string> parcala(string str, char delimiter) {
	vector<string> parcalanmisVeri; // Toplam verimiz.
	stringstream ss(str); // Stringi stream'a ceviriyoruz.
	string tok; // Her bir veri parcasi

	while (getline(ss, tok, delimiter)) {
		parcalanmisVeri.push_back(tok);
	}

	return parcalanmisVeri;
}

void skorVeHarfHesapla() {
	int i;

	// Her ogrenci icin eksik bilgileri hesaplama ve atama
	for (i = 0; i < ogrenciler.size(); i++) {
		// Toplam skoru hesaplama ve atama
		ogrenciler[i].toplamSkor = ogrenciler[i].sinav1 + ogrenciler[i].sinav2 + ogrenciler[i].sinav3;

		// Harf notunu hesaplama ve atama
		if (ogrenciler[i].toplamSkor >= 270)
			ogrenciler[i].harfNotu = 'A';
		else if (ogrenciler[i].toplamSkor >= 240 && ogrenciler[i].toplamSkor < 270)
			ogrenciler[i].harfNotu = 'B';
		else if (ogrenciler[i].toplamSkor >= 210 && ogrenciler[i].toplamSkor < 240)
			ogrenciler[i].harfNotu = 'C';
		else if (ogrenciler[i].toplamSkor >= 180 && ogrenciler[i].toplamSkor < 210)
			ogrenciler[i].harfNotu = 'D';
		else if (ogrenciler[i].toplamSkor < 180)
			ogrenciler[i].harfNotu = 'F';
	}
}

void verileriSirala() {
	int i, j; // Indexler
	
	// Bir fazlasi ile islem yapilacaginda "size() - 1" e kadar gidiyoruz.
	for (i = 0; i < ogrenciler.size() - 1; i++) {
		// Her degisim islemini, baslangic noktasini oteyerek tekrar ediyoru ki buyukten kucuge siralansin.
		for (j = i + 1; j < ogrenciler.size(); j++) {
			// Eger ikinci birinciden buyukse yer degisitirecegiz.
			if (ogrenciler[i].toplamSkor < ogrenciler[j].toplamSkor) {
				yerDegistir(i, j);
			}
		}
	}
}

void yerDegistir(int i0, int i1) {
	Ogrenci gecici;

	gecici = ogrenciler[i0]; // Ilk veri kaybolmasin diye yedekliyoruz.
	ogrenciler[i0] = ogrenciler[i1]; // Ikinci veriyi ilkinin yerine aliyoruz.
	ogrenciler[i1] = gecici; // Yedekledigimiz (ilk) veriyi de ikincinin yerine koyuyoruz.
}

vector<int> enDusukHesapla() {
	// En dusuk notlari vectorde tutuyoruz.
	vector<int> enDusuk;

	// 100'dan yuksek not olmayacagi icin baslangic degerimiz 100.
	enDusuk.push_back(100);
	enDusuk.push_back(100);
	enDusuk.push_back(100);

	// 300'den yuksek skor olmayacagi icin baslangic degerimiz 300.
	enDusuk.push_back(1000);

	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		// Eger ogrencinin notu en dusukten kucukse, en dusugu guncelliyoruz.
		if (ogrenciler[i].sinav1 < enDusuk[0])
			enDusuk[0] = ogrenciler[i].sinav1;
		// Eger ogrencinin notu en dusukten kucukse, en dusugu guncelliyoruz.
		if (ogrenciler[i].sinav2 < enDusuk[1])
			enDusuk[1] = ogrenciler[i].sinav2;
		// Eger ogrencinin notu en dusukten kucukse, en dusugu guncelliyoruz.
		if (ogrenciler[i].sinav3 < enDusuk[2])
			enDusuk[2] = ogrenciler[i].sinav3;
		// Eger ogrencinin toplam skoru en dusukten kucukse, en dusugu guncelliyoruz.
		if (ogrenciler[i].toplamSkor < enDusuk[3])
			enDusuk[3] = ogrenciler[i].toplamSkor;
	}

	return enDusuk;
}

vector<int> enYuksekHesapla() {
	// En dusuk notlari vectorde tutuyoruz.
	vector<int> enYuksek;

	// 0'dan dusuk not olmayacagi icin baslangic degerimiz 0.
	enYuksek.push_back(0);
	enYuksek.push_back(0);
	enYuksek.push_back(0);
	enYuksek.push_back(0);

	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		// Eger ogrencinin notu en yuksekten buyukse, en yuksegi guncelliyoruz.
		if (ogrenciler[i].sinav1 > enYuksek[0])
			enYuksek[0] = ogrenciler[i].sinav1;
		// Eger ogrencinin notu en yuksekten buyukse, en yuksegi guncelliyoruz.
		if (ogrenciler[i].sinav2 > enYuksek[1])
			enYuksek[1] = ogrenciler[i].sinav2;
		// Eger ogrencinin notu en yuksekten buyukse, en yuksegi guncelliyoruz.
		if (ogrenciler[i].sinav3 > enYuksek[2])
			enYuksek[2] = ogrenciler[i].sinav3;
		// Eger ogrencinin toplam skoru en yuksekten buyukse, en yuksegi guncelliyoruz.
		if (ogrenciler[i].toplamSkor > enYuksek[3])
			enYuksek[3] = ogrenciler[i].toplamSkor;
	}

	return enYuksek;
}

vector<float> ortalamaHesapla() {
	// En dusuk notlari vectorde tutuyoruz.
	vector<float> ortalamalar;

	// 0'dan dusuk not olmayacagi icin baslangic degerimiz 0.
	ortalamalar.push_back(0);
	ortalamalar.push_back(0);
	ortalamalar.push_back(0);
	ortalamalar.push_back(0);

	// Her sinav notunu topluyoruz.
	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		ortalamalar[0] += ogrenciler[i].sinav1;
		ortalamalar[1] += ogrenciler[i].sinav2;
		ortalamalar[2] += ogrenciler[i].sinav3;
		ortalamalar[3] += ogrenciler[i].toplamSkor;
	}

	// Toplami, ogrenci sayisina boluyoruz.
	int j;
	for (j = 0; j < ortalamalar.size(); j++) {
		ortalamalar[j] /= ogrenciler.size();
	}

	return ortalamalar;
}

vector<float> standartSapmaHesapla() {
	// Standart sapmanin tutuldugu degisken
	vector<float> standartSapmalar;
	
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	
	// Aritmatik ortalamayi hesapliyoruz.
	vector<float> aritmatikOrtalamalar = ortalamaHesapla();

	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		standartSapmalar[0] += pow(ogrenciler[i].sinav1 - aritmatikOrtalamalar[0], 2);
		standartSapmalar[1] += pow(ogrenciler[i].sinav2 - aritmatikOrtalamalar[1], 2);
		standartSapmalar[2] += pow(ogrenciler[i].sinav3 - aritmatikOrtalamalar[2], 2);
		standartSapmalar[3] += pow(ogrenciler[i].toplamSkor - aritmatikOrtalamalar[3], 2);
		
	}
	
	int j;
	for (j = 0; j < standartSapmalar.size(); j++) {
		standartSapmalar[j] = sqrt(standartSapmalar[j] * (1.0 / (ogrenciler.size() - 1)));
	}
	
	return standartSapmalar;
}

void ekranaVeriyiBas() {
	cout << setw(15) << "OgrenciID" << setw(9) << "Ad" << setw(14) << "Soyad";
	cout << setw(9) << "Sinav1" << setw(9) << "Sinav2" << setw(9) << "Sinav3";
	cout << setw(12) << "ToplamSkor" << setw(9) << "Not" << endl;
	
	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		cout << setw(2) << i + 1 << setw(13) << ogrenciler[i].ogrenciId << setw(9) << ogrenciler[i].ad << setw(14) << ogrenciler[i].soyad;
		cout << setw(9) << ogrenciler[i].sinav1 << setw(9) << ogrenciler[i].sinav2 << setw(9) << ogrenciler[i].sinav3;
		cout << setw(12) << ogrenciler[i].toplamSkor << setw(9) << ogrenciler[i].harfNotu << endl;
	}
	
	cout << endl;

	vector<int> enDusuk = enDusukHesapla();
	cout << setw(38) << "En Dusuk:" << setw(9) << enDusuk[0] << setw(9) << enDusuk[1];
	cout << setw(9) << enDusuk[2] << setw(12) << enDusuk[3] << endl;

	vector<int> enYuksek = enYuksekHesapla();
	cout << setw(38) << "En Yuksek:" << setw(9) << enYuksek[0] << setw(9) << enYuksek[1];
	cout << setw(9) << enYuksek[2] << setw(12) << enYuksek[3] << endl;

	vector<float> ortalama = ortalamaHesapla();
	cout << setw(38) << "Ortalama:" << setw(9) << ortalama[0] << setw(9) << ortalama[1];
	cout << setw(9) << ortalama[2] << setw(12) << ortalama[3] << endl;

	vector<float> standartSapma = standartSapmaHesapla();
	cout << setw(38) << "Std Sapma:" << setw(9) << standartSapma[0] << setw(9) << standartSapma[1];
	cout << setw(9) << standartSapma[2] << setw(12) << standartSapma[3] << endl;
}


























