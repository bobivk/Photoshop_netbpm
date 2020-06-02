#include "Negative.h"
string Negative::get_name() const {
	return "negative";
}
void Negative::execute(vector<Image*>& images) {
	for (size_t i = 0; i < images.size(); ++i) {
		int max_pixel_value = images[i]->get_max_pixel_value();
		cout << "max: " << max_pixel_value;
		//quasi-same code repetition for all three, since we have no abstract pixel
		//maybe having the logic for negate, monochrome and grayscale in the pixels themselves would be a better structure?
		if (dynamic_cast<PBM_image*>(images[i])) {
			PBM_image* pbmimage = dynamic_cast<PBM_image*>(images[i]);
			vector<vector<PBM_pixel>> pixel_matrix = pbmimage->get_pixel_matrix();
			for (unsigned row = 0; row < pbmimage->get_dimensions().y; ++row) {
				vector<PBM_pixel> row_pixels = pixel_matrix[row];
				for (unsigned col = 0; col < pbmimage->get_dimensions().x; ++col) {
					row_pixels[col].value =
						max_pixel_value - row_pixels[col].value;
				}
				pixel_matrix[row] = row_pixels;
			}
			pbmimage->set_pixel_matrix(pixel_matrix);
		}
		else if (dynamic_cast<PGM_image*>(images[i])) { 
			PGM_image* pgmimage = dynamic_cast<PGM_image*>(images[i]);
			vector<vector<PGM_pixel>> pixel_matrix = pgmimage->get_pixel_matrix();
			for (unsigned row = 0; row < pgmimage->get_dimensions().y; ++row) {
				vector<PGM_pixel> row_pixels = pixel_matrix[row];
				for (unsigned col = 0; col < pgmimage->get_dimensions().x; ++col) {
					row_pixels[col].value =
						max_pixel_value - row_pixels[col].value;
				}
				pixel_matrix[row] = row_pixels;
			}
			pgmimage->set_pixel_matrix(pixel_matrix);
		}
		else if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			vector<vector<PPM_pixel>> pixel_matrix = ppmimage->get_pixel_matrix();
			for (unsigned row = 0; row < ppmimage->get_dimensions().y; ++row) {
				vector<PPM_pixel> row_pixels = pixel_matrix[row];
				for (unsigned col = 0; col < ppmimage->get_dimensions().x; ++col) {
					row_pixels[col].red = max_pixel_value - row_pixels[col].red;
					row_pixels[col].blue = max_pixel_value - row_pixels[col].blue;
					row_pixels[col].green = max_pixel_value - row_pixels[col].green;
				}
				pixel_matrix[row] = row_pixels;
			}
			ppmimage->set_pixel_matrix(pixel_matrix);
		}
	}
}