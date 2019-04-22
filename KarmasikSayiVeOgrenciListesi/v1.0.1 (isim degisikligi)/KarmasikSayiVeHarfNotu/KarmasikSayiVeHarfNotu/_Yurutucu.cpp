#include "_Karmasik.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Menu\n1.Toplama\n2.Cikarma\n3.Carpma\n4.Bolme\n5.Cikis " << endl;
	cout << "Islem seciniz: ";

	int cevap;
	cin >> cevap;
	
	Karmasik sayi1, sayi2;
	int sayac;
	for (sayac = 0; sayac < 2; sayac++) {
		// Gercek kismin verisinin alinmasi
		int r;
		cout << "Gercek Kisim:\n";
		cin >> r;
		
		// Sanal kismin verisinin alinmasi
		int i;
		cout << "Sanal Kisim:\n";
		cin >> i;
		
		if (sayac == 0) {
			// Set ile degerlerin atanmasi
			sayi1.setGercekKisim(r);
			sayi1.setSanalKisim(i);
		} else {
			// Constructer ile veri atanmasi
			sayi2 = Karmasik(r,i);
		}
	}
	
	cout << "Islem sonucu: ";
	if (cevap == 1) {
		(sayi1 + sayi2).goster();
	} else if (cevap == 2) {
		(sayi1 - sayi2).goster();
	} else if (cevap == 3) {
		(sayi1 * sayi2).goster();
	} else if (cevap == 4) {
		(sayi1 / sayi2).goster();
	} else {
		// Güvenli cikis
		exit(1);
	}

	system("pause");
}
