#include "PPM_pixel.h"

PPM_pixel& PPM_pixel::operator=(const PPM_pixel& other){
	red = other.red;
	green = other.green;
	blue = other.blue;
	return *this;
}

istream& operator>>(istream& in, PPM_pixel& pixel) {
	while (in.peek() == '#') in.ignore(2048, '\n');
	return in >> pixel.red >> pixel.green >> pixel.blue;
}
ostream& operator<<(ostream& out, const PPM_pixel& pixel) {
	return out << pixel.red << " " << pixel.blue << pixel.green << "  ";
}