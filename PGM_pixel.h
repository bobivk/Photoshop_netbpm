#pragma once
#include<fstream>
using namespace std;

class PGM_pixel {
private:
	int value;	//grayscale value

public:
	PGM_pixel& operator=(const PGM_pixel& other);

	friend istream& operator>>(istream& in, PGM_pixel& pixel);
	friend ostream& operator<<(ostream& out, const PGM_pixel& pixel);
};
