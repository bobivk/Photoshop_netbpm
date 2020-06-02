#include "Collage.h"
void Collage::make_collage(orientation_t orientation, Image* first, Image* second, string outfilename) {
	ofstream out(outfilename, ios::beg | ios::trunc);
	out << first->get_magic_number() << '\n';
	Dimensions new_dimensions(max(first->get_dimensions().x, second->get_dimensions().x),
								first->get_dimensions().y + second->get_dimensions().y);
	if (dynamic_cast<PBM_image*>(first) && dynamic_cast<PBM_image*>(second)) {
		PBM_image* pbmimage1 = dynamic_cast<PBM_image*>(first);
		PBM_image* pbmimage2 = dynamic_cast<PBM_image*>(second);
		if (orientation == orientation_t::horizontal) {
			out << new_dimensions;
			for (unsigned row = 0; row < new_dimensions.x; ++row) {
				for (unsigned col = 0; col < pbmimage1->dimensions.y; ++col) {
					out << pbmimage1->pixel_matrix[row][col];
				}
				for (unsigned col = 0; col < pbmimage2->dimensions.y; ++col) {
					out << pbmimage2->pixel_matrix[row][col];
				}
			}
		}
		if (orientation == orientation_t::vertical) {
			Dimensions new_dimensions(first->get_dimensions().x + second->get_dimensions().x,
				max(first->get_dimensions().y, second->get_dimensions().y));
			out << new_dimensions;
			for (unsigned row = 0; row < new_dimensions.x; ++row) {
				for (unsigned col = 0; col < pbmimage1->dimensions.y; ++col) {
					out << pbmimage1->pixel_matrix[row][col];
				}
			}
		}
	}
}