#pragma once
#include"Exceptions.h"
#include<fstream>
using namespace std;

class PBM_pixel {
private:
	bool value{ false };

public:

	PBM_pixel() = default;
	PBM_pixel(const PBM_pixel& other);
	PBM_pixel& operator=(const PBM_pixel& other);
	void swap_with(PBM_pixel&);
	void read_from_binary(istream& in);
	void write_to_binary(ostream& out);
	friend istream& operator>>(istream& in, PBM_pixel& pixel);
	friend ostream& operator<<(ostream& out, const PBM_pixel& pixel);
	friend class Negative;
};
