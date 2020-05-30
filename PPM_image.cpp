#include "PPM_image.h"

PPM_image::PPM_image(istream& in) {
	in >> dimensions;
	PPM_pixel current_pixel;
	string line;
	//there may be fill bits at the end, so we need to read
	//only dimensions.y pixels on each row
	for (unsigned i = 0; i < dimensions.x; ++i) {
		getline(in, line);
		stringstream ss(line);
		for (unsigned j = 0; j < dimensions.y; ++j) {
			ss >> current_pixel;
			pixels.push_back(current_pixel);
		}
	}
}
void PPM_image::save(string filename) const {
	ofstream out(filename, ios::beg);
	out << "P6\n";
	out << dimensions;
	for (unsigned i = 0; i < dimensions.x; ++i) {
		for (unsigned j = 0; j < dimensions.y; ++j) {
			unsigned index = dimensions.x * i + j;
			out << pixels[index];
		}
		out << '\n';
	}
}