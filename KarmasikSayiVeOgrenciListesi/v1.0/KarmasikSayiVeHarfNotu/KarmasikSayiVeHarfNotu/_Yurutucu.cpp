#include "_Karmasik.h"
#include <iostream>
using namespace std;

void islemMenusu();

int main() {
	islemMenusu();

	// Islem turunun belirlenmesi 
	int islem;
	cin >> islem;
	// Islem turu belirlenmesi sonu

	// Verilerin alinmasi
	int gercekKisim;
	cout << "Gercek kisim:" << endl;
	cin >> gercekKisim;

	int sanalKisim;
	cout << "Sanal kisim: " << endl;
	cin >> sanalKisim;

	Karmasik k1(gercekKisim, sanalKisim), k2;

	cout << "Gercek kisim:" << endl;
	cin >> gercekKisim;
	k2.setGercekKisim(gercekKisim);

	cout << "Sanal kisim: " << endl;
	cin >> sanalKisim;
	k2.setSanalKisim(sanalKisim);
	// Verilerin alinmasi sonu

	// Islem turune gore islem yapilmasi
	cout << "Islem sonucu: ";
	switch (islem) {
	case 1:
		(k1 + k2).goster();
		break;
	case 2:
		(k1 - k2).goster();
		break;
	case 3:
		(k1 * k2).goster();
		break;
	case 4:
		(k1 / k2).goster();
		break;
	case 5:
		exit(1);
	}
	
	system("pause");
}

void islemMenusu() {
	cout << "Menu" << endl;
	cout << "1.Toplama" << endl;
	cout << "2.Cikarma" << endl;
	cout << "3.Carpma" << endl;
	cout << "4.Bolme" << endl;
	cout << "5.Cikis" << endl;

	cout << "Islem seciniz: ";
}
