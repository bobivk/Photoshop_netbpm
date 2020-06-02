#include "PPM_image.h"

PPM_image::PPM_image(string in_filename) :filename{ in_filename } {
	ifstream in(filename, ios::beg);
	in >> dimensions;
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> max_pixel_value;
	vector<vector<PPM_pixel>> input_pixels;
	PPM_pixel current_pixel;
	//there may be fill bits at the end, so we need to read only dimensions.y integers on each row
	for (unsigned i = 0; i < dimensions.y; ++i) {
		vector<PPM_pixel> row_pixels;
		while (in.peek() == '#') in.ignore(2048, '\n'); //comments start with '#'
		for (unsigned j = 0; j < dimensions.x; ++j) {
			in >> current_pixel;
			row_pixels.push_back(current_pixel);
		}
		input_pixels.push_back(row_pixels);
	}
	set_pixel_matrix(input_pixels);
}
void PPM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P6\n";
	out << dimensions << '\n';
	for (unsigned row = 0; row < dimensions.y; ++row) {
		for (unsigned col = 0; col < dimensions.x; ++col) {
			out << pixel_matrix[row][col];
		}
		out << '\n';
	}
}
string PPM_image::get_file_name() const {
	return filename;
}
string PPM_image::get_magic_number() const {
	return "P6";
}
int PPM_image::get_max_pixel_value() const {
	return max_pixel_value;
}
void PPM_image::set_dimensions(Dimensions& dim) {
	dimensions = dim;
}
Dimensions PPM_image::get_dimensions() const{
	return dimensions;
}
vector<vector<PPM_pixel>> PPM_image::get_pixel_matrix() const {
	return pixel_matrix;
}
void PPM_image::set_pixel_matrix(vector<vector<PPM_pixel>> in) {
	pixel_matrix = in;
}