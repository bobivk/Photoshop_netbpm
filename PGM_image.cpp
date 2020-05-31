#include "PGM_image.h"

PGM_image::PGM_image(string in_filename) :filename{ in_filename } {
	ifstream in(filename, ios::beg);
	in >> dimensions;
	in >> pixel_max_value;
	PGM_pixel current_pixel;
	string line;
	//there may be fill bits at the end, so we need to read only dimensions.y integers on each row
	for (unsigned i = 0; i < dimensions.x; ++i) {
		getline(in, line);
		while (line[0] == '#') getline(in, line); //comments start with '#'
		stringstream ss(line);
		for (unsigned j = 0; j < dimensions.y; ++j) {
			ss >> current_pixel;
			pixel_matrix[i].push_back(current_pixel);
		}
	}
}
void PGM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P5\n";
	out << dimensions;
	for (unsigned i = 0; i < dimensions.x; ++i) {
		for (unsigned j = 0; j < dimensions.y; ++j) {
			unsigned index = dimensions.x * i + j;
			out << pixel_matrix[i][j];
		}
		out << '\n';
	}
}
string PGM_image::get_file_name() const {
	return filename;
}
void PGM_image::set_dimensions(Dimensions& dim) {
	dimensions = dim;
}
Dimensions PGM_image::get_dimensions() const {
	return dimensions;
}
vector<vector<PGM_pixel>> PGM_image::get_pixel_matrix() const {
	return pixel_matrix;
}
void PGM_image::set_pixel_matrix(vector<vector<PGM_pixel>> in) {
	pixel_matrix = in;
}