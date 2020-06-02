#include "PBM_pixel.h"
using namespace std;


PBM_pixel::PBM_pixel(const PBM_pixel& other) : value{ other.value } {}

void PBM_pixel::read_from_binary(istream& in) {
	in.read((char*)&value, sizeof(bool));
}

PBM_pixel& PBM_pixel::operator=(const PBM_pixel& other) {
	if (this != &other) {
		value = other.value;
	}
	return *this;
}
void PBM_pixel::swap_with(PBM_pixel& other) {
	std::swap(value, other.value);
}

istream& operator>>(istream& in, PBM_pixel& pixel) {
	char input_char;
	int badcharcounter = 0;
	in.get(input_char);
	while (in.peek() == '#') in.ignore(2048, '\n');
	while(input_char == ' ') in.get(input_char);
	if (input_char == '\n') in.get(input_char);
	if (input_char == '0' || input_char == '1') {
		pixel.value = input_char - '0';
	}
	else
	{

		string message;
		message += input_char;
		throw Bad_pixel_exception(message);
	}

	return in;
}

ostream& operator<<(ostream& out, const PBM_pixel& pixel) {
	out << pixel.value << " ";
	return out;
}