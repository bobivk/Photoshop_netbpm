#include "PGM_image.h"

PGM_image::PGM_image(string in_filename) :filename{ in_filename } {
	ifstream in(filename, ios::beg);
	in >> dimensions;
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> max_pixel_value;
	vector<vector<PGM_pixel>> input_pixels;
	PGM_pixel current_pixel;
	//there may be fill bits at the end, so we need to read only dimensions.y integers on each row
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PGM_pixel> row_pixels;
		while (in.peek() == '#') in.ignore(2048, '\n'); //comments start with '#'
		for (unsigned col = 0; col < dimensions.x; ++col) {
			in >> current_pixel;
			row_pixels.push_back(current_pixel);
		}
		input_pixels.push_back(row_pixels);
	}
	set_pixel_matrix(input_pixels);
}
void PGM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P5\n";
	out << dimensions << '\n';
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
string PGM_image::get_magic_number() const {
	return "P5";
}
int PGM_image::get_max_pixel_value() const {
	return max_pixel_value;
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