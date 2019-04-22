#include "_Karmasik.h"
#include <iostream>


Karmasik::Karmasik() {
	gercekKisim = 0;
	sanalKisim = 0;
}

Karmasik::Karmasik(float x, float y) {
	gercekKisim = x;
	sanalKisim = y;
}

float Karmasik::getGercekKisim() {
	return gercekKisim;
}

float Karmasik::getSanalKisim() {
	return sanalKisim;
}

void Karmasik::setGercekKisim(float x) {
	gercekKisim = x;
}

void Karmasik::setSanalKisim(float y) {
	sanalKisim = y;
}

void Karmasik::goster() {
	if (sanalKisim > 0)
		cout << gercekKisim << "+" << sanalKisim << "i" << endl;
	else 
		cout << gercekKisim << sanalKisim << "i" << endl;

}

Karmasik operator+(Karmasik k1, Karmasik k2) {
	Karmasik sonuc;

	sonuc.gercekKisim = k1.gercekKisim + k2.gercekKisim;
	sonuc.sanalKisim = k1.sanalKisim + k2.sanalKisim;

	return sonuc;
}

Karmasik operator-(Karmasik k1, Karmasik k2) {
	Karmasik sonuc;

	sonuc.gercekKisim = k1.gercekKisim - k2.gercekKisim;
	sonuc.sanalKisim = k1.sanalKisim - k2.sanalKisim;

	return sonuc;
}

Karmasik operator*(Karmasik k1, Karmasik k2) {
	Karmasik sonuc;

	sonuc.gercekKisim = k1.gercekKisim * k2.gercekKisim - k1.sanalKisim * k2.sanalKisim;
	sonuc.sanalKisim = k1.gercekKisim * k2.sanalKisim + k1.sanalKisim * k2.gercekKisim;

	return sonuc;
}

Karmasik operator/(Karmasik k1, Karmasik k2) {
	Karmasik sonuc;

	sonuc.gercekKisim = (k1.gercekKisim * k2.gercekKisim + k1.sanalKisim * k2.sanalKisim) / (k2.gercekKisim * k2.gercekKisim + k2.sanalKisim * k2.sanalKisim);
	sonuc.sanalKisim = (k1.sanalKisim * k2.gercekKisim - k1.gercekKisim * k2.sanalKisim) / (k2.gercekKisim * k2.gercekKisim + k2.sanalKisim * k2.sanalKisim);

	return sonuc;
}
