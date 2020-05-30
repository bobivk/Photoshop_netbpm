#include "PGM_pixel.h"

istream& operator>>(istream& in, PGM_pixel& pixel) {
	in >> pixel.value;
	return in;
}
ostream& operator<<(ostream& out, const PGM_pixel& pixel) {
	return out << pixel.value << " ";
}