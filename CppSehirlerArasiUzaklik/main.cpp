#include <iostream>
#include <string>

#include "sehir.h"



int main(int argc, char *argv[]) {
	if (argc >= 2){
		Sehir sehir(argv[1], argv[2]);
		sehir.yakinIller();
		sehir.mesafeBul();
		sehir.uzakIller();
	}
}
