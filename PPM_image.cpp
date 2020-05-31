#include "PPM_image.h"

PPM_image::PPM_image(string in_filename) :filename{ in_filename } {
	ifstream in(filename, ios::beg);
	in >> dimensions;
	in >> max_pixel_value;
	PPM_pixel current_pixel;
	string line;
	//there may be fill bits at the end, so we need to read
	//only dimensions.y pixels on each row
	for (unsigned i = 0; i < dimensions.x; ++i) {
		getline(in, line);
		while (line[0] == '#') getline(in, line); //comments
		stringstream ss(line);
		for (unsigned j = 0; j < dimensions.y; ++j) {
			ss >> current_pixel;
			pixel_matrix[i].push_back(current_pixel);
		}
	}
}
void PPM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P6\n";
	out << dimensions;
	for (unsigned i = 0; i < dimensions.x; ++i) {
		for (unsigned j = 0; j < dimensions.y; ++j) {
			out << pixel_matrix[i][j];
		}
		out << '\n';
	}
}
string PPM_image::get_file_name() const {
	return filename;
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