#include "PPM_image.h"
#include<iostream>

PPM_image::PPM_image(string in_filename, bool binary) :filename{ in_filename }, is_binary{ binary } {
		if (is_binary) {
			load_binary();
		}
		else load_txt();
}

void PPM_image::load_txt() {
	ifstream in(filename);
	string magic_number;
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> magic_number;
	while (in.peek() == '#') in.ignore(2048, '\n');
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
	print();
}

void PPM_image::load_binary() {
	ifstream in(filename, ios::binary);
	in.seekg(2 * sizeof(char)); //skip magic number
	dimensions.read_from_binary(in);
	in.read((char*)&max_pixel_value, sizeof(int));
	vector<vector<PPM_pixel>> input_pixels;
	PPM_pixel current_pixel;
	for (unsigned row = 0; row < dimensions.x; ++row) {
		vector<PPM_pixel> row_pixels;
		for (unsigned col = 0; col < dimensions.y; ++col) {
			current_pixel.read_from_binary(in);
			row_pixels.push_back(current_pixel);
		}
		input_pixels.push_back(row_pixels);
	}
	set_pixel_matrix(input_pixels);
	print();
}

PPM_image::PPM_image(const PPM_image& other) :
	pixel_matrix{ other.pixel_matrix },
	filename{ other.filename },
	max_pixel_value{ other.max_pixel_value },
	dimensions{ other.dimensions },
	is_binary{other.is_binary}
{}
PPM_image& PPM_image::operator=(const PPM_image& other) {
	if (this != &other) {
		dimensions = other.dimensions;
		filename = other.filename;
		max_pixel_value = other.max_pixel_value;
		pixel_matrix = other.pixel_matrix;
		is_binary = other.is_binary;
	}
	return *this;
}

void PPM_image::save() const {
	if (is_binary) save_binary();
	else save_txt();
}
void PPM_image::save_txt() const {
	ofstream out(filename, ios::trunc);
	out << "P3\n";
	out << dimensions << '\n';
	out << max_pixel_value << '\n';
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PPM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			out << row_pixels[col];
		}
		out << '\n';
	}
}
void PPM_image::save_binary() const {
	ofstream out(filename, ios::binary | ios::trunc);
	out.write("P6", 2);
	dimensions.write_to_binary(out);
	out.write((char*)&max_pixel_value, sizeof(int));
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PPM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			row_pixels[col].write_to_binary(out);
		}
		out << '\n';
	}
}
void PPM_image::print()const {
	cout << filename << endl;
	cout << dimensions << endl;
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PPM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			cout << row_pixels[col];
		}
		cout << '\n';
	}
	cout << '\n';
}
string PPM_image::get_file_name() const {
	return filename;
}
string PPM_image::get_magic_number() const {
	if (is_binary) return "P6";
	return "P3";
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
void PPM_image::set_pixel_matrix(vector<vector<PPM_pixel>>& in) {
	pixel_matrix = in;
}