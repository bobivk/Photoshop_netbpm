#include "PPM_pixel.h"
istream& operator>>(istream& in, PPM_pixel& pixel) {
	return in >> pixel.red >> pixel.green >> pixel.blue;
}
ostream& operator<<(ostream& out, const PPM_pixel& pixel) {
	return out << pixel.red << " " << pixel.blue << pixel.green << "  ";
}