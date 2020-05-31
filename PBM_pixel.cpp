#include "PBM_pixel.h"
using namespace std;


PBM_pixel::PBM_pixel(const PBM_pixel& other) : value{ other.value } {}

PBM_pixel& PBM_pixel::operator=(const PBM_pixel& other) {
	if (this != &other) {
		value = other.value;
	}
	return *this;
}

istream& operator>>(istream& in, PBM_pixel& pixel) {
	char input_char;
	try {
		in.get(input_char);
		if (input_char == '0' || input_char == '1') {
			pixel.value = input_char - '0';
		}
		else
		{
			string message;
			message += input_char;
			throw Bad_pixel_exception(message);
		}
	}
	catch (Bad_pixel_exception& e) {
		cout << "Bad PBM_pixel exception caught: " << e.get_bad_pixel() << endl;
	}
	return in;
}

ostream& operator<<(ostream& out, const PBM_pixel& pixel) {
	return out << pixel.value << " ";
}