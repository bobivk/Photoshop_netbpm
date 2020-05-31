#include "Monochrome.h"
string Monochrome::get_name() const {
	return "monochrome";
}

void Monochrome::execute(vector<Image*>& images){
	for (size_t i = 0; i < images.size(); ++i) {
		int pixel_max_value = images[i]->get_max_pixel_value();
		if (dynamic_cast<PBM_image*>(images[i])) {
			cout << "image " << images[i]->get_file_name() << "is already monochrome.\n";
		}
		else if (dynamic_cast<PGM_image*>(images[i])) {
			PGM_image* pgmimage = dynamic_cast<PGM_image*>(images[i]);
			for (size_t row = 0; row < pgmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < pgmimage->dimensions.y; ++col) {
					if (pgmimage->pixel_matrix[row][col].value < pixel_max_value / 2) {
						//set either to maxvalue or 0
						pgmimage->pixel_matrix[row][col].value = 0;
					}
					else pgmimage->pixel_matrix[row][col].value = pixel_max_value;
				}
			}
		}
		else if (dynamic_cast<PPM_image*>(images[i])) {
			PPM_image* ppmimage = dynamic_cast<PPM_image*>(images[i]);
			for (size_t row = 0; row < ppmimage->dimensions.x; ++row) {
				for (size_t col = 0; col < ppmimage->dimensions.y; ++col) {
					if (ppmimage->pixel_matrix[row][col].red < pixel_max_value / 2) {
						ppmimage->pixel_matrix[row][col].red = 0;
					}
					else ppmimage->pixel_matrix[row][col].red = pixel_max_value;
					if (ppmimage->pixel_matrix[row][col].green < pixel_max_value / 2) {
						ppmimage->pixel_matrix[row][col].green = 0;
					}
					else ppmimage->pixel_matrix[row][col].green = pixel_max_value;
					if (ppmimage->pixel_matrix[row][col].blue < pixel_max_value / 2) {
						ppmimage->pixel_matrix[row][col].blue = 0;
					}
					else ppmimage->pixel_matrix[row][col].blue = pixel_max_value;
				}
			}
		}
	}
}