#include "Negative.h"
string Negative::get_name() const {
	return "negative";
}
void Negative::execute(vector<Image*>& images) {
	for (size_t i = 0; i < images.size(); ++i) {
		int max_pixel_value = images[i]->get_max_pixel_value();

		//quasi-same code repetition for all three, since we have no abstract pixel
		//maybe having the logic for negate, monochrome and grayscale in the pixels themselves would be a better structure?
	
		if (dynamic_cast<PBM_image*>(images[i])) {
			PBM_image* pbmimage = dynamic_cast<PBM_image*>(images[i]);
			for (size_t row = 0; row < pbmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < pbmimage->dimensions.y; ++col) {
					pbmimage->pixel_matrix[row][col].value = max_pixel_value - pbmimage->pixel_matrix[row][col].value;
				}
			}
		}
		else if (dynamic_cast<PGM_image*>(images[i])) { 
			PGM_image* pgmimage = dynamic_cast<PGM_image*>(images[i]);
			for (size_t row = 0; row < pgmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < pgmimage->dimensions.y; ++col) {
					pgmimage->pixel_matrix[row][col].value = max_pixel_value - pgmimage->pixel_matrix[row][col].value;
				}
			}
		}
		else if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			for (size_t row = 0; row < ppmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < ppmimage->dimensions.y; ++col) {
					ppmimage->pixel_matrix[row][col].red = max_pixel_value - ppmimage->pixel_matrix[row][col].red;
					ppmimage->pixel_matrix[row][col].blue = max_pixel_value - ppmimage->pixel_matrix[row][col].blue;
					ppmimage->pixel_matrix[row][col].green = max_pixel_value - ppmimage->pixel_matrix[row][col].green;
				}
			}
		}

	}
}