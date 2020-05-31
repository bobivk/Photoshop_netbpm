#pragma once
#include<fstream>
using namespace std;
struct Dimensions {
	unsigned x;
	unsigned y;
	Dimensions(unsigned in_x = 0, unsigned in_y = 0) :x{ in_x }, y{ in_y } {}
	Dimensions(const Dimensions&);
	Dimensions& operator=(const Dimensions&);
	void swap();
	friend istream& operator>>(istream& in, Dimensions& dimensions);
	friend ostream& operator<<(ostream& out, const Dimensions& dimensions);
};
