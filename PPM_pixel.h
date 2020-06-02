#pragma once
#include<fstream>
using namespace std;

class PPM_pixel {

private:
	int red = 0;
	int green = 0;
	int blue = 0;

public:
	PPM_pixel();
	PPM_pixel(const PPM_pixel&);
	PPM_pixel& operator=(const PPM_pixel&);
	void read_from_binary(istream& in);
	friend istream& operator>>(istream& in, PPM_pixel& pixel);
	friend ostream& operator<<(ostream& out, const PPM_pixel& pixel);
	friend class Monochrome;
	friend class Negative;
	friend class Grayscale;
};
