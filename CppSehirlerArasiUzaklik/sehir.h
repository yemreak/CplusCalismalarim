#ifndef CITY_H
#define CITY_H

#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

class Sehir {
	private:
	vector<string> sehirler;
	vector< vector<int> > mesafeler;

	ifstream okunacakDosya;
	string yazilacakDosyaAdi;

	public:
	Sehir(string, string); // Constructer
	void verileriOlustur(); // private degiskenlerinin olusturulmasi
	void yakinIller(); // 500 km sinir icinde en yakin iller
	void uzakIller(); // 1400 km'den uzak iller.
	void mesafeBul(); // Iki sehir arası mesafe bulma.
	
};

#endif // !CITY_H
