#ifndef _KARMASIK.H
#define _KARMASIK.H

#include <string>
using namespace std;

class Karmasik {
	friend Karmasik operator+(Karmasik k1, Karmasik k2);
	friend Karmasik operator-(Karmasik k1, Karmasik k2);
	friend Karmasik operator*(Karmasik k1, Karmasik k2);
	friend Karmasik operator/(Karmasik k1, Karmasik k2);

private:
	float gercekKisim;
	float sanalKisim;

public:
	Karmasik();
	Karmasik(float x, float y);

	float getGercekKisim();
	float getSanalKisim();

	void setGercekKisim(float x);
	void setSanalKisim(float y);

	void goster();

	
};

#endif

