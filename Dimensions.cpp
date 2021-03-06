#include "Dimensions.h"
#include<iostream>
Dimensions::Dimensions(unsigned in_x, unsigned in_y) :x{ in_x }, y{ in_y } {}

Dimensions::Dimensions(const Dimensions& other): x { other.x }, y{ other.y } {}

Dimensions& Dimensions::operator=(const Dimensions& other) {
	x = other.x;
	y = other.y;
	return *this;
}
void Dimensions::swap_with(Dimensions& other) {
	std::swap(x, other.x);
	std::swap(y, other.y);
}
void Dimensions::read_from_binary(istream& in) {
	in.read((char*)&x, sizeof(unsigned));
	in.read((char*)&y, sizeof(unsigned));
}
void Dimensions::write_to_binary(ostream& out) const{
	out.write((char*)&x, sizeof(unsigned));
	out.write((char*)&y, sizeof(unsigned));
}

istream& operator>>(istream& in, Dimensions& dimensions) {
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> dimensions.x >> dimensions.y;
	return in;
}
ostream& operator<<(ostream& out, const Dimensions& dimensions){
	out << dimensions.x << " " << dimensions.y;
	return out;
}
void Dimensions::swap() {
	std::swap(x, y);
}