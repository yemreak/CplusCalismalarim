#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Ogrenci struct yapisi
struct Ogrenci {
	int ogrenciId;
	string ad;
	string soyad;
	int sinav1, sinav2, sinav3;
	int toplamSkor;
	char harfNotu;
};

// Global degiskenler
vector<Ogrenci> ogrenciler;

vector<int> enDusukler;
vector<int> enYuksekler;
vector<float> ortalamalar;
vector<float> standartSapmalar;


void dosyadanVerileriAl(string dosyaAdi) 
{
	// dosyayi okumak için ifstream kullaniyoruz.
	ifstream dosya;
	dosya.open(dosyaAdi.c_str());
	
	// dosyadaki her string'i kelimeye atýyacagiz
	string kelime;
	
	// Eger dosya acildiysa okuyoruz.
	if (dosya.is_open()) {
		// Dosyanin sonuna kadar okuyacagiz.
		while (true) {
			Ogrenci ogrenci;
			
			// Kelimeleri sutunlara ayirmak icin kullanacagiz.
			int sutun = 0;
			for (sutun; sutun < 6; sutun++) {
				// Bosluga kadar olan her kelime tek tek aliyoruz.
				dosya >> kelime;
				
				// Eger dosyanin sonundaysak, fonksiyonu bitiriyoruz.
				if (dosya.eof()) {
					// Dosyayi kapatiyoruz.
					dosya.close();
					return;
				}
				
				// Kacinci sutunda oldugunu bulup atama yapiyoruz.
				switch (sutun % 6) {
					case 0:
						// String'i int'e cevirip atama yapiyoruz.
						ogrenci.ogrenciId = atoi(kelime.c_str());
						break;
					case 1:
						ogrenci.ad = kelime;
						break;
					case 2:
						ogrenci.soyad = kelime;
						break;
					case 3:
						ogrenci.sinav1 = atoi(kelime.c_str());
						break;
					case 4:
						ogrenci.sinav2 = atoi(kelime.c_str());
						break;
					case 5:
						ogrenci.sinav3 = atoi(kelime.c_str());
						ogrenciler.push_back(ogrenci);
						break;
				}
			}
		}
	}
}

void toplamSkorVeHarfHesapla() 
{
	// Ogrencilerin eksik bilgilerini hesapliyoruz.
	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		// Toplam skor hesaplaniyor
		ogrenciler[i].toplamSkor = ogrenciler[i].sinav1 + ogrenciler[i].sinav2 + ogrenciler[i].sinav3;

		// Harf notunlarýn toplam skora gore hesaplayip atamasini yapiyoruz.
		if (ogrenciler[i].toplamSkor >= 270){
			ogrenciler[i].harfNotu = 'A';
		}
		else if (ogrenciler[i].toplamSkor < 270 && ogrenciler[i].toplamSkor >= 240){
			ogrenciler[i].harfNotu = 'B';
		}
		else if (ogrenciler[i].toplamSkor < 240 && ogrenciler[i].toplamSkor >= 210){
			ogrenciler[i].harfNotu = 'C';
		}
		else if (ogrenciler[i].toplamSkor < 210 && ogrenciler[i].toplamSkor >= 180){
			ogrenciler[i].harfNotu = 'D';
		}
		else if (ogrenciler[i].toplamSkor < 180){
			ogrenciler[i].harfNotu = 'F';
		}
	}
}

void yerDegistir(int ilk, int ikinci) 
{
	// Gecici bir ogrenci elemani tanimlayarak verinin silinmesini engelliyoruz.
	Ogrenci gecici;

	gecici = ogrenciler[ilk]; 
	ogrenciler[ilk] = ogrenciler[ikinci];
	ogrenciler[ikinci] = gecici; 
}

// Verileri kabarcik siralamasina gore siralayan fonksiyon
void kabarcikSiralamasi()
{
   int i, j;
   for (i = 0; i < ogrenciler.size() - 1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < ogrenciler.size()-i-1; j++) 
           if (ogrenciler[j].toplamSkor < ogrenciler[j + 1].toplamSkor)
              yerDegistir(j, j + 1);
}

