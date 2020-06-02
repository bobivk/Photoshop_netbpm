#include "PPM_pixel.h"
PPM_pixel::PPM_pixel() :
	red{ 0 },
	blue{ 0 },
	green{ 0 }{}

PPM_pixel::PPM_pixel(const PPM_pixel& other) : 
	red{ other.red },
	blue{ other.blue },
	green{ other.green }{}

PPM_pixel& PPM_pixel::operator=(const PPM_pixel& other){
	red = other.red;
	green = other.green;
	blue = other.blue;
	return *this;
}
void PPM_pixel::read_from_binary(istream& in) {
	in.read((char*)&red, sizeof(int));
	in.read((char*)&green, sizeof(int));
	in.read((char*)&blue, sizeof(int));
}

istream& operator>>(istream& in, PPM_pixel& pixel) {
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> pixel.red >> pixel.green >> pixel.blue;
	return in;
}
ostream& operator<<(ostream& out, const PPM_pixel& pixel) {
	return out << pixel.red << " " << pixel.blue << " " << pixel.green << "  ";
}