#include "PGM_image.h"
#include<iostream>

PGM_image::PGM_image(string in_filename, bool binary) :
	filename{ in_filename },
	is_binary{ binary }{
	if (is_binary) {
		load_binary();
	}
	else load_txt();
}

void PGM_image::load_txt() {
	ifstream in(filename);
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
	print();
}

void PGM_image::load_binary() {
	ifstream in(filename, ios::binary);
	in.seekg(2 * sizeof(char)); //skip magic number
	dimensions.read_from_binary(in);
	in.read((char*)&max_pixel_value, sizeof(int));
	vector<vector<PGM_pixel>> input_pixels;
	PGM_pixel current_pixel;
	for (unsigned row = 0; row < dimensions.x; ++row) {
		vector<PGM_pixel> row_pixels;
		for (unsigned col = 0; col < dimensions.y; ++col) {
			current_pixel.read_from_binary(in);
			row_pixels.push_back(current_pixel);
		}
		input_pixels.push_back(row_pixels);
	}
	set_pixel_matrix(input_pixels);
	print();
}

PGM_image::PGM_image(const PGM_image& other) :
	pixel_matrix{ other.pixel_matrix },
	filename{ other.filename },
	max_pixel_value{ other.max_pixel_value },
	dimensions{ other.dimensions },
	is_binary{ other.is_binary }{}

PGM_image& PGM_image::operator=(const PGM_image& other) {
	if(this != &other){
		dimensions = other.dimensions;
		filename = other.filename;
		max_pixel_value = other.max_pixel_value;
		pixel_matrix = other.pixel_matrix;
		is_binary = other.is_binary;
	}
	return *this;
}

void PGM_image::save() const {
	if (is_binary) save_binary();
	else save_txt();
}
void PGM_image::save_txt() const {
	ofstream out(filename, ios::trunc);
	out << "P2\n";
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
void PGM_image::save_binary() const {
	ofstream out(filename, ios::binary | ios::trunc);
	out.write("P5", 2);
	dimensions.write_to_binary(out);
	out.write((char*)&max_pixel_value, sizeof(int));
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PGM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			row_pixels[col].write_to_binary(out);
		}
		out << '\n';
	}
}
void PGM_image::print() const {
	cout << filename << endl;
	cout << dimensions << endl;
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PGM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			cout << row_pixels[col];
		}
		cout << '\n';
	}
	cout << '\n';
}
string PGM_image::get_file_name() const {
	return filename;
}
string PGM_image::get_magic_number() const {
	if (is_binary) return "P5";
	return "P2";
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
void PGM_image::set_pixel_matrix(vector<vector<PGM_pixel>>& in) {
	pixel_matrix = in;
}