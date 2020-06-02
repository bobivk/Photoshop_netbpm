#include "Collage.h"
void Collage::make_collage(orientation_t orientation, Image* first, Image* second, string outfilename) {
	ofstream out(outfilename, ios::beg | ios::trunc);
	out << first->get_magic_number() << '\n';
//PBM
	if (dynamic_cast<PBM_image*>(first) && dynamic_cast<PBM_image*>(second)) {
		PBM_image* pbmimage1 = dynamic_cast<PBM_image*>(first);
		PBM_image* pbmimage2 = dynamic_cast<PBM_image*>(second);
		vector<vector<PBM_pixel>> first_pixels = pbmimage1->get_pixel_matrix();
		vector<vector<PBM_pixel>> second_pixels = pbmimage2->get_pixel_matrix();
		if (orientation == orientation_t::horizontal) {
			Dimensions new_dimensions(first->get_dimensions().x + second->get_dimensions().x,
									max(first->get_dimensions().y, second->get_dimensions().y));
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < new_dimensions.y; ++row) {
				vector<PBM_pixel> row_of_first = first_pixels[row];
				vector<PBM_pixel> row_of_second = second_pixels[row];
				for (unsigned col = 0; col < pbmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				for (unsigned col = 0; col < pbmimage2->get_dimensions().x; ++col) {
					out << row_of_second[col];
				}
				out << '\n';
			}
		}
		if (orientation == orientation_t::vertical) {
			Dimensions new_dimensions(max(first->get_dimensions().x, second->get_dimensions().x),
				first->get_dimensions().y + second->get_dimensions().y);
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < pbmimage1->get_dimensions().y; ++row) {
				vector<PBM_pixel> row_of_first = first_pixels[row];
				for (unsigned col = 0; col < pbmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
			for (unsigned row = 0; row < pbmimage2->get_dimensions().y; ++row) {
				vector<PBM_pixel> row_of_first = second_pixels[row];
				for (unsigned col = 0; col < pbmimage2->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
		}
	}
//PGM
	if (dynamic_cast<PGM_image*>(first) && dynamic_cast<PGM_image*>(second)) {
		PGM_image* pgmimage1 = dynamic_cast<PGM_image*>(first);
		PGM_image* pgmimage2 = dynamic_cast<PGM_image*>(second);
		vector<vector<PGM_pixel>> first_pixels = pgmimage1->get_pixel_matrix();
		vector<vector<PGM_pixel>> second_pixels = pgmimage2->get_pixel_matrix();
		if (orientation == orientation_t::horizontal) {
			Dimensions new_dimensions(first->get_dimensions().x + second->get_dimensions().x,
				max(first->get_dimensions().y, second->get_dimensions().y));
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < new_dimensions.y; ++row) {
				vector<PGM_pixel> row_of_first = first_pixels[row];
				vector<PGM_pixel> row_of_second = second_pixels[row];
				for (unsigned col = 0; col < pgmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				for (unsigned col = 0; col < pgmimage2->get_dimensions().x; ++col) {
					out << row_of_second[col];
				}
				out << '\n';
			}
		}
		if (orientation == orientation_t::vertical) {
			Dimensions new_dimensions(max(first->get_dimensions().x, second->get_dimensions().x),
				first->get_dimensions().y + second->get_dimensions().y);
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < pgmimage1->get_dimensions().y; ++row) {
				vector<PGM_pixel> row_of_first = first_pixels[row];
				for (unsigned col = 0; col < pgmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
			for (unsigned row = 0; row < pgmimage2->get_dimensions().y; ++row) {
				vector<PGM_pixel> row_of_first = second_pixels[row];
				for (unsigned col = 0; col < pgmimage2->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
		}
	}
//PPM
	if (dynamic_cast<PPM_image*>(first) && dynamic_cast<PPM_image*>(second)) {
		PPM_image* ppmimage1 = dynamic_cast<PPM_image*>(first);
		PPM_image* ppmimage2 = dynamic_cast<PPM_image*>(second);
		vector<vector<PPM_pixel>> first_pixels = ppmimage1->get_pixel_matrix();
		vector<vector<PPM_pixel>> second_pixels = ppmimage2->get_pixel_matrix();
		if (orientation == orientation_t::horizontal) {
			Dimensions new_dimensions(first->get_dimensions().x + second->get_dimensions().x,
				max(first->get_dimensions().y, second->get_dimensions().y));
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < new_dimensions.y; ++row) {
				vector<PPM_pixel> row_of_first = first_pixels[row];
				vector<PPM_pixel> row_of_second = second_pixels[row];
				for (unsigned col = 0; col < ppmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				for (unsigned col = 0; col < ppmimage2->get_dimensions().x; ++col) {
					out << row_of_second[col];
				}
				out << '\n';
			}
		}
		if (orientation == orientation_t::vertical) {
			Dimensions new_dimensions(max(first->get_dimensions().x, second->get_dimensions().x),
				first->get_dimensions().y + second->get_dimensions().y);
			out << new_dimensions << '\n';
			for (unsigned row = 0; row < ppmimage1->get_dimensions().y; ++row) {
				vector<PPM_pixel> row_of_first = first_pixels[row];
				for (unsigned col = 0; col < ppmimage1->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
			for (unsigned row = 0; row < ppmimage2->get_dimensions().y; ++row) {
				vector<PPM_pixel> row_of_first = second_pixels[row];
				for (unsigned col = 0; col < ppmimage2->get_dimensions().x; ++col) {
					out << row_of_first[col];
				}
				out << '\n';
			}
		}
	}
}