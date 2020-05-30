#pragma once
#include<fstream>
using namespace std;

class PGM_pixel {
private:
	int value;

public:


	friend istream& operator>>(istream& in, PGM_pixel& pixel);
	friend ostream& operator<<(ostream& out, const PGM_pixel& pixel);
};
