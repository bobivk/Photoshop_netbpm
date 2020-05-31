#include "Rotate.h"
Rotate::Rotate(direction_t in_direction) : direction{ in_direction } {}

string Rotate::get_name() const {
	string rotate = "rotate ";
	return rotate += directions[(int)direction];
}
void Rotate::execute(vector<Image*>& images) { //no polymorphism here :(
	for (size_t i = 0; i < images.size(); ++i) {
		if (dynamic_cast<PBM_image*>(images[i]))
		{
			PBM_image* pbmimage = dynamic_cast<PBM_image*>(images[i]);
			vector<vector<PBM_pixel>> transposed;
			Dimensions starting = pbmimage->get_dimensions();
			if (direction == direction_t::right) {
				for (unsigned row = 0; row < starting.x; ++row) {
					for (unsigned col = 0; col < starting.y; ++col) {
						transposed[col].push_back(pbmimage->get_pixel_matrix()[row][col]);
					}
				}
				pbmimage->set_pixel_matrix(transposed);
				starting.swap();
				pbmimage->set_dimensions(starting);
			}
		}
		else if (dynamic_cast<PGM_image*>(images[i])) {
			PGM_image* pbmimage = dynamic_cast<PGM_image*>(images[i]);
			vector<vector<PGM_pixel>> transposed;
			Dimensions starting = pbmimage->get_dimensions();
			if (direction == direction_t::right) {
				for (unsigned row = 0; row < starting.x; ++row) {
					for (unsigned col = 0; col < starting.y; ++col) {
						transposed[col].push_back(pbmimage->get_pixel_matrix()[row][col]);
					}
				}
				pbmimage->set_pixel_matrix(transposed);
				starting.swap();
				pbmimage->set_dimensions(starting);
			}
		}
		else if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			vector<vector<PPM_pixel>> transposed;
			vector<vector<PPM_pixel>> new_pixel_matrix = ppmimage->get_pixel_matrix();
			Dimensions starting = ppmimage->get_dimensions();
			if (direction == direction_t::right) {
				for (unsigned row = 0; row < starting.x; ++row) {
					for (unsigned col = 0; col < starting.y; ++col) {
						transposed[col].push_back(new_pixel_matrix[row][col]);
					}
				}
				ppmimage->set_pixel_matrix(transposed);
				starting.swap();
				ppmimage->set_dimensions(starting);
			}

		}
	}
}