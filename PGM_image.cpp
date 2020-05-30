#include "PGM_image.h"

PGM_image::PGM_image(istream& in) {
	in >> dimensions;
	PGM_pixel current_pixel;
	string line;
	//there may be fill bits at the end, so we need to read only dimensions.y integers on each row
	for (unsigned i = 0; i < dimensions.x; ++i) {
		getline(in, line);
		stringstream ss(line);
		while (line[0] == '#') getline(in, line); //comments start with '#'
		for (unsigned j = 0; j < dimensions.y; ++j) {
			ss >> current_pixel;
			pixels.push_back(current_pixel);
		}
	}
}
void PGM_image::save(string filename) const {
	ofstream out(filename, ios::beg);
	out << "P5\n";
	out << dimensions;
	for (unsigned i = 0; i < dimensions.x; ++i) {
		for (unsigned j = 0; j < dimensions.y; ++j) {
			unsigned index = dimensions.x * i + j;
			out << pixels[index];
		}
		out << '\n';
	}
}