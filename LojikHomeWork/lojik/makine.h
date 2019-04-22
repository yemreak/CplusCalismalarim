#pragma once
#include <stdlib.h>

class Makine {
	public:
		bool* dizi;
		bool z;

		int boyut = 0;

		// Arayüz
		void baþlat();

		// Veri alma fonksiyonlarý
		void bitAl();

		// Dizi iþlemleri fonksiyonlarý
		void diziyiOluþtur();
		void diziyiGeniþlet();
		void diziyeEkle(bool x);

		// Kontrol fonksiyonlarý
		void zyiGöster();
		void diziyiGöster();
		void sonlandýr();
};
		