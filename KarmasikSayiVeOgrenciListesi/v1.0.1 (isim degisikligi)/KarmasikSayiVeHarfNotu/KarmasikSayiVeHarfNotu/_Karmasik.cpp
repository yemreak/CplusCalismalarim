#include "_Karmasik.h"
#include <iostream>
#include <cstring>

using namespace std;

void Karmasik::setSanalKisim(float y) {
	sanalKisim = y;
}

void Karmasik::goster() {
	if (gercekKisim != 0) {
		cout << gercekKisim;
	}
	
	if (sanalKisim > 0) {
		cout << "+" << sanalKisim << "i";
	} else if (sanalKisim < 0) {
		cout << "-" << sanalKisim << "i";
	} else if (gercekKisim == 0) {
		cout << 0;
	}
	
	cout << endl;
}


Karmasik::Karmasik(float x, float y) {
	gercekKisim = x;
	sanalKisim = y;
}

Karmasik operator+(Karmasik sayi1, Karmasik sayi2) {
	Karmasik sonuc;
	sonuc.gercekKisim = sayi1.gercekKisim + sayi2.gercekKisim;
	sonuc.sanalKisim = sayi1.sanalKisim + sayi2.sanalKisim;
	return sonuc;
}

Karmasik operator-(Karmasik sayi1, Karmasik sayi2) {
	Karmasik sonuc;
	sonuc.gercekKisim = sayi1.gercekKisim - sayi2.gercekKisim;
	sonuc.sanalKisim = sayi1.sanalKisim - sayi2.sanalKisim;
	return sonuc;
}


Karmasik::Karmasik() {
	gercekKisim = 0;
	sanalKisim = 0;
}


float Karmasik::getGercekKisim() {
	return gercekKisim;
}


Karmasik operator*(Karmasik sayi1, Karmasik sayi2) {
	Karmasik sonuc;
	// carpmanin dagilma ozelligini kullaniyoruz
	sonuc.gercekKisim = sayi1.gercekKisim * sayi2.gercekKisim - sayi1.sanalKisim * sayi2.sanalKisim;
	sonuc.sanalKisim = sayi1.gercekKisim * sayi2.sanalKisim + sayi1.sanalKisim * sayi2.gercekKisim;
	return sonuc;
}


void Karmasik::setGercekKisim(float x) {
	gercekKisim = x;
}

Karmasik operator/(Karmasik sayi1, Karmasik sayi2) {
	Karmasik sonuc;
	// eslenigi ile carpinca cikan sonuc.
	float gercekPay = sayi1.gercekKisim * sayi2.gercekKisim + sayi1.sanalKisim * sayi2.sanalKisim;
	float sanalPay = sayi1.sanalKisim * sayi2.gercekKisim - sayi1.gercekKisim * sayi2.sanalKisim;
	// payda iki kisim icin de ortaktýr
	float payda = sayi2.gercekKisim * sayi2.gercekKisim + sayi2.sanalKisim * sayi2.sanalKisim;
	sonuc.gercekKisim = gercekPay / payda;
	sonuc.sanalKisim = sanalPay / payda;
	return sonuc;
}


float Karmasik::getSanalKisim() {
	return sanalKisim;
}


