#include "PBM_image.h"


PBM_image::PBM_image(string filename) {
	ifstream in(filename, ios::beg);
	string magic_number;
	cin >> magic_number;
	in >> dimensions;
	PBM_pixel current_pixel;
	string line;
	//there may be fill bits at the end, so we need to read only dimensions.y characters on each row
	for(unsigned i = 0; i < dimensions.x; ++i) {
		getline(in, line);
		while (line[0] != '#') getline(in, line); //comments
		stringstream ss(line);
		for (unsigned j = 0; j < dimensions.y; ++j) {
			ss >> current_pixel;
			pixel_matrix[i].push_back(current_pixel);
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