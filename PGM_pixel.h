#pragma once
#include<fstream>
using namespace std;

class PGM_pixel {
private:
	int value;	//grayscale value

public:
	PGM_pixel();
	PGM_pixel(const PGM_pixel&);
	PGM_pixel& operator=(const PGM_pixel&);
	void read_from_binary(istream& in);

	friend istream& operator>>(istream& in, PGM_pixel& pixel);
	friend ostream& operator<<(ostream& out, const PGM_pixel& pixel);
	friend class Monochrome;
	friend class Negative;
};