void istatislikHesapla() 
{
	// En yuksek sinav 100, en yuksek skor da 300 olabilir. Bu sebeple max degerlderden baslatiryoruz.
	enDusukler.push_back(100);
	enDusukler.push_back(100);
	enDusukler.push_back(100);
	enDusukler.push_back(300);
	
	// En dusuk sinav ve skor 0 olabilir. Bu sebeple min degerlerden baslatiryoruz.
	enYuksekler.push_back(0);
	enYuksekler.push_back(0);
	enYuksekler.push_back(0);
	enYuksekler.push_back(0);
	
	// Toplam skorlar
	vector<int> toplamlar;
	
	// Toplamda etkisiz deger olan 0 degerini veriyoruz.
	toplamlar.push_back(0);
	toplamlar.push_back(0);
	toplamlar.push_back(0);
	toplamlar.push_back(0);
	
	// StandartSapmamiza etkisiz deger olan 0 degerini veriyoruz.
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	standartSapmalar.push_back(0);
	
	// Degerlerin hesaplanmasi
	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		// En kucugu hesaplama
		if (ogrenciler[i].sinav1 < enDusukler[0])
			enDusukler[0] = ogrenciler[i].sinav1;
		// En buyugu hesaplama
		if (ogrenciler[i].sinav1 > enYuksekler[0])
			enYuksekler[0] = ogrenciler[i].sinav1;
			
			
		// En kucugu hesaplama
		if (ogrenciler[i].sinav2 < enDusukler[1])
			enDusukler[1] = ogrenciler[i].sinav2;
		// En buyugu hesaplama
		if (ogrenciler[i].sinav2 > enYuksekler[1])
			enYuksekler[1] = ogrenciler[i].sinav2;
			
		// En kucugu hesaplama
		if (ogrenciler[i].sinav3 < enDusukler[2])
			enDusukler[2] = ogrenciler[i].sinav3;
		// En buyugu hesaplama
		if (ogrenciler[i].sinav3 > enYuksekler[2])
			enYuksekler[2] = ogrenciler[i].sinav3;
			
			
		// En kucugu hesaplama
		if (ogrenciler[i].toplamSkor < enDusukler[3])
			enDusukler[3] = ogrenciler[i].toplamSkor;
		// En buyugu hesaplama
		if (ogrenciler[i].toplamSkor > enYuksekler[3])
			enYuksekler[3] = ogrenciler[i].toplamSkor;
			
		// Ortalama icin toplam puani hesapliyoruz
		toplamlar[0] += ogrenciler[i].sinav1;
		toplamlar[1] += ogrenciler[i].sinav2;
		toplamlar[2] += ogrenciler[i].sinav3;
		toplamlar[3] += ogrenciler[i].toplamSkor;
		
	}
	
	// Toplami, ogrenci sayisina boluyoruz ve ortalamayi hesapliyoruz.
	for (i = 0; i < toplamlar.size(); i++) {
		// Takilama islemi yapmak zorundayiz yoksa virgulden sonrasinin verisi kaybolur.
		ortalamalar.push_back((float)toplamlar[i] / ogrenciler.size());
	}
	
	// Yeni bir for dongusunde standart sapma hesapliyoruz. Cunku ortalamanin hesaplanmis olmasi lazim
	for (i = 0; i < ogrenciler.size(); i++) {
		standartSapmalar[0] += pow(ogrenciler[i].sinav1 - ortalamalar[0], 2);
		standartSapmalar[1] += pow(ogrenciler[i].sinav2 - ortalamalar[1], 2);
		standartSapmalar[2] += pow(ogrenciler[i].sinav3 - ortalamalar[2], 2);
		standartSapmalar[3] += pow(ogrenciler[i].toplamSkor - ortalamalar[3], 2);
		
	}

	for (i = 0; i < standartSapmalar.size(); i++) {
		standartSapmalar[i] = sqrt(standartSapmalar[i] * (1.0 / (ogrenciler.size() - 1)));
	}
	
}

int main() 
{
	dosyadanVerileriAl("dosya.txt");
	toplamSkorVeHarfHesapla();
	kabarcikSiralamasi();
	
	istatislikHesapla();
	
	// Ekrana yazdirma
	cout << left;
	cout << setw(3) << "";
	cout << setw(12) << "OgrenciID";
	cout << setw(9) << "Ad";
	cout << setw(14) << "Soyad";
	cout << setw(9) << "Sinav1";
	cout << setw(9) << "Sinav2";
	cout << setw(9) << "Sinav3";
	cout << setw(12) << "ToplamSkor";
	cout << setw(9) << "Not" << endl;
	
	int i;
	for (i = 0; i < ogrenciler.size(); i++) {
		cout << setw(3) << i + 1;
		cout << setw(12) << ogrenciler[i].ogrenciId;
		cout << setw(9) << ogrenciler[i].ad;
		cout << setw(14) << ogrenciler[i].soyad;
		cout << setw(9) << ogrenciler[i].sinav1;
		cout << setw(9) << ogrenciler[i].sinav2;
		cout << setw(9) << ogrenciler[i].sinav3;
		cout << setw(12) << ogrenciler[i].toplamSkor;
		cout << setw(9) << ogrenciler[i].harfNotu << endl;
	}
	
	cout << endl;
	cout << setw(24) << "";
	cout << setw(14) << "En Dusuk:";
	cout << setw(9) << enDusukler[0];
	cout << setw(9) << enDusukler[1];
	cout << setw(9) << enDusukler[2];
	cout << setw(12) << enDusukler[3];
	cout << endl;
	
	cout << setw(24) << "";
	cout << setw(14) << "En Yuksek:";
	cout << setw(9) << enYuksekler[0];
	cout << setw(9) << enYuksekler[1];
	cout << setw(9) << enYuksekler[2];
	cout << setw(12) << enYuksekler[3];
	cout << endl;

	cout << setw(24) << "";
	cout << setw(14) << "Ortalama:";
	cout << setw(9) << ortalamalar[0];
	cout << setw(9) << ortalamalar[1];
	cout << setw(9) << ortalamalar[2];
	cout << setw(12) << ortalamalar[3];
	cout << endl;

	cout << setw(24) << "";
	cout << setw(14) << "Std Sapma:";
	cout<< setw(9) << standartSapmalar[0];
	cout << setw(9) << standartSapmalar[1];
	cout << setw(9) << standartSapmalar[2];
	cout << setw(12) << standartSapmalar[3];
	cout << endl;
	
	system("pause");
}



























