#include "Dimensions.h"
Dimensions::Dimensions(const Dimensions& other): x { other.x }, y{ other.y } {}

Dimensions& Dimensions::operator=(const Dimensions& other) {
	x = other.x;
	y = other.y;
	return *this;
}

istream& operator>>(istream& in, Dimensions& dimensions) {
	return in >> dimensions.x >> dimensions.y;
}
ostream& operator<<(ostream& out, const Dimensions& dimensions){
	return out << dimensions.x << " " << dimensions.y << '\n';
}
void Dimensions::swap() {
	std::swap(x, y);
}