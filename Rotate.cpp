#include "Rotate.h"
Rotate::Rotate(direction_t in_direction) : direction{ in_direction } {}

string Rotate::get_name() const {
	string rotate = "rotate ";
	return rotate += directions[(int)direction];
}
void Rotate::execute(vector<Image*>& images) {
	for (size_t i = 0; i < images.size(); ++i) {
		if (dynamic_cast<PBM_image*>(images[i]))
		{
			PBM_image* pbmimage = dynamic_cast<PBM_image*>(images[i]);
			vector<vector<PBM_pixel>> transposed;
			vector<vector<PBM_pixel>> original_pixels = pbmimage->get_pixel_matrix();
			Dimensions starting = pbmimage->get_dimensions();
			if (direction == direction_t::right) {
				for (unsigned col = 0; col < starting.x; ++col) {
					vector<PBM_pixel> new_row;
					for (unsigned row = starting.y - 1; row != 0; --row) {
						new_row.push_back(original_pixels[row][col]);
					}
					new_row.push_back(original_pixels[0][col]);
					transposed.push_back(new_row);
				}
				starting.swap();
				pbmimage->set_pixel_matrix(transposed);
				pbmimage->print();
			}
		}
	}
}