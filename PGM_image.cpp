#include "PGM_image.h"
#include<iostream>

PGM_image::PGM_image(string in_filename) :filename{ in_filename } {
	ifstream in(filename, ios::beg);
	string magic_number;
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> magic_number;
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
	cout << dimensions.y << " rows " << dimensions.x << " cols" << endl;
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PGM_pixel> row_pixels = input_pixels[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			cout << row_pixels[col];
		}
		cout << '\n';
	}
}
PGM_image::PGM_image(const PGM_image& other) :
	pixel_matrix{ other.pixel_matrix },
	filename{ other.filename },
	max_pixel_value{ other.max_pixel_value },
	dimensions{ other.dimensions }{}
PGM_image& PGM_image::operator=(const PGM_image& other) {
	if(this != &other){
		dimensions = other.dimensions;
		filename = other.filename;
		max_pixel_value = other.max_pixel_value;
		pixel_matrix = other.pixel_matrix;
	}
	return *this;
}

void PGM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P5\n";
	out << dimensions << '\n';
	out << max_pixel_value << '\n';
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PGM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			out << row_pixels[col];
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