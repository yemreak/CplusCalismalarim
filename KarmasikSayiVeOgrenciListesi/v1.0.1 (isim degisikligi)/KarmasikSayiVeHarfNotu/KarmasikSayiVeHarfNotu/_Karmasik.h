#ifndef karmasik
#define karmasik

class Karmasik {
	// bölme
	friend Karmasik operator/(Karmasik k1, Karmasik k2);
	// cikarma
	friend Karmasik operator-(Karmasik k1, Karmasik k2);
	// toplama
	friend Karmasik operator+(Karmasik k1, Karmasik k2);
	// carpma
	friend Karmasik operator*(Karmasik k1, Karmasik k2);
public:
	// Constructer
	Karmasik();
	Karmasik(float x, float y);
	// istenen fonksiyonlar
	void goster();
	float getSanalKisim();
	void setSanalKisim(float y);
	float getGercekKisim();
	void setGercekKisim(float x);
private:
	float sanalKisim;
	float gercekKisim;
};

#endif

