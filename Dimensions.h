#pragma once
#include<fstream>
using namespace std;
struct Dimensions {
	unsigned x;
	unsigned y;
	Dimensions(unsigned x = 0, unsigned y = 0);
	Dimensions(const Dimensions&);
	Dimensions& operator=(const Dimensions&);
	void swap();
	void swap_with(Dimensions&);
	void read_from_binary(istream&);
	friend istream& operator>>(istream& in, Dimensions& dimensions);
	friend ostream& operator<<(ostream& out, const Dimensions& dimensions);
};
