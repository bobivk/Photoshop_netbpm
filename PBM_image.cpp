#include "PBM_image.h"
PBM_image::PBM_image(const PBM_image& other) :
	filename{ other.filename },
	dimensions{ other.dimensions },
	pixel_matrix{ other.pixel_matrix },
	is_binary{ other.is_binary }{}
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

PBM_image::PBM_image(string in_filename, bool binary) :
	filename{ in_filename },
	is_binary{ binary } {
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
	while (in.peek() == '#') in.ignore(2048, '\n');
	in >> dimensions;
	vector<vector<PBM_pixel>> input_pixels;
	PBM_pixel current_pixel;
	cout << "\n";
	//there may be fill bits at the end, so we need to read only dimensions.y characters on each row
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PBM_pixel> row_pixels;
		while (in.peek() == '#') in.ignore(2048, '\n');
		for (unsigned col = 0; col < dimensions.x; ++col) {
			try {
				in >> current_pixel;
				row_pixels.push_back(current_pixel);
				cout << current_pixel;
			}
			catch (Bad_pixel_exception & e) {
				cout << "Bad PBM_pixel exception caught: " << e.get_bad_pixel() << endl;
			}
		}
		input_pixels.push_back(row_pixels);
		cout << "\n";
	}
	set_pixel_matrix(input_pixels); 
	cout << endl << endl;
	print();
}
void PBM_image::load_binary() {
	ifstream in(filename, ios::binary|ios::beg);
	in.seekg(2 * sizeof(char)); //skip magic number
	dimensions.read_from_binary(in);
	vector<vector<PBM_pixel>> input_pixels;
	PBM_pixel current_pixel;
	for (unsigned row = 0; row < dimensions.x; ++row) {
		vector<PBM_pixel> row_pixels;
		for (unsigned col = 0; col < dimensions.y; ++col) {
			current_pixel.read_from_binary(in);
			row_pixels.push_back(current_pixel);
		}
		input_pixels.push_back(row_pixels);
	}
	set_pixel_matrix(input_pixels);
	print();
}
void PBM_image::print() const {
	cout << filename << endl;
	cout << dimensions << endl;
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PBM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			cout << row_pixels[col];
		}
		cout << '\n';
	}
	cout << '\n';
}
void PBM_image::save() const {
	ofstream out(filename, ios::beg|ios::trunc);
	if (is_binary) out << "P1\n";
	else out << "P1\n";
	out << dimensions << '\n';
	for (unsigned row = 0; row < dimensions.y; ++row) {
		vector<PBM_pixel> row_pixels = pixel_matrix[row];
		for (unsigned col = 0; col < dimensions.x; ++col) {
			out << row_pixels[col] ;
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