#include "PBM_image.h"
PBM_image::PBM_image(const PBM_image& other) :
	filename{ other.filename },
	dimensions{ other.dimensions },
	pixel_matrix{ other.pixel_matrix }{
}
PBM_image& PBM_image::operator=(const PBM_image& other) {
	PBM_image temp{ other };
	swap_with(temp);
	return *this;
}
void PBM_image::swap_with(PBM_image& other) {
	std::swap(filename, other.filename);
	dimensions.swap_with(other.dimensions);
	for (size_t row = 0; row < dimensions.x; ++row) {
		for (unsigned col = 0; col < dimensions.y; ++col) {
			pixel_matrix[row][col].swap_with(other.pixel_matrix[row][col]);
		}
	}
}

PBM_image::PBM_image(string in_filename, bool binary) :filename{ in_filename } {
	if (binary) {
		load_binary();
	}
	else load_txt();
}

void PBM_image::load_txt() {
	ifstream in(filename, ios::beg);
	string magic_number;
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> magic_number;
	while (in.peek() == '#') in.ignore(2048, '\n'); //comments not working
	in >> dimensions;
	cout <<"Dimensions: " << dimensions;
	vector<vector<PBM_pixel>> input_pixels(dimensions.x);
	PBM_pixel current_pixel;
	//there may be fill bits at the end, so we need to read only dimensions.y characters on each row
	for (unsigned row = 0; row < dimensions.x; ++row) {
		vector<PBM_pixel> row_pixels(dimensions.y);
		while (in.peek() == '#') in.ignore(2048, '\n');
		for (unsigned col = 0; col < dimensions.y; ++col) {
			try {
				in >> current_pixel;
				row_pixels.push_back(current_pixel);
			}
			catch (Bad_pixel_exception & e) {
				cout << "Bad PBM_pixel exception caught: " << e.get_bad_pixel() << endl;
			}
		}
		input_pixels.push_back(row_pixels);
	}
}
void PBM_image::load_binary() {
	ifstream in(filename, ios::binary|ios::beg);
	for (unsigned row = 0; row < dimensions.x; ++row) {
		for (unsigned col = 0; col < dimensions.y; ++col) {
			pixel_matrix[row][col].read_from_binary(in);
		}
	}
}
void PBM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	out << "P4\n";
	out << dimensions;
	for (unsigned i = 0; i < dimensions.x; ++i) {
		for (unsigned j = 0; j < dimensions.y; ++j) {
			out << pixel_matrix[i][j] ;
		}
		out << '\n';
	}
}
string PBM_image::get_file_name() const {
	return filename;
}
string PBM_image::get_magic_number() const {
	return "P4";
}
int PBM_image::get_max_pixel_value() const {
	return 1;
}
Dimensions PBM_image::get_dimensions()const {
	return dimensions;
}
void PBM_image::set_dimensions(Dimensions& dim) {
	dimensions = dim;
}

vector<vector<PBM_pixel>> PBM_image::get_pixel_matrix() const {
	return pixel_matrix;
}
void PBM_image::set_pixel_matrix(vector<vector<PBM_pixel>> in) {
	pixel_matrix = in;
}