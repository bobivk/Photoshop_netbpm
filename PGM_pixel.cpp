#include "PGM_pixel.h"

PGM_pixel& PGM_pixel::operator=(const PGM_pixel& other){
	value = other.value;
	return *this;
}

istream& operator>>(istream& in, PGM_pixel& pixel) {
	return in >> pixel.value;
	
}
ostream& operator<<(ostream& out, const PGM_pixel& pixel) {
	return out << pixel.value << " ";
}